/*1/19/17, homework lottery game
user inputs 3 values, gernerate random 3 numbers. 
compare numbers, find equal matches, duplicates count, but 1:1 ratio.
in order is worth the most.
--used functions and a parallel array for comparing and marking. integers with boolean cross refrence arrays.
Donald Davis
*/
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
using namespace std;
void getInput(int guess[], int lottery[], int& DIGITS, bool& prompt, bool& vaildNum);
void display(int guess[], int lottery[], int& DIGITS);
void calc(int guess[], int lottery[], bool lotteryMarked[], bool guessMarked[], int& DIGITS, int& matches, int& order);
void winnings(int matches, int order);

int main()
{
//declare
	int DIGITS=3;
	int guess[DIGITS]={88,88,88}, lottery[DIGITS]={99,99,99}, counted=0, matches=0,	order=0;
	bool guessMarked[DIGITS]={false,false,false}, lotteryMarked[DIGITS]={false,false,false};		//tracker for guess	//tracker for lottery
	bool vaildNum=true, prompt=true;
	string play="yes";
	
//prime lottery generator0
	unsigned int seed= time(0);
	srand(seed);
	
	while(play=="yes")
	{
	//reset values for replaying
		prompt=true;
		vaildNum=true;
		for(bool &x : guessMarked){	//reset guess false
			x= false;}
		for(bool &x : lotteryMarked){	//reset lottery false, with short had ref
			x= false;}
/*		for(int &x : guess){			//reset guess nums	not really nessecary, it will be replaced
			x= 88;}
		for(int &x : lottery){			//reset lottery nums.
			x= 99;}
*/
		counted=0;
		matches=0;
		order=0;
	
	//FUNCTION CALL, prompt for input 
		getInput(guess,lottery, DIGITS, prompt, vaildNum);
	//for testing*************************************
	//	lottery[0]=1;
	//	lottery[1]=2;
	//	lottery[2]=3;
	//tesing*****************************************
		
		//if they have followed the rules, contuine process, or else, skip process.
		if(vaildNum)
		{
		//FUNCTION CALL, DISPLAY inputs and random
			display(guess, lottery, DIGITS);
			
		//FUNCTION CALL, calculate the matches.
			calc(guess, lottery, lotteryMarked, guessMarked, DIGITS, matches, order);
			
		//FUNCTION CALL, to display Winnings.
			winnings(matches,order);
			
		}//end of succesful game	
	//ask to play again.
		do
		{
			cin.ignore();
			cout<<"\n\n\tDo you want to play again?\t'yes'...'no'";
			getline(cin,play);
		}while(play!="yes" && play!="no");
	} //end of play loop

return 0;
}

//-------------------------------------------------------------------------------------
//FUNCTION definition: enter user inputs, check within bounds, and gen random
void getInput(int guess[], int lottery[], int& DIGITS, bool& prompt, bool& vaildNum)
{
//prompt user for numbers
	while(prompt)
	{
		vaildNum=true;	//toggle to true, before asking
		for(int x=0;x<DIGITS;x++)
		{
			// ask for number.
			cout<<"\nEnter input for number "<<x+1<<":";
			cin>>guess[x];
		//rand number gen for each digit while cycling for input.
		//				  (max-min+1)+min)
			lottery[x]=(rand()%(9 - 0 + 1) + 0);
			//test input
			if(!(guess[x]>=0 && guess[x]<=9))
			{	//the input is NOT between 0-9
				cout<<"\n\t*INVAILD INPUT*\n";
				x=9999; //break out of forloop.
				vaildNum=false;
			}
		}
		if(vaildNum==true)	//if inputs were vaild
			prompt=false;	// break out of loop, prompting
		}
}

//-------------------------------------------------------------------------------------
//Function Defintion: display the recently entered inputs and the lottery numbers
void display(int guess[], int lottery[], int& DIGITS)
{	
//dipslay guess
	cout<<"\nGuess:   ";
	//for(int x : guess)
	for(int x =0; x<DIGITS; x++){
		cout<<guess[x]<<" ";
	}
//display the random numbers
	cout<<"\nLottery: ";
	//for(int x : lottery)
	for(int x =0; x<DIGITS; x++){
		cout<<lottery[x]<<" ";
	}
}

//-------------------------------------------------------------------------------------
//FUNCITON defintion: calculate if the GUESS digit matches LOTTERY digit, and if it was in ORDER
void calc(int guess[], int lottery[], bool lotteryMarked[], bool guessMarked[], int& DIGITS, int& matches, int& order)
{
	//if EXACT ORDER, than they are correct, skip the calculations.
		for(int x=0;x<DIGITS;x++)
		{
			if(guess[x]==lottery[x])
				order++;	//the exact spots match
		}
	
	//IF the order was not exactly even with amount of DIGITS... then calculate exact matches
	if(order!=DIGITS)
	{
		//test for matches x equals guess	
		for(int x=0;x<DIGITS;x++)
		{
//*		cout<<"\nEntered loop x:"<<x;
			//y equals lottery
			for(int y=0;y<DIGITS;y++)
			{
//*			cout<<"\nEntered loop y:"<<y;
				//while these parallel arrays of slots are FALSE..or not checked... contuine checking through arrays
				if(guessMarked[x]==false && lotteryMarked[y]==false)
				{
//*			cout<<"\nPassed checker guessMarked/guess:"<<x<<"==false     lotteryMarked/lottery:"<<y<<"==false  ";
					if(guess[x]==lottery[y])
					{
						matches++;	//found a match counter
						lotteryMarked[y] = true;	//Matched slot Y of lottery, check
						guessMarked[x]	= true;		//Matched slot X of Guess, check
//*					cout<<"\nMatched slot "<<x+1<<" of Guess Numbers";
//*					cout<<"\nMatched slot "<<y+1<<" of lottery Numbers";	
//*					cout<<"\nGuess:"<<guess[x]<<" matches lottery:"<< lottery[y];
//*					cout<<"\nIn place "<< x+1<< " and place "<< y+1;
					}
				}
			}
		}
	}
//*		cout<<"\nMatches:"<<matches;
		//check for exact order
}

//-------------------------------------------------------------------------------------
//FUNCTION Definition: Display their winings based on MATCHES or ORDER correct
void winnings(int matches, int order)
{	
	if(order==3)	//if they matched exact spot of all 3.
	{
		cout<<"\nJACKPOT: You have matched all identical numbers in EXACT ORDER!\n****You have won $100,000.00****";		
	}
//display winnings based on matches.
	else if(matches==3)
		cout<<"\nYou have matched all numbers correctly!\n****You have won $1000.00****";
	else if(matches==2)
		cout<<"\nYou have matched 2 numbers correctly!\n****You have won $100.00****";
	else if(matches==1)
		cout<<"\nYou have matched 1 number correctly!\n****You have won $10.00****";
	else
		cout<<"\nSorry, you have guessed all the wrong numbers in any possible order...\n----You lost----";
}
