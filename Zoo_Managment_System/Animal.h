//
//  Animal.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __ANIMAL_H
#define __ANIMAL_H

#pragma warning( disable : 4290 )

#include <ctime>
#include <iostream>
using namespace std;

// Forward declaration
class Area;


class Animal
{

private:
	char* name;
	float weight;
	int birthYear;
	Area* area;

	void setName(const char* name) throw (const char*);
	void setWeight(float weight) throw (const char*);
	void setBirthYear(int birthYear) throw (const char*);

public:
	Animal(const char *name, float weight, int birthYear, const Area* area = nullptr);
	virtual ~Animal();

	Animal(const Animal& animal) = delete;
	const Animal& operator=(const Animal& animal) = delete;

	virtual inline const char* getName() const;

	virtual inline float getWeight() const;

	virtual inline int getBirthYear() const;

	virtual void toOs(ostream& os) const = 0;
	friend ostream& operator<<(ostream& os, const Animal& animal);

};

#endif /* __ANIMAL_H */
