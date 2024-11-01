#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << coloring("DEBUG: love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n", PURPLE);
}

void Harl::info( void )
{
	std::cout << coloring("INFO: cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n", BLUE);
}

void Harl::warning( void )
{
	std::cout << coloring("WARNING: think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n", ORANGE);
}

void Harl::error( void )
{
	std::cout << coloring("ERROR: This is unacceptable! I want to speak to the manager now.\n", RED);
}

void Harl::complain( std::string level )
{
	size_t	len;
	//Array which holds pointers to functions (=Array of Functionpointers)
	void (Harl::*funcs[]) (void) = { &Harl::error, &Harl::warning, &Harl::info, &Harl::debug};

	/*
		Strings, that serve to call the right function dependend on the
		'level'string and then calling it with the right index.
		Order must be the same, since the index will be used to derefence fnc.
		at that index
	*/
	std::string levels[] {"ERROR", "WARNING", "INFO", "DEBUG"};

	/*
		Loop through the 'levels' array and compare string with
		input string 'level'
		If same, then functionspointer in the functionspointer-array at that
		index will be dereferenced and the fnc. will be called.
		'this'
	*/
	len = sizeof(levels) / sizeof(levels[0]);
	for (int i = 0; static_cast<unsigned long>(i) < len; i++)
	{
		if (!levels[i].compare(level))
		{
			(this->*funcs[i])();
			return ;
		}
	}
	// If level is not recognized
	std::cout << "Invalid complaint level: " << level << std::endl;
}
