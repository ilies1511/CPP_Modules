/*
	In this function, we use **pointers to member functions** to select and call a specific logging function (like `debug`, `info`, etc.)
	based on the given log level. Using function pointers here allows us to avoid multiple `if/else` statements and makes the code
	cleaner and more modular.

	### What Are Function Pointers?
	In C++, a **function pointer** is a variable that stores the address of a function, allowing us to call the function indirectly.
	Function pointers are especially useful when we want to dynamically choose which function to call based on runtime conditions.

	### Syntax for Function Pointers in a Class
	In a class, function pointers are slightly more complex because they refer to member functions. To declare a pointer to a member
	function, the syntax is:

		void (ClassName::*pointerToFunction)();

	Here, `ClassName` is the name of the class, and `pointerToFunction` is a pointer to a function that takes no parameters and
	returns `void`.

	### Using Member Function Pointers in Harl
	In the `Harl` class, we create an array of pointers to member functions (`debug`, `info`, `warning`, and `error`).
	Each function in this array corresponds to a specific log level.

	**Declaration and Initialization**:

		void (Harl::*funcs[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	- `void (Harl::*)()` represents a pointer to a `Harl` member function that returns `void` and takes no parameters.
	- `funcs[]` is an array holding these function pointers, allowing us to call each member function indirectly.

	### Calling a Member Function through a Pointer
	To call a function using a member function pointer, the syntax is:

		(this->*pointerToFunction)();

	- `this->*` is used to access the member function of the current object (`this`).
	- `pointerToFunction` is dereferenced and then called.

	### Explanation of the `complain` Function

	1. **Define Log Levels and Function Pointers**:
		We define an array of strings `levels` representing each log level and an array `funcs` of function pointers that correspond
		to these levels.

	2. **Search for the Matching Level**:
		We loop through the `levels` array to find the one that matches `level`. When we find a match, we call the associated function
		from `funcs` at the same index.

		Example:
			- `level = "DEBUG"` matches `levels[0]`, so we call `funcs[0]`, which is `&Harl::debug`.
			- `(this->*funcs[0])();` calls `debug()` on the current `Harl` instance.

	3. **Invalid Level Handling**:
		If `level` doesn’t match any string in `levels`, we output an error message indicating an invalid level.

	### Summary of Execution
	Here’s what happens when you call `harl.complain("WARNING")`:

	- The `levels` array is checked in the loop:
		- `"DEBUG"` does not match `"WARNING"`.
		- `"INFO"` does not match `"WARNING"`.
		- `"WARNING"` matches `"WARNING"` at index `2`.
	- `funcs[2]` is `&Harl::warning`, so `(this->*funcs[2])();` calls `Harl::warning()`, printing:

		"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."

	This approach offers an efficient and scalable way to select and call functions in C++ using member function pointers.
*/
