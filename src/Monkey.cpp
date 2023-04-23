#include "Monkey.h"
 Monkey::Monkey(const string n, const Loction l) :Animal(n, l)
{
	counter = 0;
	typeOfAnimal = "Monkey";
	d = (direction)(1 + (rand() % 4));
}
 void Monkey::doingMove(int step_to_move)
{
	if (d == direction::UP || d == direction::LEFT)
		step_to_move = step_to_move * -1;
	if (d == direction::UP || d == direction::DOWN)
	{
		if (loction.row + step_to_move<40 && loction.row + step_to_move > -1)
			loction.row = loction.row + step_to_move;
	}
	if (d == direction::LEFT || d == direction::RIGHT)
	{
		if (loction.col + step_to_move<20 && loction.col + step_to_move > -1)
			loction.col = loction.col + step_to_move;
	}
}
 void Monkey::step()
{
	if (!stopMove)
	{
		if (counter % 5 == 0)
		{
			d = (direction)(1 + (rand() % 4));
			int step_to_move = 1 + (rand() % 2);
			doingMove(step_to_move);
			counter++;
		}
		else
			counter++;
	}
}
