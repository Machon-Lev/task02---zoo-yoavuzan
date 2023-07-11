#pragma once
#include <string>
#include <list>
#include <iostream>
#include "../src/Location.cpp"
#include "direction.h"

using std::cout;
using std::string;

class Animal {
protected:
    Location _location;
    string _name;
    string _typeOfAnimal;
    direction _d;
    bool _stopMove = false;

public:
    // Constructor for the Animal class that takes a name and a location
    Animal(const string n, const Location l);

    // Print the details of the animal
    void printDetails() const;

    // Abstract method to get the initial character of the animal's type
    virtual const char getInitial() = 0;

    // Get the current location of the animal
    Location getLocation() { return _location; }

    // Abstract method for the animal to perform a step
    virtual void step() = 0;

    // Stop the movement of the animal
    void stop() { _stopMove = true; }

    // Allow the animal to move
    virtual void move() { _stopMove = false; };

    // Change the direction of the animal vertically
    void turnVertically();

    // Change the direction of the animal horizontally
    void turnHorizontally();

    // Set the location of the animal with the given _row and _column values
    void setLocation(int _row, int _col) { _location._row = _row; _location._col = _col; }
};
