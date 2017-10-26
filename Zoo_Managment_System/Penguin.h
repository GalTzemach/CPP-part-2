//
//  Penguin.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __PENGUIN_H
#define __PENGUIN_H

#include "Animal.h"

class Penguin : public Animal
{

public:
	enum eSeaFood { SHRIMP, CRAB, FISH, CALAMARI };

	Penguin(const char *name, float weight, int birthYear, eSeaFood favoriteFood);

	Penguin(const Penguin& penguin) = delete;
	const Penguin& operator=(const Penguin& penguin) = delete;

	inline eSeaFood getFavoriteFood() const;
	void setFavoriteFood(eSeaFood favoriteFood);

	virtual void toOs(ostream& os) const override;

private:
	eSeaFood favoriteFood;

};

#endif /* __PENGUIN_H */
