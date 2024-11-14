/*
	The "Diamond Problem" arises due to multiple inheritance in C++,
	where a class inherits from two classes that have a common base class.
	In this case, DiamondTrap inherits from both ScavTrap and FragTrap,
	which both inherit from ClapTrap, leading to ambiguity in the inheritance
	of attributes like _hit_points, _energy_points, and _attack_damage.
	The solution is to avoid direct attribute assignments in DiamondTrap's
	copy constructor. Instead, we rely on the constructors of the base classes
	(ScavTrap and FragTrap) to correctly initialize the inherited attributes.
	This ensures that each class in the inheritance chain initializes its part
	of the object in a consistent and non-conflicting manner.
	By calling the base class constructors explicitly, we prevent the Diamond
	Problem from causing issues like duplicated attributes or incorrect values
	in DiamondTrap. This approach makes the class easier to maintain and avoids
	potential bugs in cases of deep inheritance chains.
*/

#include "DiamondTrap.hpp"

void	Blayer()
{
	DiamondTrap Blayer1("Perpetrator");
	DiamondTrap Blayer2("Victim");

	std::cout << coloring("\nBlayerCheck\n", BLUE);
	Blayer1.setEnergyPoint(99999);
	Blayer1.setAttackDamage(1);
	Blayer2.setHitPoint(5);
	std::cout << RED << "[PRE Blayer1]: Perpetrator Energy: "<< Blayer1.getEnergyPoint() << NC << "\n";
	std::cout << RED << "[PRE Blayer1]: Attack Damage: "<< Blayer1.getAttackDamage() << NC << "\n";
	std::cout << RED << "[PRE Blayer2]: HitPoints: "<< Blayer2.getHitPoint() << NC << "\n";
	// std::cout << RED << "[PRE]: Victim HitPoints: "<< Blayer2.getHitPoint() << NC << "\n";
	while (1)
	{
		if (Blayer2.getHitPoint() <= 0 || Blayer1.getEnergyPoint() <= 0)
			break ;
		Blayer1.attack(Blayer2.getName());
		Blayer2.takeDamage(static_cast<unsigned int>(Blayer1.getAttackDamage()));
		std::cout << RED << "[WHILE]: HitPoints: "<< Blayer2.getHitPoint() << NC << "\n";
	}
	std::cout << RED << "[POST]: Victim HitPoints: "<< Blayer2.getHitPoint() << NC << "\n";
}
void	complexCheck()
{
	std::cout << coloring("\nComplex Test\n", BLUE);
	DiamondTrap	dt("Ilies");
	dt.setAttackDamage(99);
	dt.setHitPoint(1511);
	dt.setEnergyPoint(1);

	DiamondTrap cpy = dt;
	std::cout << RED << "Energy Point Cpy: "<< cpy.getEnergyPoint() << NC << "\n";
	std::cout << RED << "Hit Point Cpy: "<< cpy.getHitPoint() << NC << "\n";
	std::cout << RED << "Attack Damage Cpy: "<< cpy.getAttackDamage() << NC << "\n";
	std::cout << RED << "ATTACK!!" << NC << "\n";
	cpy.attack(dt.getName());

	std::cout << RED << "PRE REPAIR - Hit Point Cpy: "<< cpy.getHitPoint() << NC << "\n";
	cpy.setEnergyPoint(1);
	cpy.beRepaired(100);
	std::cout << RED << "POST REPAIR - Hit Point Cpy: "<< cpy.getHitPoint() << NC << "\n";
}

void	nameConstructorCheck()
{
	DiamondTrap	dt("Täter");

	dt.attack("Opfer");
}

void	attackCheck()
{
	std::cout << coloring("\nTEST2: check if attack is like in ScavTrap\n", BLUE);
	DiamondTrap	dt;
	dt.attack("Gwyneth");
}

void	valueCheck()
{
	std::cout << coloring("\nTEST 1: check if value of attributes correct\n", BLUE);
	DiamondTrap	diamondTrap;

	std::cout << "Hitpoints: " << diamondTrap.getHitPoint() << "\n";
	std::cout << "Energy Point: " << diamondTrap.getEnergyPoint() << "\n";
	std::cout << "Attack Point: " << diamondTrap.getAttackDamage() << "\n";
}

int	main()
{
	valueCheck();
	attackCheck();
	nameConstructorCheck();
	complexCheck();
	Blayer();
	return (0);
}
