#include "../Includes/Log.hpp"

std::string coloring(const std::string& text, const std::string& color)
{
	return color + text + NC;
}

Log::Log(void) : _programm("DefaultProgram"){}

Log::Log(const std::string programm) : _programm(programm){}

Log::Log(const Log& og) : _programm(og._programm){}

Log& Log::operator=(const Log& og)
{
	return *this;
}

Log::~Log(void){}

void Log::logMessage(const std::string& level, const std::string& color,
			const char* file, const char* function, int line, const std::string& msg)
{
	std::cout << coloring("[" + level + "]: ", color)
			<< "Program: " << _programm
			<< ", File: " << file
			<< ", Function: " << function
			<< ", Line: " << line << "\n"
			<< "Message: " << msg << std::endl;
}

void Log::debug(const char* file, const char* function, int line, const std::string& msg)
{
	logMessage("DEBUG", CYAN, file, function, line, msg);
}

void Log::info(const char* file, const char* function, int line, const std::string& msg)
{
	logMessage("INFO", LIGHT_BLUE, file, function, line, msg);
}

void Log::warning(const char* file, const char* function, int line, const std::string& msg)
{
	logMessage("WARNING", YELLOW, file, function, line, msg);
}

void Log::error(const char* file, const char* function, int line, const std::string& msg)
{
	logMessage("ERROR", RED, file, function, line, msg);
}

void Log::complain( std::string level , const std::string msg, const char* file, const char* function, int line)
{
	size_t	len;
	//Array which holds pointers to functions (=Array of Functionpointers)
	void (Log::*funcs[])(const char*, const char*, int, const std::string&) = \
		{ &Log::error, &Log::warning, &Log::info, &Log::debug };

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
	int i = 0;
	for (; static_cast<unsigned long>(i) < len; i++)
	{
		if (!levels[i].compare(level))
			break ;
	}
	switch (i)
	{
		case 0:
			(this->*funcs[0])(file, function, line, msg);
			break ;
		case 1:
			(this->*funcs[1])(file, function, line, msg);
			break ;
		case 2:
			(this->*funcs[2])(file, function, line, msg);
			break ;
		case 3:
			(this->*funcs[3])(file, function, line, msg);
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
