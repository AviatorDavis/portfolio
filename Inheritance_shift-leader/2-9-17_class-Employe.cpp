/*Employee in class
Classes
Donald Davis
2/9/17
*/

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

class Employee
{
	string name;
	int id;
	float payRate;
	
	public:
		void setName(string);
		void setID(int);
		void setPayRate(float );
		string getName();
		int getID();
		float getPayRate();
};


void Employee::setName(string name)
{
	Employee::name=name;
}

string Employee::getName()
{
	return name;
}

void Employee::setID(int id)
{
	Employee::id=id;
}

int Employee::getID()
{
	return id;	
}

void Employee::setPayRate(float payRate)
{
	Employee::payRate= payRate;
}

float Employee::getPayRate()
{	
	return payRate;
}


int main()
{
	Employee joe;
	
return 0;	
}
