#pragma once
#include <string>
#include <list>
#include "Loction.cpp"
#include <iostream>
using std::cout;
using std::string;
class Animal {
protected:
	enum class direction
	{
		UP = 1,
		DOWN = 2,
		RIGHT = 3,
		LEFT = 4,
		DL=5,
		DR=6,
		UL=7,
		UR=8
	};
	Loction loction;
	string name;
	string typeOfAnimal;
	direction d;
	bool stopMove = false;
public:
	Animal(const string n, const Loction l);
	void printDetails() const;
	virtual const char  getInitial() = 0;
	Loction getLocation() { return loction; }
	virtual void step() = 0;
	void stop() { stopMove = true; }
	virtual void move() { stopMove = false; };
	void turnVertically() ;
	void turnHorizontally() ;
	void setLocation(int row, int col) { loction.row = row; loction.col = col; }
	
 };
#pragma once