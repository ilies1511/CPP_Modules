NAME := PmergeMe
.DEFAULT_GOAL := all
CPP := c++
AR := ar
RM := rm -rf

################################################################################
###############                  DIRECTORIES                      ##############
################################################################################

OBJ_DIR := _obj
# INC_DIRS := .
INC_DIRS := Includes Includes/Extra Includes/Tests
# SRC_DIRS := .
SRC_DIRS := src src/Extra src/Tests

# Tell the Makefile where headers and source files are
vpath %.hpp $(INC_DIRS)
vpath %.cpp $(SRC_DIRS)

################################################################################
###############                  SOURCE FILES                     ##############
################################################################################

EXTRA_FILES := Log.cpp printer.cpp
EXTRA := $(addprefix Extra/, $(EXTRA_FILES))

TEST_FILES := test.cpp
TEST := $(addprefix Tests/, $(TEST_FILES))

SRC :=	main.cpp VectorPmergeMe.cpp DequePmergeMe.cpp \
		algo_deque.cpp algo_vector.cpp
SRCS := $(addprefix src/, $(SRC) $(EXTRA) $(TEST))

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))

################################################################################
########                         COMPILING                      ################
################################################################################

# CFLAGS := -Wall -Wextra -Werror -g -MMD -MP -I$(INC_DIRS)
CFLAGS := -Wall -Werror -Wextra -Wpedantic -Wshadow -Wno-shadow -std=c++17 -Wconversion -Wsign-conversion -g -MMD -MP $(addprefix -I, $(INC_DIRS))
CFLAGS_SAN := $(CFLAGS) -fsanitize=address
LDFLAGS := -lncurses
LDFLAGS_SAN := -lncurses -fsanitize=address
ARFLAGS := -rcs

# ANSI color codes
GREEN := \033[0;32m
MAGENTA := \033[0;35m
BOLD := \033[1m
NC := \033[0m # Reset

all: $(NAME)

$(NAME): $(OBJS)
#$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(CPP) $(LDFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)Successful Compilation$(NC)"

# Rule to compile .o files
$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	mkdir -p $(@D)
	$(CPP) $(CFLAGS) -c $< -o $@

# Ensure the directories exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	@echo "$(MAGENTA)$(BOLD)Executable + Object Files cleaned$(NC)"

re: fclean submodule_update all

submodule_update:
	git submodule update --remote --merge

bonus: all

san: fclean
	make CFLAGS="$(CFLAGS_SAN)" LDFLAGS="$(LDFLAGS_SAN)"
	@echo "$(GREEN)$(BOLD)Successful Compilation with fsan$(NC)"

re_sub: submodule_rebuild

submodule_rebuild:
	git submodule deinit -f .
	git submodule update --init --recursive

debug: clean
debug: CFLAGS += -DDEBUG
debug: $(NAME)

test: $(NAME)
	@echo "Running test with randomly generated input..."
	@ARGS=`jot -r 3000 1 1000 | tr '\n' ' '`; \
	echo "./$(NAME) $$ARGS"; \
	./$(NAME) $$ARGS

test_cases: $(NAME)
	@echo "Running specific test cases..."
	@echo "Test Case 1: Alternating High and Low"
	@./$(NAME) 1 1000 2 999 3 998 4 997 5 996 6 995 7 994 8 993 9 992 10 991
	@echo "Test Case 2: Highly Repeated Numbers"
	@./$(NAME) 5 5 5 10 10 10 15 15 15 20 20 20 25 25 25 30 30 30
	@echo "Test Case 3: Sparse Numbers"
	@./$(NAME) 1 10000 2 9999 3 9998 4 9997 5 9996 6 9995 7 9994 8 9993 9 9992
	@echo "Test Case 4: Nearly Sorted with Single Swaps"
	@./$(NAME) 1 2 3 4 5 7 6 8 9 10 12 11 14 13 16 15 18 17 20 19
	@echo "Test Case 5: Random Large Numbers"
	@./$(NAME) 12345 987 65432 321 45678 789 23456 987 34567 123 56789 321 67890 456
	@echo "Test Case 6: All Identical Except One"
	@./$(NAME) 100 100 100 100 100 100 100 100 100 100 101
	@echo "Test Case 7: Zig-Zag Pattern"
	@./$(NAME) 1 100 2 99 3 98 4 97 5 96 6 95 7 94 8 93 9 92 10
	@echo "Test Case 8: Reverse Alternating"
	@./$(NAME) 10 1 9 2 8 3 7 4 6 5 15 6 14 7 13 8 12 9 11 10
	@echo "Test Case 9: Mixed Patterns"
	@./$(NAME) 5 1 9 2 8 4 7 3 6 0 10 20 30 40 50 15 25 35 45

-include $(OBJS:%.o=%.d)

.PHONY: all clean fclean re bonus re_sub submodule_rebuild san debug test test_cases
