// Created by: Yoav Uzan
#include "Animal.h"
class Owl : public Animal
{
private:
	void doingMove(int step_to_move);
	bool checkRowAndCol(int row,int col);
public:
	Owl(const std::string n, const Loction l);
	void step();
	const char  getInitial() { return 'O'; }
};


