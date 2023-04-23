#pragma once
#include <vector>
#include <iostream>
#include "Monkey.h"
#include "Lion.h"
#include "Owl.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;

Loction randLoc();
class Zoo
{
public:
	void run();
private:
	vector <Animal*> allAnimals ;
	void stop(int i);
	void move(int i);
	void create(string typeOfAnimal, string name);
	void del(int i);
	void delAll(string typeOfAnimal);
	void help();  
	void step();
	void printTheMap();
};
