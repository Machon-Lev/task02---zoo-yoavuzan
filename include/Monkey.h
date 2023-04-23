// Created by:  Yoav Uzan
#include "Animal.h"
class Monkey : public Animal
{	
private:
	int counter;
	void doingMove(int step_to_move);
public:
Monkey(const std::string n, const Loction l);
void step() ;
const char  getInitial()  { return 'M'; }
};
