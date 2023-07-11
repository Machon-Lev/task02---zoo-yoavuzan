#include "Animal.h"

Animal::Animal(const string n, const Location l)
{
    // Constructor for the Animal class that initializes its name and location
    _name = n;
    _location = l;
}

void Animal::printDetails() const
{
    // Print the details of the animal, including its name, type, location, and if it can move
    cout << "Name: " << _name << " Type: " << _typeOfAnimal << " Location: " << _location << " Can move: ";
    if (!_stopMove)
        cout << "yes\n";
    else
        cout << "No\n";
}

void Animal::turnVertically()
{
    // Change the direction of the animal vertically (up to down or down to up)
    if (_d == direction::UP) {
        _d = direction::DOWN;
    }
    if (_d == direction::DOWN) {
        _d = direction::UP;
    }
}

void Animal::turnHorizontally()
{
    // Change the direction of the animal horizontally (left to right or right to left)
    if (_d == direction::LEFT) {
        _d = direction::RIGHT;
    }
    if (_d == direction::RIGHT) {
        _d = direction::LEFT;
    }
}
