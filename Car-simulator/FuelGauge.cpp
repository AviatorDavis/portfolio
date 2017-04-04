
using namespace std;
#include "FuelGauge.h"
//#include "Odometer.h"
//FuelGauge::Functions()
FuelGauge::FuelGauge()
{
	fuel=15;
	MAX_FUEL = 15;
} 
FuelGauge::FuelGauge(int f)
{
	fuel = f;
	MAX_FUEL = f;
}

//get set
int FuelGauge::getFuel()
{
	return fuel;
}

void FuelGauge::setFuel(int f)
{
	fuel = f;	
}

//out put FuelGauge
ostream& operator<<(ostream& print, FuelGauge& fg)
{
	print<<"\nFuel guague indicating -> "<< fg.fuel;
	return print;
}

//fuelgauge ++;
FuelGauge FuelGauge::operator++()
{
	if(fuel+1 != (MAX_FUEL+1))
		++fuel;
	else
		cout<<"\nCannot add anymore gas, fueltank is already holding"<< MAX_FUEL <<" gallons.";
	//*this->DateValidation();
	return *this;
}

//fuelgauge --
FuelGauge FuelGauge::operator--()
{
	if(fuel-1 != -1)
		--fuel;
	else
		cout<<"\nGas tank is empty!";
	//*this.DateValidation();
	return *this;
}

void FuelGauge::fuelUp(int f)
{	//add fuel
	int overFlow=0;
	int neededFuel=0;
	if(f > 0)	//check to see positive added
	{
		//added to much
		if( f == 99 )
		{
			neededFuel = MAX_FUEL - fuel;
			cout<<"\n->Topped the tank off with "<<neededFuel<<" gallons.";
			fuel = MAX_FUEL;
		}
		else if( fuel + f > MAX_FUEL)
		{
			cout<<"\n->Adding "<< f << " gallons into the tank.";
			fuel = fuel + f;
			overFlow = fuel - MAX_FUEL;
			fuel = MAX_FUEL;
			cout<<"\n->Over filled, spilling "<<overFlow<<" gallons of gas on the ground.";
		}
		else
		{
			cout<<"\n->Adding "<< f << " gallons into the tank.";
			fuel = f + fuel;
			cout<<"\n->Added "<<f<<" gallons into the gas tank.";
		}
	}
	else if(f==0)
		cout<<"\n->No more gas to add";
	else
		cout<<"\n->Impossible to add Negitive gallons";
	
}
