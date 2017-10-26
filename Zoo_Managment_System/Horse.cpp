#include "Horse.h"

void Horse::setSizeOfHorseShoe(float sizeOfHorseShoe) throw(const char *)
{
	if (sizeOfHorseShoe < 0)
		throw "The horseshoe size must be positive";

	this->sizeOfHorseShoe = sizeOfHorseShoe;
}

Horse::Horse(const char * name, float weight, int birthYear, float sizeOfHorseShoe)
	:Animal(name, weight, birthYear)
{
	setSizeOfHorseShoe(sizeOfHorseShoe);
}

float Horse::getSizeOfHorseShoe() const
{
	return sizeOfHorseShoe;
}

void Horse::toOs(ostream & os) const
{
	os << ", sizeOfHorseShoe:" << sizeOfHorseShoe;
}
