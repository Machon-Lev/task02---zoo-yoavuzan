#include "Monkey.h"

Monkey::Monkey(const string n, const Location l) : Animal(n, l)
{
    // Monkey constructor that sets the type of animal to "Monkey" and randomly assigns a direction
    counter = 0;
    typeOfAnimal = "Monkey";
    d = (direction)(1 + (rand() % 4));
}

void Monkey::doingMove(int step_to_move)
{
    // Perform the movement of the Monkey by a given number of steps
    // The direction is taken into account, and the Monkey may change direction if it hits a boundary
    if (d == direction::UP || d == direction::LEFT)
        step_to_move = step_to_move * -1;

    if (d == direction::UP || d == direction::DOWN)
    {
        if (location._row + step_to_move < 40 && location._row + step_to_move > -1)
            location._row = location._row + step_to_move;
    }

    if (d == direction::LEFT || d == direction::RIGHT)
    {
        if (location._col + step_to_move < 20 && location._col + step_to_move > -1)
            location._col = location._col + step_to_move;
    }
}

void Monkey::step()
{
    if (!stopMove)
    {
        if (counter % 5 == 0)
        {
            // Change the direction randomly and move a random number of steps
            d = (direction)(1 + (rand() % 4));
            int step_to_move = 1 + (rand() % 2);
            doingMove(step_to_move);
            counter++;
        }
        else
        {
            counter++;
        }
    }
}
