// Created by: Yoav Uzan
#include "Animal.h"

class Owl : public Animal
{
private:
    // Perform the movement of the Owl by a given number of steps
    void doingMove(int step_to_move);

    // Check if the given row and column are within the valid range
    bool checkRowAndCol(int row, int col);

public:
    // Constructor for the Owl class that takes a name and a location
    Owl(const std::string n, const Location l);

    // Perform a step for the Owl
    void step();

    // Get the initial character representing the Owl
    const char getInitial() { return 'O'; }
};
