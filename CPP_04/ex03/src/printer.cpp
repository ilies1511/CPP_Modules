#include "printer.hpp"
#include "Floor.hpp"

std::string coloring(const std::string& text, const std::string& color)
{
	return color + text + NC;
}

namespace printer
{
	void	ocf_printer(const std::string& class_name, OCF_TYPE type)
	{
		std::string str;
		switch (type)
		{
			case OCF_TYPE::DC:	str = "[" + class_name + "]: " + "Default Constructor called";
			case OCF_TYPE::DNC:	str = "[" + class_name + "]: " + "Default Name Constructor called";
			case OCF_TYPE::CC:	str = "[" + class_name + "]: " + "Copy Constructor called";
			case OCF_TYPE::CAC:	str = "[" + class_name + "]: " + "Copy Assignment Constructor called";
			case OCF_TYPE::D:	str = "[" + class_name + "]: " + "Destructor called";
		}
		std::cout << coloring(str, BROWN) << "\n";
	}

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
			case MessageType::OCF:		color = BROWN;	break;
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
