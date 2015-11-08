#include "stdafx.h"
#include "railvehicle.h"
#include "engine.h"


Engine::Engine(int Speed) : RailVehicle()
{
	this->Speed = Speed;
	Prev = NULL;
	Next = NULL;

}

Engine::~Engine()
{
	std::cout << "Wywolany Destruktor" << endl;
}

int Engine::changeSpeed(int value)
{
	this->Speed = value;
	return Speed;
}

void Engine::ShowThis(ostream &o)
{
	o << "Lokomotywa predkosc: " << Speed << endl;
}

int Engine::getSpeed()
{
	return Speed;
}