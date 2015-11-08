#include "stdafx.h"
#include "railvehicle.h"
#include "engine.h"


RailVehicle::RailVehicle()
{
	Prev = NULL;
	Next = NULL;
}

RailVehicle::~RailVehicle()
{
	std::cout << "Destruction of vehicle" << endl;
}

RailVehicle *RailVehicle::getNext()
{
	return this->Next;
}


RailVehicle *RailVehicle::getFront()
{
	RailVehicle *Ptr = this;
	while (Ptr->Next != NULL)
	{
		Ptr = Ptr->getNext();
	}
	return Ptr;
}


void RailVehicle::ShowAll(ostream &o)
{
	RailVehicle *Ptr = this->getFront();
	do
	{
		Ptr->ShowThis(o);
	} while ((Ptr = Ptr->Prev) != NULL);
}

RailVehicle *RailVehicle::ConnectToNext(RailVehicle *nextPtr) throw (char)
{
	if (nextPtr == NULL)
	{
		if (Prev != NULL)
		{
			delete Prev;
			Prev = NULL;
		}

	}
	else
	{
		Engine *isEngine = dynamic_cast<Engine*>(nextPtr);
		if (isEngine != 0)
		{
			throw "This is not an engine";
		}
		if (this->Prev != NULL)
		{
			throw "";
		}

		this->Prev = nextPtr;
		nextPtr->Next = this;
	}
}