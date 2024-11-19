#include "Character.hpp"
// #include "../Includes/Character.hpp"

// // Statische Member initialisierens
// AMateria** Character::_floor = nullptr;
// size_t Character::_floorSize = 0;
// size_t Character::_floorCapacity = 0;

//OCF
Character::Character(void) : _characterName("DefaultCharacter")
{
	for (size_t i = 0; i < 4; ++i) inventory[i] = nullptr;
	std::cout << "[CHARACTER]: Default Construcor called\n";
}

Character::Character(std::string InputName) : _characterName(InputName)
{
	for (size_t i = 0; i < 4; ++i) inventory[i] = nullptr;
	std::cout << "[CHARACTER]: Default Name Construcor called\n";
}

Character::Character(const Character &og)
{
	std::cout << "[CHARACTER]: Copy Construcor called\n";
}

Character &Character::operator=(const Character &og)
{
	std::cout << "[CHARACTER]: Copy Assignment Construcor called\n";
}

Character::~Character()
{
	std::cout << "[CHARACTER]: Destrucor called\n";
}

//Methodes
std::string const & Character::getName()
{
	return (this->_characterName);
}

void Character::equip(AMateria* m)
{
	;
}

void Character::unequip(int idx)
{
	;
}

void Character::use(int idx, ICharacter& target)
{
	;
}

//Floor
void Character::resizeFloor(size_t newCapacity)
{
	// Speicher für neues Floor-Array reservieren
	AMateria** newFloor = new AMateria*[newCapacity];
	// Alte Daten kopieren
	for (size_t i = 0; i < _floorSize; ++i)
		newFloor[i] = _floor[i];
	// Alten Speicher freigeben
	delete[] _floor;
	// Neues Array verwenden
	_floor = newFloor;
	_floorCapacity = newCapacity;
}
