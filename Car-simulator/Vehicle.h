#ifndef Vehicle_H
#define Vehicle_H
#include <iostream>
#include "FuelGauge.h"
#include "Odometer.h"

using namespace std;
//Vehicle CLASS
class Vehicle
{	
	friend ostream& operator<<(ostream&, Vehicle&);
	
	private:
		FuelGauge fg;
		Odometer od;
		int MPG = 0;
	public:
		Vehicle(int=0,int=15, int=24);
		int checkFuel();
		void fuel(int);
		Vehicle operator++();
		void display();

};

#endif
