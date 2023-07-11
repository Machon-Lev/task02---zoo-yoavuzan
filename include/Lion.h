// created by Yoav Uzan
#include "Animal.h"

class Lion : public Animal
{
private:
    // Perform the movement of the Lion by a given number of steps
    void doingMove(int step_to_move);

    // Check if the given row is within the valid range
    bool checkRow(int row);

    // Check if the given column is within the valid range
    bool checkCol(int col);

public:
    // Constructor for the Lion class that takes a name and a location
    Lion(const std::string n, const Location l);

    // Perform a step for the Lion
    void step();

    // Get the initial character representing the Lion
    const char getInitial() { return 'L'; }

    // Move the Lion (override the base class method)
    void move() override;
};
