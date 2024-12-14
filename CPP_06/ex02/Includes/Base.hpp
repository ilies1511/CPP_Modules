#pragma once

//Includes
#include "iostream"
#include "string"
#include <cstdlib>
#include <ctime>
//Mine
#include "printer.hpp"
#include "Log.hpp"
// #include "A.hpp"
// #include "B.hpp"
// #include "C.hpp"
//Class

// class A;
// class B;
// class C;

class Base
{
	// No OCF needed
	public:
	virtual ~Base();
	//Memebers
};

Base * generate(void);
void identifyBy_ptr(Base* p);
void identifyBy_ref(Base& p);

