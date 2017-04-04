#ifndef Odometer_H
#define Odometer_H
#include <iostream>
//#include "FuelGauge.h"

using namespace std;
//Odometer CLASS
class Odometer
{	
//add friends
	friend ostream& operator<<(ostream&, Odometer&);
//	void checkFuel(FuelGauge&, Odometer&);	
	
	private:
		int mileage=0;
		int MAX_MILEAGE = 999999;
		int MIN_MILEAGE = 0;
		int milesAfterGas= 0;
	public:
		Odometer(int m=0);
		Odometer operator++();
		void driveMile();
		int getMileage();
		void setMileage(int);
		int getMilesAfterGas();
		void setMilesAfterGas(int);
		
};

#endif
