#pragma warning( disable : 4290 )

#include <iostream>
using namespace std;

#include "Zoo.h"
#include "Area.h"
#include "Animal.h"
#include "Worker.h"
#include "AreaManager.h"
#include "Veterinarian.h"
#include "Keeper.h"
#include "MaintenanceWorker.h"
#include "Elephant.h"
#include "Giraffe.h"
#include "Horse.h"
#include "Lion.h"
#include "Penguin.h"
#include "Zebra.h"
#include "Zebroid.h"

Area** createAllAreas(int& numOfAreas, AreaManager** managers, int& numOfManagers);
AreaManager** createAreaManagers(int& numOfManagers, int& numOfAreas);
void addAreasToZoo(Zoo& zoo, Area** areas, int& numOfAreas);
Animal** createAnimals(int& numOfAnimals);
void addAllAnimalsToZoo(Zoo& myZoo, Animal** animals, int& numOfAnimals);
Keeper** createAllKeepers(int& numOfKeepers);
void addKeepersToZoo(Zoo& myZoo, Keeper** keepers, int& numOfKeepers);
Veterinarian** createAllVeterinarian(int& numOfVeterinarian);
void addAllVeterinarianToZoo(Zoo& myZoo, Veterinarian**vets, int& numOfVeterinarian);
void freeAllAreaManagers(AreaManager** areaManagers, int& numOfAreaManagers);
void freeAllAreas(Area** areas, int& numOfAreas);
void freeAllAnimals(Animal** animals, int& numOfAnimals);
void freeAllVeterinarian(Veterinarian** vets, int& numOfVeterinarian);
void freeAllKeepers(Keeper** keepers, int& numOfKeepers);

int main()
{
	static constexpr int NUM_OF_AREAS = 3;
	static constexpr int NUM_OF_MANAGERS = 3;

	try
	{
		AreaManager quarantineManager("Meny", 5468, 50000, 20);
		Area quarentineArea("quarentineArea", 4, 4, &quarantineManager);

		Zoo myZoo("My Zoo", 10, quarentineArea);

		int numOfAreas = NUM_OF_AREAS;
		int numOfManagers = NUM_OF_MANAGERS;

		AreaManager** managers = createAreaManagers(numOfManagers, numOfAreas);

		Area** areas = createAllAreas(numOfAreas, managers, numOfManagers);

		// add all areas
		addAreasToZoo(myZoo, areas, numOfAreas);

		int numOfAnimals;
		Animal** animals = createAnimals(numOfAnimals);

		// add animals
		addAllAnimalsToZoo(myZoo, animals, numOfAnimals);

		int numOfKeepers;
		Keeper** keepers = createAllKeepers(numOfKeepers);

		// add all the keepers
		addKeepersToZoo(myZoo, keepers, numOfKeepers);

		int numOfVeterinarian;
		Veterinarian** vets = createAllVeterinarian(numOfVeterinarian);

		// add all vets
		addAllVeterinarianToZoo(myZoo, vets, numOfVeterinarian);

		// print the whole zoo
		cout << " ========" << endl << "||My Zoo||" << endl << " ========" << "\n" << myZoo << endl << endl;

		// free all memory
		freeAllAnimals(animals, numOfAnimals);
		freeAllAreaManagers(managers, numOfManagers);
		freeAllAreas(areas, numOfAreas);
		freeAllKeepers(keepers, numOfKeepers);
		freeAllVeterinarian(vets, numOfVeterinarian);
	}
	catch (const char* message)
	{
		cout << message;
	}
	catch (...)
	{
		cout << "Something went wrong" << endl;
	}

	system("pause");
	return 0;
}

AreaManager** createAreaManagers(int& numOfManagers, int& numOfAreas)
{
	///numOfManagers = 3;
	const char* managersNames[] = { "Yogev", "Moshe", "Roie" };
	int managersId[] = { 31235, 51455, 84578 };
	int managersSalary[] = { 5000, 4500, 4800 };
	int managersYearsOfExperience[] = { 2, -3, 4 };

	AreaManager** managers = new AreaManager*[numOfManagers];

	for (int i = 0; i < numOfManagers; i++)
		managers[i] = nullptr;

	for (int i = 0; i < numOfManagers && i < numOfAreas; i++)
	{
		try
		{
			managers[i] = new AreaManager(managersNames[i], managersId[i], managersSalary[i], managersYearsOfExperience[i]);
		}
		catch (const char* errMessage)
		{
			cout << "Could not create manager " << managersNames[i] << ":" << endl << errMessage << endl << endl;
			managers[i] = nullptr;
			numOfManagers = i;
			break;
		}
	}

	return managers;
}

Area** createAllAreas(int& numOfAreas, AreaManager** managers, int& numOfManagers)
{
	///numOfAreas = 3;
	int maxNumberOfAnimals = 4, maxNumberOfWorkers = 4, wrongMaxNumberOfAnimals = -5;
	const char* areasNames[] = { "A1", "A2", "A3" };
	Area** areas = new Area*[numOfAreas];

	for (int i = 0; i < numOfAreas; i++)
	{
		try
		{
			areas[i] = new Area(areasNames[i], maxNumberOfAnimals, maxNumberOfWorkers, managers[i]);
		}
		catch (const char* errMessage)
		{
			cout << "Could not create area " << areasNames[i] << ":" << endl << errMessage << endl << endl;
			areas[i] = nullptr;
			numOfAreas = i;
			break;
		}
	}

	return areas;
}

void addAreasToZoo(Zoo& zoo, Area** areas, int& numOfAreas)
{
	for (int i = 0; i < numOfAreas; i++)
	{
		try
		{
			zoo.addArea(*areas[i]);
		}
		catch (const char* errMessage)
		{
			cout << "Area " << areas[i]->getName() << " was not added to the zoo:" << endl << errMessage << endl << endl;
		}
	}
}

Animal** createAnimals(int& numOfAnimals)
{
	numOfAnimals = 4;
	const char* names[] = { "Horsy", "Pini", "Eli", "Zeze" };
	Animal** animals = new Animal*[numOfAnimals];

	for (int i = 0; i < numOfAnimals; i++)
	{
		try
		{
			switch (i%numOfAnimals)
			{
			case 0:
			{
				animals[i] = new Horse(names[i], 208.5f, 1998, 40.2f);
				break;
			}
			case 1:
			{
				animals[i] = new Penguin(names[i], 1.2f, 2005, Penguin::CRAB);
				break;
			}
			case 2:
			{
				animals[i] = new Elephant(names[i], 2.5f, 1752, 1.35f, 2.75f);
				break;
			}
			case 3:
			{
				animals[i] = new Zebroid(names[i], 1.45f, 2010, 128, 38.6f);
				break;
			}
			}
		}
		catch (const char *errMessage)
		{
			cout << "Could not create animal " << names[i] << ":" << endl << errMessage << endl << endl;
			animals[i] = nullptr;
			numOfAnimals = i;
			break;
		}
	}
	return animals;
}

void addAllAnimalsToZoo(Zoo& myZoo, Animal** animals, int& numOfAnimals)
{
	int numOfAreas = myZoo.getNumOfAreas();

	const Area** areas = myZoo.getAllAreas();

	for (int i = 0; i < numOfAnimals && i < numOfAreas; i++)
	{
		try
		{
			myZoo.addAnimal(*animals[i], areas[i]->getName());
		}
		catch (const char* errMessage)
		{
			cout << "Could not add " << animals[i]->getName() << ":" << endl << errMessage << endl << endl;
		}
	}

	// another animal to the last area
	myZoo.addAnimal(*animals[3], areas[2]->getName());
}

Keeper** createAllKeepers(int& numOfKeepers)
{
	numOfKeepers = 3;
	const char*  keepersNames[] = { "Kipi", "Keepi", "Keepee" };
	int keepersId[] = { 312542, 387542, 955642 }, keeperSalary = 7500;
	Keeper::eAnimal animals[] = { Keeper::PENGUIN, Keeper::ELEPHANT, Keeper::HORSE };

	Keeper** keepers = new Keeper*[numOfKeepers];

	for (int i = 0; i < numOfKeepers; i++)
	{
		try
		{
			keepers[i] = new Keeper(keepersNames[i], keepersId[i], keeperSalary, animals[i]);
		}
		catch (const char* errMessage)
		{
			cout << "Could not create keeper " << keepers[i]->getName() << endl << ":" << errMessage << endl << endl;
			keepers[i] = nullptr;
			numOfKeepers = i;
			break;
		}
	}

	return keepers;
}

void addKeepersToZoo(Zoo& myZoo, Keeper** keepers, int& numOfKeepers)
{
	int numOfAreas = myZoo.getNumOfAreas();

	const Area** areas = myZoo.getAllAreas();

	for (int i = 0; i < numOfKeepers && i < numOfAreas; i++)
	{
		try
		{
			myZoo.addWorker(*keepers[i], areas[i]->getName());
		}
		catch (const char* errMessage)
		{
			cout << "Could not add keeper " << keepers[i]->getName() << " to the zoo:" << endl << errMessage << endl << endl;
		}
	}
}

Veterinarian** createAllVeterinarian(int& numOfVeterinarian)
{
	numOfVeterinarian = 3;
	const char* vetsNames[] = { "Dr. Vivi", "Dr. Vuvu", "Dr. Kobi" };
	int vetsId[] = { 45875, 87457, 26584 }, vetsSalary = 10000, vetsLicenseNumbers[] = { 5, 8, 10 };

	Veterinarian** vets = new Veterinarian*[numOfVeterinarian];

	for (int i = 0; i < numOfVeterinarian; i++)
	{
		try
		{
			vets[i] = new Veterinarian(vetsNames[i], vetsId[i], vetsSalary, vetsLicenseNumbers[i]);
		}
		catch (const char* errMessage)
		{
			cout << "Could not create Veterinarian " << vets[i]->getName() << ":" << endl << errMessage << endl << endl;
			vets[i] = nullptr;
			numOfVeterinarian = i;
			break;
		}
	}

	return vets;
}

void addAllVeterinarianToZoo(Zoo& myZoo, Veterinarian**vets, int& numOfVeterinarian)
{
	int numOfAreas = myZoo.getNumOfAreas();
	const Area** areas = myZoo.getAllAreas();

	for (int i = 0; i < numOfVeterinarian && i < numOfAreas; i++)
	{
		try
		{
			myZoo.addWorker(*vets[i], areas[i]->getName());
		}
		catch (const char* errMessage)
		{
			cout << "Could not add Veterinarian " << vets[i]->getName() << " to the zoo:" << endl << errMessage << endl << endl;
		}
	}
}

void freeAllAreaManagers(AreaManager** areaManagers, int& numOfAreaManagers)
{
	for (int i = 0; i < numOfAreaManagers; i++)
	{
		delete areaManagers[i];
	}

	delete[]areaManagers;
}

void freeAllAreas(Area** areas, int& numOfAreas)
{
	for (int i = 0; i < numOfAreas; i++)
	{
		delete areas[i];
	}

	delete[]areas;
}

void freeAllAnimals(Animal** animals, int& numOfAnimals)
{
	for (int i = 0; i < numOfAnimals; i++)
	{
		delete animals[i];
	}

	delete[]animals;
}

void freeAllVeterinarian(Veterinarian** vets, int& numOfVeterinarian)
{
	for (int i = 0; i < numOfVeterinarian; i++)
	{
		delete vets[i];
	}

	delete[]vets;
}

void freeAllKeepers(Keeper** keepers, int& numOfKeepers)
{
	for (int i = 0; i < numOfKeepers; i++)
	{
		delete keepers[i];
	}

	delete[]keepers;
}
