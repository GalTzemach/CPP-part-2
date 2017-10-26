//
//  Area_Manager.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __AREA_MANAGER_H
#define __AREA_MANAGER_H

#include "Worker.h"


class AreaManager : public Worker
{
private:
	int yearsOfExperience;

	void setYearsOfExperience(int yearsOfExperience) throw (const char*);

public:
	AreaManager(const char *name, long idNumber, int salary, int yearsOfExperience);

	AreaManager(const AreaManager& areaManager) = delete;
	const AreaManager& operator=(const AreaManager& areaManager) = delete;

	inline int getYearsOfExperience() const;

	virtual void toOs(ostream& os) const override;
};

#endif /* __AREA_MANAGER_H */
