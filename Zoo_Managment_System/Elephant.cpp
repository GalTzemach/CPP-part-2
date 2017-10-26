#include "Elephant.h"

void Elephant::setSizeOfEars(float sizeOfEars) throw(const char *)
{
	if (sizeOfEars < 0)
		throw "Ear size can not be negative";

	this->sizeOfEars = sizeOfEars;
}

void Elephant::setLengthOfTrunk(float lengthOfTrunk) throw(const char *)
{
	if (lengthOfTrunk < 0)
		throw "The length of the trunk can not be negative";

	this->lengthOfTrunk = lengthOfTrunk;
}

Elephant::Elephant(const char * name, float weight, int birthYear, float sizeOfEars, float lengthOfTrunk)
	:Animal(name, weight, birthYear)
{
	setSizeOfEars(sizeOfEars);
	setLengthOfTrunk(lengthOfTrunk);
}

inline float Elephant::getSizeOfEars() const
{
	return this->sizeOfEars;
}

inline float Elephant::getLengthOfTrunk() const
{
	return lengthOfTrunk;
}

void Elephant::toOs(ostream & os) const
{
	os << ", sizeOfEars= " << sizeOfEars << ", lengthOfTrunk= " << lengthOfTrunk;
}
