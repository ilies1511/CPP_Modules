#include "HumanA.hpp"

// void	setWeaponTyp(const std:string& weaponType)
// {
// 	weaponA->setType(weaponType);
// 	return ;
// }


/*
	In C++, object initialization can be managed through a constructor's initializer list,
	which is introduced by a colon (':') following the constructor's parameter list.
	The initializer list provides a way to directly initialize member variables before
	the constructor body (enclosed by '{ }') is executed.

	Key points:
	- Constant members (const) and references (&) require initialization in the initializer list,
	as they cannot be reassigned within the constructor body.
	- The initializer list can improve efficiency for complex types, like std::string, by
	 avoiding unnecessary default construction and reassignment.
	- The syntax 'member(value)' in the initializer list initializes 'member' with 'value'
	 directly, making the code more efficient and readable.

	Example:
	In the line `HumanA::HumanA(std::string Name, Weapon &obj) : name(Name), weaponRE(obj) {}`,
	the member 'name' is initialized with 'Name' and 'weaponRE' (a reference) is initialized
	with 'obj' using the initializer list.
*/
HumanA::HumanA(std::string Name, Weapon &obj) : name(Name), weaponRE(obj){}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weaponRE.getType() << '\n';
}
