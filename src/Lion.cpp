#include "Lion.h"

Lion::Lion(const string n, const Location l) : Animal(n, l)
{
    // Lion constructor that sets the type of animal to "Lion" and randomly assigns a direction
    typeOfAnimal = "Lion";
    d = (direction)(3 + (rand() % 2));
}

bool Lion::checkCol(int _col)
{
    // Check if the given column is within the valid range
    return _col < 40 && _col > -1;
}

bool Lion::checkRow(int row)
{
    // Check if the given row is within the valid range
    return row < 20 && row > -1;
}

void Lion::step()
{
    // Perform a step for the Lion if it is allowed to move
    if (!stopMove)
    {
        doingMove(2);
    }
}

void Lion::move()
{
    // Move the Lion if it is currently not allowed to move
    if (stopMove)
    {
        d = (direction)(3 + (rand() % 2));
        stopMove = false;
    }
}

void Lion::doingMove(int step_to_move)
{
    // Perform the movement of the Lion by a given number of steps
    // The direction is taken into account, and the Lion may change direction if it hits a boundary
    if (d == direction::LEFT)
        step_to_move = step_to_move * -1;

    if (checkCol(location._col + step_to_move))
        location._col = location._col + step_to_move;
    else
    {
        // If the Lion hits a boundary while moving left, change its direction to right and try again
        // If the Lion hits a boundary while moving right, change its direction to left and try again
        d == direction::LEFT ? d = direction::RIGHT : d = direction::LEFT;
        doingMove(2);
        return;
    }
}
