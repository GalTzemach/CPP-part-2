#include "Zebroid.h"

Zebroid::Zebroid(const char * name, float weight, int birthYear, int numOfStrips, float sizeOfHorseShoe)
	:Animal(name, weight, birthYear),
	Zebra(name, weight, birthYear, numOfStrips),
	Horse(name, weight, birthYear, sizeOfHorseShoe)
{}

inline const char * Zebroid::getName() const
{
	return ((Animal*)this)->getName(); ///
}

inline float Zebroid::getWeight() const
{
	return ((Animal*)this)->getWeight(); ///
}

inline int Zebroid::getBirthYear() const
{
	return ((Animal*)this)->getBirthYear(); ///
}

void Zebroid::toOs(ostream & os) const
{
	Horse::toOs(os);
	Zebra::toOs(os);
}


