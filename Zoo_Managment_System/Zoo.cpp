#include "Zoo.h"

Zoo::Zoo(const char * name, int maxNumOfAreas, const Area & quarentineArea)
	: quarentineArea(quarentineArea.getName(), quarentineArea.getMaxNumberOfAnimals(), quarentineArea.getMaxNumberOfWorkers())
{
	setName(name);
	setMaxNumOfAreas(maxNumOfAreas);
}

Zoo::~Zoo()
{
	delete[]name;
	delete[]areas;
}

const char * Zoo::getName() const
{
	return this->name;
}

int Zoo::getMaxNumOfAreas() const
{
	return this->maxNumOfAreas;
}

int Zoo::getNumOfAreas() const
{
	return this->numOfAreas;
}

const Area & Zoo::getQuarentineAreaArea() const
{
	return this->quarentineArea;
}

void Zoo::addArea(Area & area) throw(const char *)
{
	if (numOfAreas == maxNumOfAreas)
		throw "You can not add more areas to the zoo";

	for (int i = 0; i < numOfAreas; i++)
	{
		if (area == *(this->areas[i]))
			throw "This area already exist in the zoo";
	}

	this->areas[numOfAreas++] = &area;
}

void Zoo::addAnimal(Animal & animal, const char * areaName) throw(const char *)
{
	for (int i = 0; i < numOfAreas; i++)
	{
		if ((this->areas[i])->getName() == areaName)
		{
			this->areas[i]->addAnimal(animal);
			return;
		}
	}

	throw "This area not exist in zoo";
}

void Zoo::addWorker(Worker & worker, const char * areaName) throw(const char *)
{
	for (int i = 0; i < numOfAreas; i++)
	{
		if ((this->areas[i])->getName() == areaName)
		{
			this->areas[i]->addWorker(worker);
			return;
		}
	}

	throw "This area not exist in zoo";
}

const Area ** Zoo::getAllAreas() const
{
	return (const Area**)this->areas;
}

const Zoo & Zoo::operator+(Area & area)
{
	this->addArea(area);
	return *this;
}

const Area & Zoo::operator[](int index) const throw (const char*)
{
	if (index < 0)
		throw "Index of area must be positive";
	if (index > numOfAreas)
		throw "Index of area is too large";
	return *(this->areas[index]);
}


void Zoo::setMaxNumOfAreas(int maxNumOfAreas) throw(const char *)
{
	if (maxNumOfAreas <= 0)
		throw "The number of areas must be positive";

	this->maxNumOfAreas = maxNumOfAreas;
	this->areas = new Area*[maxNumOfAreas];
}

void Zoo::setName(const char * name) throw(const char *)
{
	if (strlen(name) == 0)
		throw "Zoo name can not be empty";

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

ostream & operator<<(ostream & os, const Zoo & zoo)
{
	os << "name= " << zoo.name << ", numOfAreas= " << zoo.numOfAreas << " from " << zoo.maxNumOfAreas;

	for (int i = 0; i < zoo.numOfAreas; i++)
		os << endl << endl << "Area " << i + 1 << ":" << endl << "=======" << endl << *zoo.areas[i] << endl;

	os << endl << endl << "Area " << "quarentineArea:" << endl << "====================" << endl << zoo.quarentineArea << endl;

	return os;
}
