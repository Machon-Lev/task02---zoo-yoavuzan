#include "Owl.h"

Owl::Owl(const string n, Loction l) :Animal(n, l)
{
	if (!(l.row < 17 && l.row > 2 && l.col < 37 && l.col > 2))
	{
		setLocation(2 + (rand() % 15), 2 + (rand() % 35));
	}
	typeOfAnimal = "Owl";
	d = (direction)(5 + (rand() % 4));
}

bool Owl::checkRowAndCol(int row, int col)
{
	return row<20 && row > -1 && col<40 && col > -1;
}

void Owl::doingMove(int step_to_move)
{

	if (d == direction::UL)
	{
		if (checkRowAndCol(loction.row - step_to_move, loction.col - step_to_move))
		{
			loction.row = loction.row - step_to_move;
			loction.col = loction.col - step_to_move;
			return;
		}
		else
		{
			d = direction::DR;
			doingMove(3);
			return;
		}
	}
	if (d == direction::DL)
	{
		if (checkRowAndCol(loction.row + step_to_move, loction.col - step_to_move))
		{
			loction.row = loction.row + step_to_move;
			loction.col = loction.col - step_to_move;
			return;
		}
		else
		{
			d = direction::UR;
			doingMove(3);
			return;
		}
	}
	if (d == direction::UR)
	{
		if (checkRowAndCol(loction.row - step_to_move, loction.col + step_to_move))
		{
			loction.row = loction.row - step_to_move;
			loction.col = loction.col + step_to_move;
			return;
		}
		else
		{
			d = direction::DL;
			doingMove(3);
			return;
		}
	}
	if (d == direction::DR)
	{
		if (checkRowAndCol(loction.row + step_to_move, loction.col + step_to_move))
		{
			loction.row = loction.row + step_to_move;
			loction.col = loction.col + step_to_move;
			return;
		}
		else
		{
			d = direction::UL;
			doingMove(3);
			return;
		}
	}
}


void Owl::step()
{
	if (!stopMove)
	{
		doingMove(3);
	}
}

