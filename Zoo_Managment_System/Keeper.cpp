#include "Keeper.h"

Keeper::Keeper(const char * name, long idNumber, int salary, eAnimal keeperSpecialty)
	:Worker(name, idNumber, salary)
{
	this->keeperSpecialty = keeperSpecialty;
}

inline Keeper::eAnimal Keeper::getKeeperSpecialty() const
{
	return this->keeperSpecialty;
}

void Keeper::toOs(ostream & os) const
{
	os << ", keeperSpecialty= " << keeperSpecialty;
}
