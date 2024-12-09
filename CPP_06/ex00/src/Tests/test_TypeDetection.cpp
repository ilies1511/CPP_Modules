#include "test_TypeDetection.hpp"

namespace testTypeDetection
{
	void checkWhat(const std::string& Type, const std::string& testInput, bool (*checkFunction)(const std::string&))
	{
		std::cout << testInput << ": ";
		if (checkFunction(testInput))
			std::cout << "is " << Type << "\n";
		else
			std::cout << "not " << Type << "\n";
	}

	// isPseudoLiteral: "nan", "+inf", "-inff", ungültige Fälle : "123", "inf"
	void	checkPseudoLiteral(void)
	{
		printer::Header("\nTEST PseudoLiteral");
		checkWhat("PseudoLiteral", "inf" ,isPseudoLiteral);
		checkWhat("PseudoLiteral", "nan" ,isPseudoLiteral);
		checkWhat("PseudoLiteral", "+infa" ,isPseudoLiteral);
		checkWhat("PseudoLiteral", "-inf" ,isPseudoLiteral);
		checkWhat("PseudoLiteral", "-inff" ,isPseudoLiteral);
		checkWhat("PseudoLiteral", "132" ,isPseudoLiteral);
	}

	void	checkDouble(void)
	{
		printer::Header("\nTEST DOUBLE");
		checkWhat("double", "a" ,isDouble);
		checkWhat("double", "aa" ,isDouble);
		checkWhat("double", "9" ,isDouble);
		checkWhat("double", "~" ,isDouble);
		checkWhat("double", "1" ,isDouble);
		checkWhat("double", "1.0f" ,isDouble);
		checkWhat("double", "42.000" ,isDouble);
		checkWhat("double", "-123" ,isDouble);
		checkWhat("double", "" ,isDouble);
	}

	void	checkFloat(void)
	{
		printer::Header("\nTEST FLOAT");
		checkWhat("float", "a" ,isFloat);
		checkWhat("float", "aa" ,isFloat);
		checkWhat("float", "\n" ,isFloat);
		checkWhat("float", "9" ,isFloat);
		checkWhat("float", "~" ,isFloat);
		checkWhat("float", "1" ,isFloat);
		checkWhat("float", "1.0f" ,isFloat);
		checkWhat("float", "42" ,isFloat);
		checkWhat("float", "-123" ,isFloat);
		checkWhat("float", "" ,isFloat);
	}

	// isInt: "42", "-123", "0", ungültige Fälle: "42.0", "42f".
	void	checkInt(void)
	{
		printer::Header("\nTEST INT");
		checkWhat("int", "a" ,isInt);
		checkWhat("int", "aa" ,isInt);
		checkWhat("int", "9" ,isInt);
		checkWhat("int", "~" ,isInt);
		checkWhat("int", "1" ,isInt);
	}

	// isChar: 'a', '~', ' ', ungültige Fälle: "ab", "9".
	void	checkChar(void)
	{
		printer::Header("\nTEST CHAR");
		checkWhat("char", "a" ,isChar);
		checkWhat("char", "aa" ,isChar);
		checkWhat("char", "47" ,isChar);
		checkWhat("char", "~" ,isChar);
	}

	void	checkMo(void)
	{
		printer::Header("\nTEST MO");
		checkWhat("char", "a" ,isChar);
	}
}
