//
//  Keeper.h
//  Zoo_Management_System
//
//  Created by Almog Segal on 01/08/2017.
//  Copyright © 2017 Almog Segal. All rights reserved.
//

#ifndef __KEEPER_H
#define __KEEPER_H

#include "Worker.h"


class Keeper : public Worker
{

public:
	enum eAnimal { LION, PENGUIN, ELEPHANT, GIRAFFE, ZEBRA, HORSE, ZEBROID };

	Keeper(const char *name, long idNumber, int salary, eAnimal keeperSpecialty);

	Keeper(const Keeper& keeper) = delete;
	const Keeper& operator=(const Keeper& keeper) = delete;

	inline eAnimal getKeeperSpecialty() const;

	virtual void toOs(ostream& os) const override;

private:
	eAnimal keeperSpecialty;
};

#endif /* __KEEPER_H */
