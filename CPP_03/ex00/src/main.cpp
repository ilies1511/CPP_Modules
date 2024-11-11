#include "ClapTrap.hpp"

void	test3(ClapTrap &Blayer1, ClapTrap &Blayer2, ClapTrap &Blayer3)
{

}

void	test2(ClapTrap &Blayer1, ClapTrap &Blayer2, ClapTrap &Blayer3)
{
	(void)Blayer3;
	std::cout << coloring("\nTEST2\n", RED);
	Blayer2.beRepaired(30);
	while (1)
	{
		if (Blayer2.getHitPoint() <= 0 || Blayer1.getEnergyPoint() <= 0)
			break ;
		Blayer1.attack(Blayer2.getName());
		Blayer2.takeDamage(static_cast<unsigned int>(Blayer1.getAttackDamage()));
		Blayer1.setAttackDamage(Blayer1.getAttackDamage() + 1);
	}
}

void	test1(ClapTrap &Blayer1, ClapTrap &Blayer2, ClapTrap &Blayer3)
{
	(void)Blayer3;
	std::cout << coloring("\nTEST1\n", RED);
	Blayer1.setAttackDamage(6);
	Blayer2.setAttackDamage(6);
	std::cout << "Hit Point PRE " << Blayer2.getHitPoint() << "\n";
	Blayer1.attack(Blayer2.getName());
	Blayer2.takeDamage(static_cast<unsigned int>(Blayer2.getAttackDamage()));
	Blayer2.beRepaired(5);
	std::cout << "Hit Point POST " << Blayer2.getHitPoint() << "\n";
}

int	main()
{
	ClapTrap	Blayer1("Zizou");
	ClapTrap	Blayer2("Beter");
	ClapTrap	Blayer3;

	test1(Blayer1, Blayer2, Blayer3);
	test2(Blayer1, Blayer2, Blayer3);
	test3();
	return (0);
}
