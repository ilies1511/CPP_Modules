#include <iostream>
#include <string>
#include <iomanip>

void	print_values(std::string brain, std::string *stringPTR, std::string &stringREF)
{
	const int label_width = 40;

	std::cout << std::setw(label_width) << "value held by 'brain': " << brain << '\n';
	std::cout << std::setw(label_width) << "value pointed to by 'stringPTR': " << *stringPTR << '\n';
	std::cout << std::setw(label_width) << "value pointed to by 'stringREF': " << stringREF << '\n';
	return ;
}

void	print_memory_address(std::string *brain, std::string *stringPTR, std::string &stringREF)
{
	const int label_width = 40;

	std::cout << std::left;
	// memory adress of string;
	std::cout << std::setw(label_width) << "memory adress of string: " << brain << "\n";
	// memory adress held by 'stringPTR';
	std::cout << std::setw(label_width) << "memory adress held by stringPTR: " << stringPTR << "\n";
	// memory adress held by 'stringREF';
	std::cout << std::setw(label_width) << "memory adress held by stringREF: " << &stringREF << "\n";
}

int	main(void)
{
	std::string brain; //String 'brain'
	std::string *stringPTR = &brain; //Pointer to brain
	std::string &stringREF = brain; //Reference to 'brain'

	brain = "HI THIS IS BRAIN";
	print_memory_address(&brain, stringPTR, stringREF);
	print_values(brain, stringPTR, stringREF);
	return (0);
}
