//
//  Zoo.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 18/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __ZOO_H
#define __ZOO_H

#include "Area.h"
#include "Worker.h"
#include "Animal.h"


class Zoo
{
private:
	char* name;
	int maxNumOfAreas;
	int numOfAreas;
	Area** areas;
	Area quarentineArea;

	void setMaxNumOfAreas(int maxNumOfAreas) throw (const char*);
	void setName(const char* name) throw (const char*);

public:
	Zoo(const char* name, int maxNumOfAreas, const Area& quarentineArea);
	~Zoo();

	Zoo(const Zoo& other) = delete;
	const Zoo& operator=(const Zoo& zoo) = delete;

	const char* getName() const;

	int getMaxNumOfAreas() const;

	int getNumOfAreas() const;

	const Area& getQuarentineAreaArea() const;

	void addArea(Area& area)  throw (const char *);

	void addAnimal(Animal& animal, const char* areaName)  throw (const char*);

	void addWorker(Worker& worker, const char* areaName)  throw (const char*);

	const Area** getAllAreas() const;

	const Zoo& operator+(Area& area);

	const Area& operator[](int index) const throw (const char*);

	friend ostream& operator<<(ostream& os, const Zoo& zoo);
};

#endif /* __ZOO_H */
