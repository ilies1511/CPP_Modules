#include <iostream>
#include <string>

int	main(void)
{
	std::cout << "alo\n";
	char str[] = "test";
	for (int i = 0; i < 10000; i++) {
		std::cout << str[i];
	}
	return (0);
}
