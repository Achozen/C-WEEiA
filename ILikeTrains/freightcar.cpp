#include "stdafx.h"
#include "railvehicle.h"
#include "freightcar.h"
#include "engine.h"

FreightCar::FreightCar() : RailVehicle()
{
	Prev = NULL;
	Next = NULL;
	mass = 0;

}

FreightCar::~FreightCar()
{
	std::cout << "Destroy the FreightCar !!!" << endl;
	system("pause");
}

int FreightCar::getSpeed()
{
	RailVehicle *Ptr = this;
	while (Ptr->getNext() != NULL)
	{
		Ptr = Ptr->getNext();
	}
	Engine *isEngine = dynamic_cast<Engine*>(Ptr);
	if (isEngine != 0)
	{
		return isEngine->getSpeed();
	}
	return 0;
}

int FreightCar::addFreight(int add) throw (char)
{
	if (this->getSpeed() == 0)
	{
		mass = mass + add;
	}
	else
	{
		throw "You cannot add freight weight while you drive you filthy bastart!";
//		system("pause");
	}

}

int FreightCar::removeFreight(int rem) throw (char)
{
	if (this->getSpeed() == 0)
	{
		if (rem <= mass)
		{
			mass = mass - rem;
		}
		else throw "You cannot remove more weight than freight have";
//		system("pause");
	}
	else throw "You cannot remove freight weight while you drive you filthy bastart!";
}

void FreightCar::ShowThis(ostream &o)
{
	o << "Freights mass is " << mass << endl;
//	system("pause");
}