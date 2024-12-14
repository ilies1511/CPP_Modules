#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	printer::ocf_printer("Base", printer::OCF_TYPE::D);
}

