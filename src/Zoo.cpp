#include "Zoo.h"

Location randLoc()
{
    // Generate a random location with row and col values within the valid range
    Location l;
    l._col = 1 + (rand() % 40);
    l._row = 1 + (rand() % 20);
    return l;
}

int enterNumOfAnimal()
{
    // Prompt the user to enter the number of an animal
    cout << "Please enter the number of the animal:\n";
    int num;
    cin >> num;
    return num;
}

string entertypeOfAnimall()
{
    // Prompt the user to enter the type of an animal
    cout << "Please enter the type of animal:\n";
    string type;
    cin >> type;
    return type;
}

void Zoo::run()
{
    // Providing a seed value for randomization
    srand((unsigned)time(NULL));

    cout << "Welcome!\n";
    Monkey m("Rafiki", randLoc());
    Lion l1("Simba", randLoc());
    Lion l2("Mufasa", randLoc());
    _allAnimals.push_back(&m);
    _allAnimals.push_back(&l1);
    _allAnimals.push_back(&l2);
    Owl o("Hedwig", randLoc());
    _allAnimals.push_back(&o);

    printTheMap();

    while (true)
    {
        std::cout << "\nPlease enter an order. Enter 'help' to see all options.\n";
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
                cout << "Please enter the name of the animal you want to add:\n";
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
            else
            {
                cout << "The input was invalid.\n";
            }
            printTheMap();
        }
        catch (const std::exception& e)
        {
            cout << e.what();
            cout << "The input was invalid.\n";
        }
    }

    cout << "Goodbye :-)\n";
}

void Zoo::stop(int i)
{
    // Stop the movement of the animal at the given index
    _allAnimals[i]->stop();
}

void Zoo::move(int i)
{
    // Allow the animal at the given index to move
    _allAnimals[i]->move();
}

void Zoo::create(string typeOfAnimal, string name)
{
    // Create a new animal of the given type with the given name
    if (typeOfAnimal == "Monkey")
    {
        _allAnimals.push_back(new Monkey(name, randLoc()));
    }
    else if (typeOfAnimal == "Lion")
    {
        _allAnimals.push_back(new Lion(name, randLoc()));
    }
    else if (typeOfAnimal == "Owl")
    {
        _allAnimals.push_back(new Owl(name, randLoc()));
    }
    else
    {
        throw std::exception("The type of animal does not exist.");
    }
}

void Zoo::del(int i)
{
    // Delete the animal at the given index
    _allAnimals.erase(_allAnimals.begin() + i);
}

void Zoo::delAll(string typeOfAnimal)
{
    // Delete all animals of the given type
    for (int i = 0; i < _allAnimals.size(); i++)
    {
        if (_allAnimals[i]->getInitial() == typeOfAnimal[0])
        {
            _allAnimals.erase(_allAnimals.begin() + i);
            i--; // Update the index to account for the removed element
        }
    }
}

void Zoo::help()
{
    // Print the available commands and their usage
    cout << "The available commands are:\n"
        << "stop\n"
        << "move\n"
        << "create\n"
        << "del\n"
        << "delAll\n"
        << "help\n"
        << "step\n"
        << "exit\n";
}

void Zoo::step()
{
    // Perform a step for all animals
    for (int i = 0; i < _allAnimals.size(); i++)
    {
        _allAnimals[i]->step();
    }
}

void Zoo::printTheMap()
{
    const int ROWS = 20;
    const int COLS = 40;

    char matrix[ROWS][COLS];

    // Initialize the matrix with underscore characters
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            matrix[i][j] = '_';
        }
    }

    // Place the animals on the matrix according to their location
    for (int i = 0; i < _allAnimals.size(); i++)
    {
        auto loc = _allAnimals[i]->getLocation();
        matrix[loc._row][loc._col] = _allAnimals[i]->getInitial();
    }

    // Print the matrix
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << matrix[i][j];
        }
        cout << "\n";
    }

    // Print the details of each animal
    for (int i = 0; i < _allAnimals.size(); i++)
    {
        cout << i << " ";
        _allAnimals[i]->printDetails();
        cout << "\n";
    }
}
