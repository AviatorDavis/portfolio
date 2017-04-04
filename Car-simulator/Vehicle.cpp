
using namespace std;
#include "Vehicle.h"


//FuelGauge::Functions()
Vehicle::Vehicle(int miles,int fuel, int mpg):
		fg(fuel),od(miles)
{
	MPG = mpg;
//	FuelGauge tempFG(fuel);
//	Odometer tempO(miles);
	//set fuelGauge.
//	fuelgauge.setFuel(tempFG.getFuel());
//	odometer.setMileage(tempO.getMileage());
	cout<<"\nVehicle created with "<<miles<<" miles and a maximum "<< fuel<<" gallon size tank and "<< " with "<<mpg<<" mpg burn rate.";

}

	int Vehicle::checkFuel()
{
	//check to see if 24 miles have gone by
	if(od.getMileage() == (MPG+od.getMilesAfterGas()))
	{
		cout<<"\n\t\tGallon of fuel consummed ";
		fg.operator--();
		od.setMilesAfterGas(od.getMileage());
		cout<<fg.getFuel()<<" gallons remaing.";
		if(fg.getFuel() == 0)
			return 0;	//retun false, ran out of gas
		else
			return 1;	//return true. still fuel
	}
	else
	{
		return 1;	//return true still fuel
	}
	
}

void Vehicle::fuel(int f)
{
	fg.fuelUp(f);
}

Vehicle Vehicle::operator++()
{
	if(fg.getFuel()!=0)
		++od;
	//checkFuel();
	return *this;
}

void Vehicle::display()
{
	cout<<"\n=====================================";
	cout<<od;
	cout<<fg;
	cout<<"\n#####################################";

}

//output Vechile 
ostream& operator<<(ostream& print, Vehicle& vec)
{
	vec.display();
	return print;
}
