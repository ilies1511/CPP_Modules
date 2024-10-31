#include "log.hpp"

/*
	Methode-Definition of Log
*/
void Log::mf_set_level(Status level)
{
	m_loglevel = level;
}

void Log::mf_success(const std::string &msg)
{
	if (m_loglevel == SUCCESS)
		// std::cout << "[ERROR]: " << msg << '\n';
		std::cout << coloring("[SUCCESS]: " + msg, GREEN) << '\n';
}

void Log::mf_error(const std::string &msg)
{
	if (m_loglevel == ERROR)
		// std::cout << "[ERROR]: " << msg << '\n';
		std::cout << coloring("[ERROR]: " + msg, RED) << '\n';
}

void Log::mf_info(const std::string &msg)
{
	if (m_loglevel == INFO)
		std::cout << coloring("[INFO]: " + msg, BLUE) << '\n';
}

void	print_log(Status status, const std::string &str)
{
	Log	log;
	log.mf_set_level(status);
	if (status == ERROR)
		log.mf_error(str);
	else if (status == INFO)
		log.mf_info(str);
	else if (status == SUCCESS)
		log.mf_success(str);

}
