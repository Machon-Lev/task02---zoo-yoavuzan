#pragma once
#include <vector>
#include <iostream>
#include "Monkey.h"
#include "Lion.h"
#include "Owl.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;

// Function to generate a random location
Location randLoc();

class Zoo
{
public:
    // Run the zoo simulation
    void run();

private:
    vector<Animal*> _allAnimals;

    // Stop the movement of the animal at the given index
    void stop(int i);

    // Allow the animal at the given index to move
    void move(int i);

    // Create a new animal of the given type with the given name
    void create(string typeOfAnimal, string name);

    // Delete the animal at the given index
    void del(int i);

    // Delete all animals of the given type
    void delAll(string typeOfAnimal);

    // Print the available commands and their usage
    void help();

    // Perform a step for all animals
    void step();

    // Print the current state of the zoo map
    void printTheMap();
};
