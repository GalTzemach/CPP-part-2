//
//  Maintenance_Worker.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __MAINTENANCE_WORKER_H
#define __MAINTENANCE_WORKER_H

#include "Worker.h"

class MaintenanceWorker : public Worker
{
private:
	float shoeSize;

public:
	MaintenanceWorker(const char *name, long idNumber, int salary, float shoeSize);

	MaintenanceWorker(const MaintenanceWorker& maintenanceWorker) = delete;
	const MaintenanceWorker& operator=(const MaintenanceWorker& maintenanceWorker) = delete;

	inline float getShoeSize() const;
	void setShoeSize(float shoeSize) throw (const char*);

	virtual void toOs(ostream& os) const override;
};

#endif /* __MAINTENANCE_WORKER_H */
