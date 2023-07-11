#include "Owl.h"

Owl::Owl(const string n, Location l) :Animal(n, l)
{
	if (!(l._row < 17 && l._row > 2 && l._col < 37 && l._col > 2))
	{
		setLocation(2 + (rand() % 15), 2 + (rand() % 35));
	}
	typeOfAnimal = "Owl";
	d = (direction)(5 + (rand() % 4));
}

bool Owl::checkRowAndCol(int _row, int _col)
{
	return _row<20 && _row > -1 && _col<40 && _col > -1;
}

void Owl::doingMove(int step_to_move)
{

	if (d == direction::UL)
	{
		if (checkRowAndCol(location._row - step_to_move, location._col - step_to_move))
		{
			location._row = location._row - step_to_move;
			location._col = location._col - step_to_move;
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
		if (checkRowAndCol(location._row + step_to_move, location._col - step_to_move))
		{
			location._row = location._row + step_to_move;
			location._col = location._col - step_to_move;
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
		if (checkRowAndCol(location._row - step_to_move, location._col + step_to_move))
		{
			location._row = location._row - step_to_move;
			location._col = location._col + step_to_move;
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
		if (checkRowAndCol(location._row + step_to_move, location._col + step_to_move))
		{
			location._row = location._row + step_to_move;
			location._col = location._col + step_to_move;
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

