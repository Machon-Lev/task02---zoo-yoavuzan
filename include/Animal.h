#pragma once
#include <string>
#include <list>
#include "Location.cpp"
#include <iostream>

using std::cout;
using std::string;

class Animal {
protected:
    // Enumeration for the possible directions an animal can move
    enum class direction
    {
        UP = 1,
        DOWN = 2,
        RIGHT = 3,
        LEFT = 4,
        DL = 5,
        DR = 6,
        UL = 7,
        UR = 8
    };

    Location location;
    string name;
    string typeOfAnimal;
    direction d;
    bool stopMove = false;

public:
    // Constructor for the Animal class that takes a name and a location
    Animal(const string n, const Location l);

    // Print the details of the animal
    void printDetails() const;

    // Abstract method to get the initial character of the animal's type
    virtual const char getInitial() = 0;

    // Get the current location of the animal
    Location getLocation() { return location; }

    // Abstract method for the animal to perform a step
    virtual void step() = 0;

    // Stop the movement of the animal
    void stop() { stopMove = true; }

    // Allow the animal to move
    virtual void move() { stopMove = false; };

    // Change the direction of the animal vertically
    void turnVertically();

    // Change the direction of the animal horizontally
    void turnHorizontally();

    // Set the location of the animal with the given _row and _column values
    void setLocation(int _row, int _col) { location._row = _row; location._col = _col; }
};
