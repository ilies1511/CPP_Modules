#include "easyfind.hpp"

const char *NotFoundException::what() const throw()
{
	return ("Element not found ALOOO !");
}
