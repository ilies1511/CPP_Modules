#pragma once

//Imclude
#include <iostream>
#include <string>
#include "Extra/printer.hpp"
#include "TypeDetection.hpp"

namespace testTypeDetection
{
	void	checkWhat(const std::string& Type, const std::string& testInput, bool (*checkFunction)(const std::string&));
	void	checkPseudoLiteral(void);
	void	checkDouble(void);
	void	checkFloat(void);
	void	checkInt(void);
	void	checkChar(void);
	void	checkMo(void);
}



