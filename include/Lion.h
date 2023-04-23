// created by Yoav Uzan
#include "Animal.h"
class Lion : public Animal
{
private:
	void doingMove(int step_to_move);
	bool checkRow(int row);
	bool checkCol(int col);
public:
	Lion(const std::string n, const Loction l);
	void step();
	const char  getInitial() { return 'L'; }
	void move()override;
};

