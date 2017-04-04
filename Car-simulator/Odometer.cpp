
using namespace std;
#include "Odometer.h"
//#inlcude "FuelGauge.h"

//Odometer::Functions()
Odometer::Odometer(int m)
{
	mileage=m;
	milesAfterGas = m;
}

//out put Odometer
ostream& operator<<(ostream& print, Odometer& odom)
{
	print<<"\nOdometer indicating -> "<< odom.mileage;
	return print;
}
//mileage ++;
Odometer Odometer::operator++()
{
	driveMile();
	//Vehicle.checkFuel();
	//*this->DateValidation();
	return *this;
}

void Odometer::driveMile()
{
	if(mileage==999999)
	{
		cout<<"\nMaxed out odometer at 999,999. Will reset to 0...";
		mileage=0;
		milesAfterGas = 999999 - milesAfterGas;
		milesAfterGas = 0 - milesAfterGas;
		cout<<"\nOdometer indicating -> "<< mileage;
	}
	else
		mileage++;
}
//get
int Odometer::getMileage()
{
	return mileage;	
}

int Odometer::getMilesAfterGas()
{
	return milesAfterGas;
}

void Odometer::setMileage(int m)
{
	mileage = m;	
}

void Odometer::setMilesAfterGas(int mag)
{
	milesAfterGas = mag;
}  

