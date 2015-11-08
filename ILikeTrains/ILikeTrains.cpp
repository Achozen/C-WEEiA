// ILikeTrains.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "engine.h"
#include "freightcar.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int speed = 0;

	try
	{
	
		Engine *engine = new Engine(speed);
		FreightCar *car1 = new FreightCar;
		FreightCar *car2 = new FreightCar;
		FreightCar *car3 = new FreightCar;

		engine->ConnectToNext(car1);
		car1->ConnectToNext(NULL);
		car2->ConnectToNext(car3);

		car1->addFreight(20);
		car2->addFreight(30);
		car1->removeFreight(10);
		engine->changeSpeed(30);
		car2->getSpeed();
		car1->removeFreight(10);
		car2->ShowAll(cout);
		system("pause");
	}
	catch (const char * exc)
	{
		cout << exc << endl;
		system("pause");
	}
	return 0;
}

