#include "Giraffe.h"

void Giraffe::setLengthOfNeck(float lengthOfNeck) throw(const char *)
{
	if (lengthOfNeck <= 0)
		throw "The length of the neck must be positive";

	this->lengthOfNeck = lengthOfNeck;
}

Giraffe::Giraffe(const char * name, float weight, int birthYear, float lengthOfNeck)
	:Animal(name, weight, birthYear)
{
	setLengthOfNeck(lengthOfNeck);
}

inline float Giraffe::getLengthOfNeck() const
{
	return this->lengthOfNeck;
}

void Giraffe::toOs(ostream & os) const
{
	os << ", lengthOfNeck= " << lengthOfNeck;
}
