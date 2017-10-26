//
//  Zebroid.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __ZEBROID_H
#define __ZEBROID_H

#include "Horse.h"
#include "Zebra.h"

class Zebroid : public Horse, public Zebra
{

public:
	Zebroid(const char *name, float weight, int birthYear, int numOfStrips, float sizeOfHorseShoe);

	Zebroid(const Zebroid& zebroid) = delete;
	const Zebroid& operator=(const Zebroid& zebroid) = delete;

	virtual inline const char* getName() const override;

	virtual inline float getWeight() const override;

	virtual inline int getBirthYear() const override;

	virtual void toOs(ostream& os) const override;

};

#endif /* __ZEBROID_H */
