#include "Lion.h"

 Lion::Lion(const string n, const Loction l) :Animal(n, l)
{
	typeOfAnimal = "Lion";
	d = (direction)(3 + (rand() % 2));
}

 bool Lion::checkCol(int col)
{
	return col<40 && col > -1;
}

 bool Lion::checkRow(int row)
{
	return row<20 && row > -1;
}

 void Lion::step()
{
	if (!stopMove)
	{
		doingMove(2);
	}
}

 void Lion::move()
{
	if (stopMove)
	{
		d = (direction)(3 + (rand() % 2));
		stopMove = false;
	}
}

 void Lion::doingMove(int step_to_move)
{
	if (d == direction::LEFT)
		step_to_move = step_to_move * -1;
	if (checkCol(loction.col + step_to_move))
		loction.col = loction.col + step_to_move;
	else
	{
		d == direction::LEFT ? d = direction::RIGHT : d = direction::LEFT;
		doingMove(2);
		return;
	}
}
