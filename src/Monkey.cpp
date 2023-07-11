#include "Monkey.h"

Monkey::Monkey(const string n, const Location l) : Animal(n, l)
{
    // Monkey constructor that sets the type of animal to "Monkey" and randomly assigns a direction
    _counter = 0;
    _typeOfAnimal = "Monkey";
    _d = (direction)(1 + (rand() % 4));
}

void Monkey::doingMove(int step_to_move)
{
    // Perform the movement of the Monkey by a given number of steps
    // The direction is taken into account, and the Monkey may change direction if it hits a boundary
    if (_d == direction::UP || _d == direction::LEFT)
        step_to_move = step_to_move * -1;

    if (_d == direction::UP || _d == direction::DOWN)
    {
        if (_location._row + step_to_move < 40 && _location._row + step_to_move > -1)
            _location._row = _location._row + step_to_move;
    }

    if (_d == direction::LEFT || _d == direction::RIGHT)
    {
        if (_location._col + step_to_move < 20 && _location._col + step_to_move > -1)
            _location._col = _location._col + step_to_move;
    }
}

void Monkey::step()
{
    if (!_stopMove)
    {
        if (_counter % 5 == 0)
        {
            // Change the direction randomly and move a random number of steps
            _d = (direction)(1 + (rand() % 4));
            int step_to_move = 1 + (rand() % 2);
            doingMove(step_to_move);
            _counter++;
        }
        else
        {
            _counter++;
        }
    }
}
