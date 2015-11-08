#ifndef FREIGHTCAR_H
#define FREIGHTCAR_H
#include <iostream>
#include "stdafx.h"
#include "railvehicle.h"
class FreightCar : public RailVehicle
{
protected:
	int mass;
public:
	FreightCar();
	~FreightCar();
	int addFreight(int add);
	int removeFreight(int rem);
	void ShowThis(ostream &o);
	int getSpeed();
};
#endif