/*
 * Inheritance in C++ - Summary and Explanation
 *
 * Inheritance is a fundamental concept in Object-Oriented Programming (OOP).
 * It allows one class (the derived class) to inherit properties and behaviors
 * (methods) from another class (the base class). In C++, the derived class can
 * access and modify the attributes and methods of the base class, facilitating
 * code reuse and extension of functionality.
 *
 * In this program, we have two classes: ClapTrap (the base class) and ScavTrap
 * (the derived class). ScavTrap inherits from ClapTrap, meaning it gets access
 * to ClapTrap's public and protected members.
 *
 * The relationship between ClapTrap and ScavTrap is modeled as follows:
 * - ClapTrap defines common properties and methods for a robot (e.g., name, hit
 *   points, energy points, and attack damage).
 * - ScavTrap extends ClapTrap by providing specialized behavior, such as a custom
 *   attack message and an additional method `guardGate()`.
 *
 * Key concepts explained:
 *
 * 1. **Constructors**:
 *    - In C++, constructors are special member functions that are used to
 *      initialize objects of a class. The constructors in both ClapTrap and
 *      ScavTrap initialize object attributes.
 *    - **Default Constructor**: A constructor with no parameters, used to create
 *      an object with default values.
 *    - **Parameterized Constructor**: A constructor that accepts arguments to
 *      initialize the object with specific values.
 *    - **Copy Constructor**: A constructor that creates a new object as a copy
 *      of an existing object.
 *    - **Constructor Chaining**: When constructing a derived class object (like
 *      ScavTrap), the constructor of the base class (ClapTrap) is called first,
 *      followed by the derived class constructor. This is achieved through
 *      constructor delegation (e.g., `ClapTrap()`).
 *
 * 2. **Destructors**:
 *    - A destructor is a special function that is called when an object is
 *      destroyed, and it is used to release resources or perform cleanup. In
 *      the case of ScavTrap, the destructor calls the destructor of ClapTrap
 *      implicitly.
 *
 * 3. **Method Overriding**:
 *    - In C++, a derived class can override a method from the base class by
 *      providing its own implementation. This is done by defining a method with
 *      the same signature in the derived class.
 *    - The `override` keyword explicitly tells the compiler that we intend to
 *      override a base class method. It helps catch errors if the base class
 *      method's signature changes.
 *    - **`virtual` keyword in base class**: Methods that may be overridden in
 *      derived classes should be declared with `virtual` in the base class.
 *      This allows polymorphic behavior, meaning the appropriate method (base
 *      or derived) is called at runtime based on the actual object type, not
 *      the type of the pointer/reference.
 *    - **`override` keyword in derived class**: This ensures that the method
 *      we’re defining in the derived class indeed overrides a virtual method
 *      in the base class. If the base class method’s signature is incorrect
 *      or missing, the compiler will report an error.
 *
 * 4. **Setters**:
 *    - Setters are methods used to assign values to private member variables of
 *      a class. We created setters for attributes such as hit points, energy
 *      points, and attack damage to ensure that the values are properly controlled
 *      and validated if needed.
 *    - Using setters is a better practice than directly accessing private
 *      members, as it encapsulates the logic of assigning values.
 *
 * 5. **The `explicit` Keyword**:
 *    - The `explicit` keyword is used in C++ to mark constructors that can
 *      prevent implicit conversions or copy-initialization.
 *    - For example, by declaring `explicit ScavTrap(std::string InputName)` in
 *      the ScavTrap class, we prevent the compiler from automatically converting
 *      a string into a `ScavTrap` object. This helps avoid unexpected behavior
 *      in the code.
 *
 * 6. **Polymorphism**:
 *    - Polymorphism allows objects of different classes to be treated as objects
 *      of a common base class. This is achieved through method overriding and
 *      virtual functions. For example, `attack()` is a virtual function in
 *      ClapTrap, and ScavTrap overrides this function to provide its own
 *      implementation.
 *
 * 7. **Constructor and Destructor Chaining**:
 *    - When a `ScavTrap` object is created, the constructor of ClapTrap is called
 *      first (because ScavTrap is derived from ClapTrap), followed by the
 *      constructor of ScavTrap. This ensures that the base class is properly
 *      initialized before the derived class.
 *    - Similarly, destructors are called in reverse order: the derived class
 *      destructor is called first, followed by the base class destructor.
 *
 * Example of polymorphic behavior:
 * - When calling `attack()` on a base class pointer that points to a derived
 *   class object, the derived class version of the method is executed, not the
 *   base class version. This is because the `attack()` method in ClapTrap is
 *   marked as `virtual`, and in ScavTrap it's overridden.
 *
 * Example of virtual method use:
 * - `void attack(const std::string& target) override;` in ScavTrap is overriding
 *   the base class method, and it's necessary to mark it with the `override`
 *   keyword to ensure that it properly overrides the virtual method in ClapTrap.
 *
 * Notes:
 * - Always use `virtual` in the base class if you intend to override a method
 *   in derived classes.
 * - Always use `override` in the derived class to indicate that you're
 *   intentionally overriding a base class method.
 * - Constructor chaining is important for properly initializing the base class
 *   before the derived class, ensuring a well-formed object.
 */

#include "FragTrap.hpp"

// Function to test ScavTrap with default constructor
void testScavTrapDefaultConstructor()
{
	FragTrap fragTrap1;

	std::cout << coloring("\nTesting FragTrap (default constructor):\n", RED);
	fragTrap1.attack("Enemy2");
	fragTrap1.highFivesGuys();
}

// Function to test FragTrap with named constructor
void testScavTrapNamedConstructor()
{
	FragTrap fragTrap2("Frager");

	std::cout << coloring("\nTesting FragTrap (named constructor):\n", RED);
	fragTrap2.attack("Enemy3");
	fragTrap2.highFivesGuys();
}

// Function to test FragTrap with copy constructor
void testFragTrapCopyConstructor()
{
	FragTrap fragTrap2("Frager");

	FragTrap scavTrap3(fragTrap2);
	std::cout << coloring("\nTesting FragTrap (copy constructor):\n", RED);
	scavTrap3.attack("Enemy4");
	scavTrap3.highFivesGuys();
}

// Function to test FragTrap with assignment operator
void testScavTrapAssignmentOperator()
{
	FragTrap fragTrap2("Frager");
	FragTrap scavTrap4;
	scavTrap4 = fragTrap2;
	std::cout << coloring("\nTesting FragTrap (assignment operator):\n", RED);
	scavTrap4.attack("Enemy5");
	scavTrap4.highFivesGuys();
}

int main()
{
	testScavTrapDefaultConstructor();
	testScavTrapNamedConstructor();
	testFragTrapCopyConstructor();
	testScavTrapAssignmentOperator();
	return (0);
}
