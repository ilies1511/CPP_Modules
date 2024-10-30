#ifndef WEAPON_HPP
# define WEAPON_HPP

//Includes
#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string type;
	public: // Memeber functions
		//getter -> retuns const ref
		const std::string& getType();
		//setter
		void setType(const std::string& new_type);
	public: //(De)Constructor
		Weapon(std::string Weapon);
		Weapon(void){}; //Default Constructor: needed in case of creating an object without any arguments
		~Weapon(){};
};

#endif
