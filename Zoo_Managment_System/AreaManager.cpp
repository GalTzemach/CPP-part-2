#include "AreaManager.h"

void AreaManager::setYearsOfExperience(int yearsOfExperience) throw(const char *)
{
	if (yearsOfExperience < 0)
		throw "The number of years of experience must be positive";

	this->yearsOfExperience = yearsOfExperience;
}

AreaManager::AreaManager(const char * name, long idNumber, int salary, int yearsOfExperience)
	:Worker(name, idNumber, salary)
{
	setYearsOfExperience(yearsOfExperience);
}

inline int AreaManager::getYearsOfExperience() const
{
	return yearsOfExperience;
}

void AreaManager::toOs(ostream & os) const
{
	os << ", yearsOfExperience= " << yearsOfExperience;
}
