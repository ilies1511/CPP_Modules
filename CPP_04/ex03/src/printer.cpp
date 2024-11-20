#include "printer.hpp"
#include "Floor.hpp"

std::string coloring(const std::string& text, const std::string& color)
{
	return color + text + NC;
}

namespace printer
{
	void PrintMessage(const std::string& message, MessageType type)
	{
		std::string color;
		switch (type)
		{
			case MessageType::INFO:		color = PURPLE;	break;
			case MessageType::PROMPT:	color = BLUE;	break;
			case MessageType::ERROR:	color = RED;	break;
			case MessageType::HEADER:	color = ORANGE;	break;
			case MessageType::SUCCESS:	color = GREEN;	break;
		}
		std::cout << coloring(message, color) << "\n";
	}

	void Header(const std::string& Input)
	{
		std::cout << coloring(Input, ORANGE) << "\n";
	}

	void print_Interactive(const std::string& Input)
	{
		std::cout << coloring(Input, BLUE);
	}

	void print_invalidInput()
	{
		std::cout << coloring(
			"[INFO]: Invalid Command. USAGE: <cat> <dog> <wronganimal> <wrongcat> <clear> <exit>",
			RED
		) << "\n";
	}

	void print_floor(Floor* sharedFloor)
	{
		for (size_t i = 0; i < sharedFloor->getFloorSize(); i++)
		{
			std::cout	<< "Item[" << i << "]: "
						<< sharedFloor->getMateria(i)->getType()
						<< "\n";
		}
	}
}
