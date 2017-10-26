#include "Area.h"

void Area::setMaxNumberOfAnimals(int maxNumberOfAnimals) throw(const char *)
{
	if (maxNumberOfAnimals <= 0)
		throw "Maximum number of animals per area must be positive";

	this->maxNumberOfAnimals = maxNumberOfAnimals;
	animals = new const Animal*[maxNumberOfAnimals];
}

void Area::setMaxNumberOfWorkers(int maxNumberOfWorkers) throw(const char *)
{
	if (maxNumberOfWorkers < 0)
		throw "Maximum number of worker in each area can not be negative";

	this->maxNumberOfWorkers = maxNumberOfWorkers;
	workers = new const Worker*[maxNumberOfWorkers];
}

void Area::setName(const char * name) throw(const char *)
{
	if (strlen(name) == 0)
		throw "Area name can not be empty";

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Area::Area(const char * name, int maxNumberOfAnimals, int maxNumberOfWorkers, AreaManager * areaManager)
	: numOfAnimals(0), numOfWorkers(0)
{
	setName(name);
	setMaxNumberOfAnimals(maxNumberOfAnimals);
	setMaxNumberOfWorkers(maxNumberOfWorkers);

	if (areaManager != nullptr)
		setAreaManager(*areaManager);
}

Area::~Area()
{
	delete[]name;
	delete[]animals;
	delete[]workers;
}

const char * Area::getName() const
{
	return this->name;
}

inline int Area::getNumOfAnimals() const
{
	return this->numOfAnimals;
}

int Area::getMaxNumberOfAnimals() const
{
	return this->maxNumberOfAnimals;
}

inline int Area::getNumOfWorkers() const
{
	return this->numOfWorkers;
}

int Area::getMaxNumberOfWorkers() const
{
	return this->maxNumberOfWorkers;
}

inline const AreaManager& Area::getAreaManager() const
{
	return *(this->areaManager);
}

void Area::setAreaManager(AreaManager& areaManager)
{
	if (this->areaManager == nullptr)
	{
		this->areaManager = &areaManager;
	}
	else if (this->areaManager != &areaManager)
	{
		(this->areaManager)->removeArea();
		this->areaManager = &areaManager;
	}
}

void Area::addAnimal(const Animal & animal) throw(const char *)
{
	if (numOfAnimals == maxNumberOfAnimals)
		throw "You can not add an animal to an area that's already full";

	this->animals[numOfAnimals++] = &animal;
}

void Area::addWorker(const Worker & worker) throw(const char *)
{
	if (numOfWorkers == maxNumberOfWorkers)
		throw "You can not add an worker to an area that's already full";

	this->workers[numOfWorkers++] = &worker;
}

const Animal ** Area::getAllAnimals() const
{
	return animals;
}

const Worker ** Area::getAllworkers() const
{
	return workers;
}

const Area & Area::operator+=(const Animal & animal)
{
	addAnimal(animal);
	return *this;
}

bool Area::operator<(const Area & area) const
{
	return this->maxNumberOfAnimals < area.maxNumberOfAnimals;
}

bool Area::operator>(const Area & area) const
{
	return this->maxNumberOfAnimals < area.maxNumberOfAnimals;
}

bool Area::operator==(const Area & area) const
{
	return (this->getName() == area.getName());
}

ostream & operator<<(ostream & os, const Area & area)
{
	os << "name= " << area.name
		<< ", numOfAnimals= " << area.numOfAnimals << " from " << area.maxNumberOfAnimals
		<< ", numOfWorkers= " << area.numOfWorkers << " from " << area.maxNumberOfWorkers
		<< ", areaManager= ";

	if (area.areaManager != nullptr)
		os << area.areaManager->getName();
	else
		os << "null";

	os << endl << endl << "Animals: " /*<< endl << "--------"*/;
	for (int i = 0; i < area.numOfAnimals; i++)
	{
		os << endl << *area.animals[i];
	}

	os << endl << endl << "Workers: " /*<< endl << "--------"*/;
	for (int i = 0; i < area.numOfWorkers; i++)
	{
		os << endl << *area.workers[i];
	}

	return os;
}
