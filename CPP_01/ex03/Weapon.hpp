#ifndef WEAPON_HPP
# define WEAPON_HPP

//Includes
#include <iostream>
#include <string>

class Weapon
{
	private:
		std::string type;
	public:
		//getter -> retuns const ref
		const std::string& getType();
		//setter
		void setType(const std::string& new_type);
};

#endif
