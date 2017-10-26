//
//  Elephant.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __ELEPHANT_H
#define __ELEPHANT_H

#include "Animal.h"
#include "Area.h"


class Elephant : public Animal
{

private:
	float sizeOfEars;
	float lengthOfTrunk;

	void setSizeOfEars(float sizeOfEars) throw (const char*);
	void setLengthOfTrunk(float lengthOfTrunk) throw (const char*);

public:
	Elephant(const char *name, float weight, int birthYear, float sizeOfEars, float lengthOfTrunk);

	Elephant(const Elephant& elephant) = delete;
	const Elephant& operator=(const Elephant& elephant) = delete;

	inline float getSizeOfEars() const;
	inline float getLengthOfTrunk() const;

	virtual void toOs(ostream& os) const override;
};

#endif /* __ELEPHANT_H */
