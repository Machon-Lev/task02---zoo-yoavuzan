#include "Animal.h"
 Animal::Animal(const string n, const Loction l)
{
	name = n;
	loction = l;
}

 void Animal::printDetails() const
{
	cout << "Name: " << name << " Type: " << typeOfAnimal << " Loction: " << loction << " can move: ";
	if (!stopMove)
		cout << "yes\n";
	else
		cout << "No\n";
}

 void Animal::turnVertically()
{
	if (d == direction::UP) { d = direction::DOWN; }
	if (d == direction::DOWN) { d = direction::UP; }
}

 void Animal::turnHorizontally()
{
	if (d == direction::LEFT) { d = direction::RIGHT; }
	if (d == direction::RIGHT) { d = direction::LEFT; }
}
