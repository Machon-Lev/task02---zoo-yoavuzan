#include "Animal.h"

Animal::Animal(const string n, const Location l)
{
    // Constructor for the Animal class that initializes its name and location
    name = n;
    location = l;
}

void Animal::printDetails() const
{
    // Print the details of the animal, including its name, type, location, and if it can move
    cout << "Name: " << name << " Type: " << typeOfAnimal << " Location: " << location << " Can move: ";
    if (!stopMove)
        cout << "yes\n";
    else
        cout << "No\n";
}

void Animal::turnVertically()
{
    // Change the direction of the animal vertically (up to down or down to up)
    if (d == direction::UP) {
        d = direction::DOWN;
    }
    if (d == direction::DOWN) {
        d = direction::UP;
    }
}

void Animal::turnHorizontally()
{
    // Change the direction of the animal horizontally (left to right or right to left)
    if (d == direction::LEFT) {
        d = direction::RIGHT;
    }
    if (d == direction::RIGHT) {
        d = direction::LEFT;
    }
}
