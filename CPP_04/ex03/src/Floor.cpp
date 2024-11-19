#include "Floor.hpp"

Floor::Floor() : _floor(nullptr), _floorSize(0), _floorCapacity(0)
{
	std::cout << "[FLOOR]: Default Construcor called\n";
}

Floor::Floor(const Floor &og)
	: _floor(nullptr), _floorSize(og._floorSize), _floorCapacity(og._floorCapacity)
{
	std::cout << "[FLOOR]: Copy Construcor called\n";
	if (this->_floorCapacity > 0)
	{
		this->_floor = new AMateria*[_floorCapacity];
		for (size_t i = 0; i < _floorSize; i++)
			this->_floor[i] = og._floor[i];
	}
}

Floor &Floor::operator=(const Floor &og)
{
	std::cout << "[FLOOR]: Copy Assigment Construcor called\n";
	if (this != &og)
	{
		delete[] _floor;
		_floorSize = og._floorSize;
		_floorCapacity = og._floorCapacity;
		if (_floorCapacity > 0)
		{
			this->_floor = new AMateria*[_floorCapacity];
			for (size_t i = 0; i < _floorSize; i++)
			this->_floor[i] = og._floor[i];
		}
		else
			_floor = nullptr;
	}
	return (*this);
}

Floor::~Floor()
{
	std::cout << "[FLOOR]: Destrucor called\n";
	delete[] _floor;
}

//Floor
void Floor::resizeFloor(size_t newCapacity)
{
	// Speicher für neues Floor-Array reservieren
	AMateria** newFloor = new AMateria*[newCapacity];
	// Alte Daten kopieren
	for (size_t i = 0; i < _floorSize; ++i)
		newFloor[i] = _floor[i];
	// Alten Speicher freigeben
	delete[] _floor;
	// Neues Array verwenden
	this->_floor = newFloor;
	this->_floorCapacity = newCapacity;
}

void	Floor::adMateria(AMateria *newM)
{
	if (!newM)
		return ;
	if (this->_floorSize == this->_floorCapacity)
	{
		size_t newCapacity = (_floorCapacity == 0) ? 1 : (_floorCapacity * 2);
		resizeFloor(newCapacity);
	}
	_floor[_floorSize++] = newM;
}


//Getters
size_t	Floor::getFloorSize(void) const
{
	return (this->_floorSize);
}

size_t	Floor::getFloorCapacity(void) const
{
	return (this->_floorCapacity);
}

AMateria *Floor::getMateria(size_t index) const
{
	if (index < this->_floorSize)
		return (this->_floor[index]);
	return (nullptr);
}


