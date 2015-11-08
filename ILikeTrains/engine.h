#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>
#include "stdafx.h"
#include "railvehicle.h"
using namespace std;

class Engine : public RailVehicle
{
protected:
	int Speed;
public:
	Engine(int Speed);
	~Engine();
	int changeSpeed(int value);
	void ShowThis(ostream &o);
	int getSpeed();
};
#endif