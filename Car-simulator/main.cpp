#include <iostream>
#include <vector>
#include "FuelGauge.h"
#include "Odometer.h"
#include "Vehicle.h"

using namespace std;

/*
void checkFuel(FuelGauge& fg, Odometer& o)
{
	//check to see if 24 miles have gone by
	if(o.getMileage()== (24+o.getMilesAfterGas()))
	{
		cout<<"\nGallon of fuel consummed.";
		fg.fuel--;
		o.milesAfterGas=o.mileage;
	}
}
*/
int main()
{
	Vehicle car(998900,10,32);
	int trip=0;
	int gas=297;
	
	while(gas>0)
	{
		//drive while
		cout<<"\n\nBegin driving till empty.";
		while(car.checkFuel())
		{
			++car;
			trip++;
			if(trip==50)
			{
				trip=0;
				cout<<"\n\tJust finished driving 50 more miles.";
			}
		}
		//next time add half as much
		gas = gas/3;
		cout<<car;
		//add gas
		car.fuel(gas);
	}
	
	
	cout<<"\n\n\nAnother Vehicle\n\n\n";
	Vehicle motorcycle(21000,4,55);
	trip=0;
	gas=297;
	
	while(gas>0)
	{
		//drive while
		cout<<"\n\nBegin driving till empty.";
		while(motorcycle.checkFuel())
		{
			++motorcycle;
			trip++;
			if(trip==50)
			{
				trip=0;
				cout<<"\n\tJust finished driving 50 more miles.";
			}
		}
		//next time add half as much
		gas = gas/3;
		cout<<motorcycle;
		//add gas
		motorcycle.fuel(gas);
	}
	
	
cout<<"End of simulator";	
return 0;
}

