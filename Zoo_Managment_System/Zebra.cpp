#include "Zebra.h"

void Zebra::setNumOfStrips(int numOfStrips) throw(const char *)
{
	if (numOfStrips < 0)
		throw "The number of zebra stripes can not be negative";

	this->numOfStrips = numOfStrips;
}

Zebra::Zebra(const char * name, float weight, int birthYear, int numOfStrips)
	:Animal(name, weight, birthYear)
{
	setNumOfStrips(numOfStrips);
}

inline int Zebra::getNumOfStrips() const
{
	return numOfStrips;
}

void Zebra::toOs(ostream & os) const
{
	os << ", numOfStrips= " << numOfStrips;
}
