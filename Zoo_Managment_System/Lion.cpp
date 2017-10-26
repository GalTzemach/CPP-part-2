#include "Lion.h"

Lion::Lion(const char * name, float weight, int birthYear, eManeColor maneColor)
	:Animal(name, weight, birthYear)
{
	this->maneColor = maneColor;
}

inline Lion::eManeColor Lion::getManeColor() const
{
	return this->maneColor;
}

void Lion::toOs(ostream & os) const
{
	os << ", maneColor= " << maneColor;
}
