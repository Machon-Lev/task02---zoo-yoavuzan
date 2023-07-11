// Created by: Yoav Uzan
#include "Animal.h"

class Monkey : public Animal
{
private:
    int counter;

    // Perform the movement of the Monkey by a given number of steps
    void doingMove(int step_to_move);

public:
    // Constructor for the Monkey class that takes a name and a location
    Monkey(const std::string n, const Location l);

    // Perform a step for the Monkey
    void step();

    // Get the initial character representing the Monkey
    const char getInitial() { return 'M'; }
};
