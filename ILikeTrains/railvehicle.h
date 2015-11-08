#ifndef RAILVEHICLE_H
#define RAILVEHICLE_H
#include <iostream>
using namespace std;
class RailVehicle
{
protected:
	RailVehicle *Next;
	RailVehicle *Prev;

public:
	RailVehicle();
	~RailVehicle();

	RailVehicle *getNext();
	RailVehicle *getFront();
	RailVehicle *ConnectToNext(RailVehicle *nextPtr);
	virtual int getSpeed() = 0;
	virtual void ShowThis(ostream &o) = 0;
	void ShowAll(ostream &o);

};
#endif