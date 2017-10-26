#include "Veterinarian.h"

void Veterinarian::setLicenseNumber(int licenseNumber) throw(const char *)
{
	if (licenseNumber <= 0)
		throw "The veterinarian's license number must be positive";
	this->licenseNumber = licenseNumber;
}

Veterinarian::Veterinarian(const char * name, long idNumber, int salary, int licenseNumber)
	:Worker(name, idNumber, salary)
{
	setLicenseNumber(licenseNumber);
}

inline int Veterinarian::getLicenseNumber() const
{
	return this->licenseNumber;
}

void Veterinarian::toOs(ostream & os) const
{
	os << ", licenseNumber= " << licenseNumber;
}
