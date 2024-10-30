#include "HumanA.hpp"
#include "HumanB.hpp"
/*
	In object-oriented programming, aggregation and composition are two ways to define relationships between classes.

	- **Aggregation**:
	- A "has-a" relationship where one class (the container) holds a reference to another class (the contained).
		- The contained object can exist independently of the container.
		- Example: In the given code, `HumanA` aggregates a `Weapon` object. The `Weapon` is created independently and passed to `HumanA`, allowing it to function without owning the `Weapon`'s lifetime.

	- **Composition**:
		- A stronger "has-a" relationship where the container class owns the contained object.
		- The contained object's lifecycle is tied to that of the container. When the container is destroyed, so is the contained object.
		- Example: If `HumanA` were to create and manage its own `Weapon` object, it would be a composition relationship, as the `Weapon` would not exist outside the `HumanA` instance.

	Understanding these distinctions helps in designing classes and managing object lifecycles effectively.
*/
int	main(void)
{
	{
		Weapon club = Weapon("crude spiked club"); // same as 'club.setType("crude spiked club")' but more efficient. Most efficient: Weapon club("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}

/*
The difference between the two initialization methods for a Weapon object is as follows:

1. `Weapon club = Weapon("crude spiked club");`
	- This approach creates a temporary Weapon object using the constructor,
		which is then copied to the variable `club`.
	- It may involve additional overhead due to the copy operation and is
		generally less efficient.

2. `Weapon club("crude spiked club");`
	- This method directly initializes the `club` object with the specified
		type using the constructor.
	- It avoids the overhead of creating a temporary object and is more
		efficient and clearer.

In modern C++ practices, the second method (direct initialization) is
	preferred for its clarity and performance benefits.
*/
