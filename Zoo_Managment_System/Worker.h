//
//  Worker.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __WORKER_H
#define __WORKER_H

#pragma warning( disable : 4290 )

#include <iostream>
using namespace std;

// Forward declaration
class Area;


// Abstract class
class Worker
{

private:
	char* name;
	long idNumber;
	int salary;
	Area* area;

	void setIdNumber(long idNumber) throw (const char*);

public:
	Worker(const char *name, long idNumber, int salary, Area* area = nullptr);
	virtual ~Worker();

	Worker(const Worker& worker) = delete;
	const Worker& operator=(const Worker& worker) = delete;

	const char* getName() const;
	void setName(const char* name) throw (const char*);

	inline long getIdNumber() const;

	inline int getSalary() const;
	void setSalary(int salary) throw (const char*);

	inline const Area& getArea() const;
	void setArea(Area& area);
	void removeArea();

	virtual void toOs(ostream& os) const = 0;
	friend ostream& operator<<(ostream& os, const Worker& worker);

};

#endif /* __WORKER_H */
