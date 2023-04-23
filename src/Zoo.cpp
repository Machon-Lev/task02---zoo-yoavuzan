#include "Zoo.h"
Loction randLoc() {
	Loction l;
	l.col = 1 + (rand() % 40);
	l.row = 1 + (rand() % 20);
	return l;
}
int enterNumOfAnimal()
{
	cout << "plese enter the number of animal\n";
	int num;
	cin >> num;
	return num;
}
string entertypeOfAnimall()
{
	cout << "plese enter the type of animal\n";
	string type;
	cin >> type;
	return type;
}

void Zoo::run()
{
	// Providing a seed value
	srand((unsigned)time(NULL));
	cout << "Wellcom !\n";
	Monkey m("Rafiki", randLoc());
	Lion l1("Simba", randLoc());
	Lion l2("Mufasa", randLoc());
	allAnimals.push_back(&m);
	allAnimals.push_back(&l1);
	allAnimals.push_back(&l2);
	Owl o("Hedwig", randLoc());
	allAnimals.push_back(&o);
	printTheMap();
	while (true)
	{
		std::cout << "\nplese enter orders, enter help to see all option\n";
		std::string str;
		cin >> str;
		try
		{
			if (str == "stop")
			{
				int num = enterNumOfAnimal();
				stop(num);
			}
			else if (str == "move")
			{
				int num = enterNumOfAnimal();
				move(num);
			}
			else if (str == "create")
			{
				string type = entertypeOfAnimall();
				cout << "please enter the name of the animal you want to add\n";
				string name;
				cin >> name;
				create(type, name);
			}
			else if (str == "del")
			{
				int num = enterNumOfAnimal();
				del(num);
			}
			else if (str == "delAll")
			{
				string type = entertypeOfAnimall();
				delAll(type);
			}
			else if (str == "help")
			{
				help();
			}
			else if (str == "step")
			{
				step();
			}
			else if (str == "exit")
			{
				break;
			}
			else { cout << "The input was unillegel\n"; }
			printTheMap();
		}
		catch (const std::exception& e)
		{
			cout << e.what();
			cout << "The input was unillegel\n";
		}
	}
	cout << "GoofBye : - )";
}

void Zoo::stop(int i)
{
	allAnimals[i]->stop();
}

void Zoo::move(int i)
{
	allAnimals[i]->move();
}

 void Zoo::create(string typeOfAnimal, string name)
{
	if (typeOfAnimal == "Monkey")
	{
		allAnimals.push_back(new Monkey(name, randLoc()));
	}
	else if (typeOfAnimal == "Lion")
	{
		allAnimals.push_back(new Lion(name, randLoc()));
	}
	else if (typeOfAnimal == "Owl")
	{
		allAnimals.push_back(new Owl(name, randLoc()));
	}
	else
	{
		throw std::exception("The type of animal is not exist");
	}
}

 void Zoo::del(int i)
{
	allAnimals.erase(allAnimals.begin() + i);
}

 void Zoo::delAll(string typeOfAnimal)
{
	// Remove all the values equal to typeOfAnimal
	for (int i = 0; i < allAnimals.size(); i++) {
		if (allAnimals[i]->getInitial() == typeOfAnimal[0]) {
			allAnimals.erase(allAnimals.begin() + i);
			i--; // update the index to account for the removed element
		}
	}
}

 void Zoo::help()
{
	cout << "The orders you can use is only :\nstop\nmove\ncreate\ndel\ndelAll\nhelp\nstep\nexit\n";
}

 void Zoo::step()
{
	for (int i = 0; i < allAnimals.size(); i++)
	{
		allAnimals[i]->step();
	}
}

 void Zoo::printTheMap()
{
	const int ROWS = 20;
	const int COLS = 40;

	char matrix[ROWS][COLS];
	// Initialize the matrix with null characters
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			matrix[i][j] = '_';
		}
	}

	for (int i = 0; i < allAnimals.size(); i++)
	{
		auto loc = allAnimals[i]->getLocation();
		matrix[loc.row][loc.col] = allAnimals[i]->getInitial();
	}

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << matrix[i][j];
		}
		cout << "\n";
	}
	for (int i = 0; i < allAnimals.size(); i++)
	{
		cout << i << " ";
		allAnimals[i]->printDetails();
		cout << "\n";
	}

}
