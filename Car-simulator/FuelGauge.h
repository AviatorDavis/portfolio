#ifndef FuelGauge_H
#define FuelGauge_H
#include <iostream>
//#include "Odometer.h"

using namespace std;
//FuelGauge CLASS
class FuelGauge
{	

	friend ostream& operator<<(ostream&, FuelGauge&);
//	void checkFuel(FuelGauge&, Odometer&);
	
	private:
		int fuel=0;
		int MAX_FUEL = 15;
	public:
		FuelGauge();
		FuelGauge(int f);
		FuelGauge operator++();
		FuelGauge operator--();
		void fuelUp(int);
		void setFuel(int);
		int getFuel();
		

};

#endif
