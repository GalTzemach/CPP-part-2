#include "MaintenanceWorker.h"

MaintenanceWorker::MaintenanceWorker(const char * name, long idNumber, int salary, float shoeSize)
	:Worker(name, idNumber, salary)
{
	setShoeSize(shoeSize);
}

float MaintenanceWorker::getShoeSize() const
{
	return this->shoeSize;
}

void MaintenanceWorker::setShoeSize(float shoeSize) throw(const char *)
{
	if (shoeSize <= 0)
		throw "Shoe size must be positive";

	this->shoeSize = shoeSize;
}

void MaintenanceWorker::toOs(ostream & os) const
{
	os << ", shoeSize= " << shoeSize;
}
