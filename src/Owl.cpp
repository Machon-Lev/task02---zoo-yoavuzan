#include "Owl.h"

Owl::Owl(const string n, Location l) :Animal(n, l)
{
	if (!(l._row < 17 && l._row > 2 && l._col < 37 && l._col > 2))
	{
		setLocation(2 + (rand() % 15), 2 + (rand() % 35));
	}
	_typeOfAnimal = "Owl";
	_d = (direction)(5 + (rand() % 4));
}

bool Owl::checkRowAndCol(int _row, int _col)
{
	return _row<20 && _row > -1 && _col<40 && _col > -1;
}

void Owl::doingMove(int step_to_move)
{

	if (_d == direction::UL)
	{
		if (checkRowAndCol(_location._row - step_to_move, _location._col - step_to_move))
		{
			_location._row = _location._row - step_to_move;
			_location._col = _location._col - step_to_move;
			return;
		}
		else
		{
			_d = direction::DR;
			doingMove(3);
			return;
		}
	}
	if (_d == direction::DL)
	{
		if (checkRowAndCol(_location._row + step_to_move, _location._col - step_to_move))
		{
			_location._row = _location._row + step_to_move;
			_location._col = _location._col - step_to_move;
			return;
		}
		else
		{
			_d = direction::UR;
			doingMove(3);
			return;
		}
	}
	if (_d == direction::UR)
	{
		if (checkRowAndCol(_location._row - step_to_move, _location._col + step_to_move))
		{
			_location._row = _location._row - step_to_move;
			_location._col = _location._col + step_to_move;
			return;
		}
		else
		{
			_d = direction::DL;
			doingMove(3);
			return;
		}
	}
	if (_d == direction::DR)
	{
		if (checkRowAndCol(_location._row + step_to_move, _location._col + step_to_move))
		{
			_location._row = _location._row + step_to_move;
			_location._col = _location._col + step_to_move;
			return;
		}
		else
		{
			_d = direction::UL;
			doingMove(3);
			return;
		}
	}
}


void Owl::step()
{
	if (!_stopMove)
	{
		doingMove(3);
	}
}

