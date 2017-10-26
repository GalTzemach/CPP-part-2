//
//  Giraffe.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __GIRAFFE_H
#define __GIRAFFE_H

#include "Animal.h"


class Giraffe : public Animal
{

private:
	float lengthOfNeck;

	void setLengthOfNeck(float lengthOfNeck) throw (const char*);

public:
	Giraffe(const char *name, float weight, int birthYear, float lengthOfNeck);

	Giraffe(const Giraffe& giraffe) = delete;
	const Giraffe& operator=(const Giraffe& giraffe) = delete;

	inline float getLengthOfNeck() const;

	virtual void toOs(ostream& os) const override;

};

#endif /* __GIRAFFE_H */
