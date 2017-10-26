#include "Penguin.h"

Penguin::Penguin(const char * name, float weight, int birthYear, eSeaFood favoriteFood)
	:Animal(name, weight, birthYear)
{
	setFavoriteFood(favoriteFood);
}

inline Penguin::eSeaFood Penguin::getFavoriteFood() const
{
	return this->favoriteFood;
}

void Penguin::setFavoriteFood(eSeaFood favoriteFood)
{
	this->favoriteFood = favoriteFood;
}

void Penguin::toOs(ostream & os) const
{
	os << ", favoriteFood= " << favoriteFood;
}
