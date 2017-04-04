#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>  

/* ROULETTE GAME 3.0
The 3nd version
Keeping it simple. Type, Number, Alternative. 
Using pointers
Sting comparison. one Char

 *BY Donald Davis*/
//declaration of prototypes

void Rules();
float BetAmount();
void TypeBet(char *, int *, char *);
int Wheel();
float winningsCalculate(float inThePot,int numberBet,char secondaryTypeBet,int rolled);
//void build_array( char* strings[], size_t size );

int main() 
{
	bool pushingLuck=1; //a toggle for WHILE loop repeat playing
	float inThePot=0;	//money bet
	int rolled, numberBet;		//random number and number chosen
	char secondaryTypeBet,typeBet,again;					//the data being passed by refrence to the funcitons.
	float afterWinnings;	//after wining diffrence

	Rules();
	while (pushingLuck==1)
	{
		numberBet=0;
		inThePot=BetAmount(); //call the amount to bet
		TypeBet(&typeBet,&numberBet,&secondaryTypeBet);
		//test the pointers to be working.
		printf("the type bet: %c\n",typeBet);
		printf("the number: %d\n",numberBet);	
		printf("the secondary bet: %c\n",secondaryTypeBet);
		//BOOM BABY! :) yes... now im sure i could cut out some vaildating later.
	
	//the rest of it
		rolled = Wheel();	//the random generator function.
		printf("Range is 1-36\n\nAnd the lucky number is...\n	-----------\n	SPINNED: %d\n	-----------\n", rolled);	//drum roll number
		//input all data into funciton, to figure
		afterWinnings=afterWinnings+ (winningsCalculate(inThePot,numberBet,secondaryTypeBet,rolled));
		
		//all over, play again prompt
		if (afterWinnings>0)	//if you won money.
			{
			printf("After playing your total winnings is: $%.2f\n", afterWinnings);
			}
		else {
			printf("You are in the hole: $%.2f\n", afterWinnings);
			}
		printf("\n\nWant to play again?	\"Y\" for yes,	\"N\" for no\n");
		scanf("\n%c",&again);
		if (again=='y' || again == 'Y')
		{
			pushingLuck=true;  // already set as true... redundent
			//do nothing. keep runing the while loop. 
		}
		else		// not an "y(yes)"
		{
			pushingLuck=false;
			printf("Bye Bye, thanks for playing.\n");	
		}	
	}
return 0;
}

//1st function
void Rules()	//rules of betting
{
	printf("\nRules of the Game:\n1) Setting your bet is first, no take backs.");
	printf("\n2) You decide your chances and winnings; the harder to win, the larger the loot.\n");	
	printf("3) Types of Bets: \n	i.  Choose a number 1-36; winning payout is 36x times the betting.\n");
	printf("	ii.  Bet on an odd or even number; payout is 2 times the bet.\n");
	printf("	iii.  Bet on a dozen~first 1-12 OR 13-24 OR 25-36; payout is 3 times the bet.\n");
	printf("4) no whining.\n\n");
	//void, nothing to return.
}

//2nd function		ask the amount to bet
float BetAmount()
{
	float amountBetted;
	printf("============================================\n	How much are you willing to bet?\n");
	scanf("%f", &amountBetted);
	return amountBetted; //return the gambled cash
}

//3rd funciton 			prompt betting type, the number, or dozen or even/odd. return all 3, via refrence address pointers.
void TypeBet(char *typeBet, int *numberBet, char *secondaryTypeBet)
{
	//declare place holders for scanf to the pointer.
	char inputTypeBet, inputSecondaryTypeBet;
	int inputNumberBet;
	char evenOdd;
	bool vaild=false;
	char dozen;
	//the while loop for bet is running.
		while(vaild==false)
		{
			printf("Which type of bet chances are you chosing?\n\"N\" for Number	 \"E\" for Even	 \"O\" for Odd  \"D\" for Dozen\n");
			scanf("\n%c", &inputTypeBet);
			*typeBet = inputTypeBet;
		//	printf("testing value   %c\n", type);
			switch(*typeBet)
			{
				case 'N': case 'n':	//CASE for number, 1-36
					printf("You chose the NUMBER bet, probabitly winning= chance=2.667%%.\nChoose your number 1-36:\n");
					scanf("%d", &inputNumberBet);
					*numberBet=inputNumberBet;
					//check if the number is within allowed range.
					if(*numberBet>=1 && *numberBet<=36)
					{
						vaild=true;  //vaildation is correct input, end WHILE loop, and pass data.
						 // number
					}
					else
					{
						printf("	ERROR: number entered is not within the allowed betting range. (1-36).\n");
						vaild=false;		//valadation is wrong, reenter WHILE loop.
					}
					break;
					
						
				case 'E': case 'e':

						printf("You choose EVEN\n");
						vaild=true;		//vaildation is correct input, end WHILE loop, and pass data.
						*secondaryTypeBet = 'E';
					break;

				case 'O': case 'o':		
						printf("You choose ODD\n");
						vaild=true;		//vaildation is correct input, end WHILE loop, and pass data.
						*secondaryTypeBet = 'O';				
					break;
						
				case 'D': case 'd':
					printf("You chose the DOZEN bet, probability winning=33%%.\nChoose \"L\" for low(1-12)	\"M\" for middle(13-24)	\"H\" for high(25-36\n");
					scanf("\n%c",&dozen);
					*secondaryTypeBet=dozen;
					if(dozen=='L' || dozen== 'l')
					{
						printf("You choose LOW(1-12)\n");
						vaild=true;		//vaildation is correct input, end WHILE loop, and pass data.	
					}
					else if (dozen=='M' || dozen =='m')
					{
						printf("You choose MIDDLE(13-24)\n");
						vaild=true;		//vaildation is correct input, end WHILE loop, and pass data.
					}
					else if (dozen=='H' || dozen =='h')
					{
						printf("You choose HIGH(25-36)\n");
						vaild=true;		//vaildation is correct input, end WHILE loop, and pass data.	
					}
					else
					{
						printf("	ERROR, inccorect input.\n");
						vaild=false;		//valadation is wrong, reenter WHILE loop.
					}
					
					break;
					
				default:
					printf("\n	INVAILD INPUT! enter again.\n	-------------------------\n");
					vaild=false;		//valadation is wrong, reenter WHILE loop.
			}
	
		}
	
}

//random spining
int Wheel()
{
	int spin;
	int t;
	spin = 0;
	int x;
	
//	for(t=1;t<10;t++)
//	{//spinned = rand() % 35;	// try to wipe the odd 23 (22) first number
	srand(time(NULL));
	spin= rand() % 37;	//____________ random for 37 numbers, 0-36. mod of    0%37=0  2%37=2   37%37=0   38%37= 1  40%37=3  73%37=36    74%37=0  75%37=1
/*	while (spin!=36)

	{	
	spin= rand() % 37;
	printf("%d\n",spin);
	}
*/	

	return spin;
}



float winningsCalculate(float inThePot,int numberBet,char secondaryTypeBet,int rolled)
{
	int divisable;
	float winnings;
	if(numberBet!= 0)
	{
		if(numberBet==rolled) //THEY WON, rolled equals chosen number
		{
			winnings=inThePot*36;
			printf("Amount Betted: $%.2f\nWinnings: $%.2f\n", inThePot,winnings);
			printf("***************************\nYOU WON! THE JACKPOT!\nYOU ARE ONE LUCKY DOG!\n");
			
		}
		else
		{
			printf("Amount Betted: $%.2f\nLosings: $%.2f\nSorry, you've lost. Better luck next time.\n",inThePot,inThePot);
			winnings=-1.0*inThePot;
		}
	}
	switch(secondaryTypeBet)
	{
				{
		case 'l': case 'L':
			//low
			if(rolled>=1 && rolled<=12)
				{
					winnings=inThePot*3;
					printf("You guess within the correct DOZEN! \nCongradulations\nAmount Betted: $%.2f\nWinnings: $%.2f\n", inThePot,winnings);					
				}
			else
				{
					printf("Sorry, you've guessed the wrong DOZEN\n losings: $%.2f\nLosings: $%.2f\n Better luck next time.\n",inThePot,inThePot);
					winnings=-1.0*inThePot;
				}
			break;
			
		case 'm': case 'M':
			{//mid
			if(rolled>=13 && rolled<=24)
				{
					winnings=inThePot*3;
					printf("You guess within the correct DOZEN! \nCongradulations\nAmount Betted: $%.2f\nWinnings: $%.2f\n", inThePot,winnings);					
				}
			else
				{
					printf("Sorry, you've guessed the wrong DOZEN\n losings: $%.2f\nLosings: $%.2f\n Better luck next time.\n",inThePot,inThePot);
					winnings=-1.0*inThePot;
				}
			break;
			}
		case 'h': case 'H':
			//high
			if(rolled>=25 && rolled<=36)
				{
					winnings=inThePot*3;
					printf("You guess within the correct DOZEN! \nCongradulations\nAmount Betted: $%.2f\nWinnings: $%.2f\n", inThePot,winnings);					
				}
			else
				{
					winnings=-1.0*inThePot;
					printf("Sorry, you've guessed the wrong DOZEN\n losings: $%.2f\nLosings: $%.2f\n Better luck next time.\n",inThePot,inThePot);
				}
			break;		
		
		case 'E': case 'e':		
			divisable=rolled%2;	//find remainder of number.
			if (divisable==0)	//if no remainder of divisable 2... even.
			{
				winnings=inThePot*2;
				printf("It is EVEN! Congradulations\nAmount Betted: $%.2f\nWinnings: $%.2f\n", inThePot,winnings);
			}
			else	//if even was chosen, but not divisible mod 2, then landed odd, wrong choice.
			{
				printf("Amount Betted: $%.2f\nLosings: $%.2f\nSorry, you've lost. Better luck next time.\n",inThePot,inThePot);
				winnings=-1.0*inThePot;
			}
			break;	
		
		case 'O': case 'o':		
			divisable=rolled%2;	//find remainder of number.
			if (divisable==1)	//if there is one remainder, its odd.
			{
				winnings=inThePot*2;
				printf("It is ODD! Congradulations\nAmount Betted: $%.2f\nWinnings: $%.2f\n", inThePot,winnings);
			}
			else	//if even was chosen, but not divisible mod 2, then landed odd, wrong choice.
			{
				printf("Amount Betted: $%.2f\nLosings: $%.2f\nSorry, you've lost. Better luck next time.\n",inThePot,inThePot);
				winnings=-1.0*inThePot;
			}
			break;	
		
		}
	}
	
	
return winnings;
}
