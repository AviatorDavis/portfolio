#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
DONALD DAVIS
10/12/2016
Tic Tac Toe
Display a game between 2 users
using a 2 demensional ARRAY, String Comparison.
*/
//void createBoard3D();
void displayBoard3D(char board3D[3][3]);
void clearBoard3D(char board3D[3][3]);
void identifyBoard3D(char board3D[3][3]);
int selectLocation(char player);
bool setTurn(char player,int placement,char board3D[3][3],bool AI);
char checkForWin(char board3D[3][3]);
float aiDecision(char board3D[3][3]);
//float because computers are that percise

int main() 
{	//declaration
	//array 2D			 index 0        index 1        index 2
	char board3D[3][3]{{'0','1','2'},{'0','1','2'},{'0','1','2'}};
	int placement=0,randomSpot=0;	
	char player='X', playing='y', winner='n', again , aiActive='u',boardIdentified='y',aiSkill='E';
	bool inPlay=true, VaildPlacement=false, AI=false; 
	float aiPrediction;
	
	//show board numbers
	identifyBoard3D(board3D);
	displayBoard3D(board3D);//display the board every loop
	printf("\n");

//	clearBoard3D(board3D);	//clear the numbers
	//game is shown and contuine playing.
	while(inPlay)	
	{	//DO WHILE loop for vaild AI 
		
		while(aiActive!='Y' && aiActive != 'N' && aiActive != 'n' && aiActive != 'y')
		{	//do at least once
			printf("Would you like the Board Number Identified?   'Y'  'N'\n");
			scanf("\n%c",&boardIdentified);
//			boardIdentified='n';	//for testing faster
			if(boardIdentified=='Y' || boardIdentified =='y')	//only able to break WHILE loop with y or n
			{
				identifyBoard3D(board3D);
			}
			if(boardIdentified=='N' || boardIdentified =='n')
			{	
				clearBoard3D(board3D);
			}
			printf("\n Play against AI?  'Y'  'N'\n");	//ask agasnt ai
			scanf("\n%c",&aiActive);	//assign y or n
//			aiActive='y';	//for testing faster
			if(aiActive=='Y' || aiActive =='y')	//only able to break WHILE loop with y or n
			{
				AI=true;	//turn on AI
				printf("AI set true\n");
				
			}
			if(aiActive=='N' || aiActive =='n')
			{	
				AI=false;	//Dont use AI
				printf("AI set false\n");
				
			}
			printf("Select the difficulty of AI. EASY  OR  HARD   'E'  'H'\n");
			scanf("\n%c",&aiSkill);
//			boardIdentified='n';	//for testing faster
			if(aiSkill=='E' || aiSkill =='e')	//only able to break WHILE loop with y or n
			{
				aiSkill='E';
				printf("AI set EASY\n");
			}
			else
			{
				aiSkill='H';
				printf("AI set HARD\n");
			}
		}
	//	displayBoard3D(board3D);//display the board every loop
		
		VaildPlacement=false;
	//prompt input for location
		while(VaildPlacement==false)
		{	//prompt poistion	
			placement= selectLocation(player);
			//vaildate if the spot is taken.
			VaildPlacement=setTurn(player,placement,board3D,false);
			displayBoard3D(board3D);//display the board every loop
			printf("\n\n");

		}
		//change players
		while(AI==false)
			{
			if(player=='X')
			{
				player='O';
				break;
			}
			else
			{
				player='X';
				break;
			}
			break;
			}
		//if AI is ON, true, then take action
		
		while(AI)
			{	
				printf("<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>\n");
			//extra check, to see if defeat has occured before processing.
				winner = checkForWin(board3D);
				//short track out of AI
				if (winner=='x')	//x winner, x wins
					break;
				if (winner=='o')	//o winner, o wins
					break;
				if (winner=='c')	//c winner, cats game
					break;
				aiPrediction=aiDecision(board3D);
				printf("%f\n",aiPrediction);
						/*
						0. being index 0
						1. being index 1
						.1 being losing vertically
						.2 being losing horizotally
						.9 being wining vertically
						.8 being wining horizontal
						*/
	//top row, wining horizonatlly	0.0 - 0.2				
				if((aiPrediction>=0.777 && aiPrediction<=0.888)||(aiPrediction>=0.199 && aiPrediction<=0.222))	//moved both wining and losing actions same line
				{
					for(int S=7;S<=9;S++)	//try for placement in the top row.
					{			
						VaildPlacement=setTurn('O',S,board3D,AI);
					}
				}

	///middle row, wining horizontally		1.0 - 1.2	
				if((aiPrediction>=1.777 && aiPrediction<=1.888)||(aiPrediction>=1.199 && aiPrediction<=1.2222))
				{
					for(int S=4;S<=6;S++)	//try for placement in the middle row.
					{			
						VaildPlacement=setTurn('O',S,board3D,AI);
					}
				}

	///bot row, wining horizontally			2.0 - 2.2
				if((aiPrediction>=2.777 && aiPrediction<=2.888)||(aiPrediction>=2.199 && aiPrediction<=2.2222))
				{
					for(int S=1;S<=3;S++)	
					{			
						VaildPlacement=setTurn('O',S,board3D,AI);
					}
				}
 //wining horizonatlly		 	0.0  0.1  0.2	
				if((aiPrediction>=0.899 && aiPrediction<=0.999)||(aiPrediction>=0.099 && aiPrediction<=0.111))
				{		//try vertically placing.
					VaildPlacement=setTurn('O',1,board3D,AI);
					VaildPlacement=setTurn('O',4,board3D,AI);
					VaildPlacement=setTurn('O',7,board3D,AI);
				}

	//mid coloum, wining horizonatlly		1.0  1.1  1.2				
				if((aiPrediction>=1.899 && aiPrediction<=1.999)||(aiPrediction>=1.099 && aiPrediction<=1.111))
				{		//try vertically placing.
					VaildPlacement=setTurn('O',2,board3D,AI);
					VaildPlacement=setTurn('O',5,board3D,AI);
					VaildPlacement=setTurn('O',8,board3D,AI);
				}
	
	//right coloum, wining horizonatlly			2.0  2.1  2.2	
				if((aiPrediction>=2.899 && aiPrediction<=2.999)||(aiPrediction>=2.099 && aiPrediction<=2.111))
				{		//try vertically placing.
					VaildPlacement=setTurn('O',3,board3D,AI);
					VaildPlacement=setTurn('O',6,board3D,AI);
					VaildPlacement=setTurn('O',9,board3D,AI);
				}

	//digonaly chance. top-left, bot-right		7  5 3	
				if(aiPrediction>=0.32 && aiPrediction<=0.34)
				{
					VaildPlacement=setTurn('O',7,board3D,AI);
					VaildPlacement=setTurn('O',5,board3D,AI);
					VaildPlacement=setTurn('O',3,board3D,AI);
				}
	
	//digonaly chance. bot-left, topr-right, 1  5 9			
				if(aiPrediction>=0.43 && aiPrediction<=0.45)
				{
					VaildPlacement=setTurn('O',9,board3D,AI);
					VaildPlacement=setTurn('O',5,board3D,AI);
					VaildPlacement=setTurn('O',1,board3D,AI);
				}				
	//its not seeing anything. try CORNER BLOCK with MIDDLE,			
				if(aiPrediction>=-.1 && aiPrediction<=0.1)							//***there is no vicotry or losing next move, set up future plans.
				{
					if(aiSkill=='H')
					{	//ai on HARD					
						if(((board3D[2][0]=='X')||(board3D[0][0]=='X')||(board3D[0][2]=='X')||(board3D[2][2]=='X'))&&(VaildPlacement=setTurn('O',5,board3D,AI)))	//**if corners are taken. take middle IF middle is vaild placement.
						{	//	printf("1   if \n");
								VaildPlacement=setTurn('O',5,board3D,AI);
								printf("YOU ARE IN CORNER. WILL PICK MIDDLE FOR MULTIPLE SOLUTIONS.\n");							
						}																				
																															//*** check for corner spots, and mirror.
						else if((board3D[2][2]=='X')&&(board3D[0][0]=='X')&&(board3D[1][1]=='O'))		//if they are in the left and right corner while you are in the middle.
						{	//	printf("2  else if \n");
							VaildPlacement=setTurn('O',2,board3D,AI);
							printf("YOU ARE GETTING GREEDY. I'LL RACE YOUR TURNS.\n");
						}
						else if((board3D[0][2]=='X')&&(board3D[2][0]=='X')&&(board3D[1][1]=='O'))		//if they are in the left and right corner while you are in the middle.
						{	//	printf("3  else if \n");
							VaildPlacement=setTurn('O',8,board3D,AI);
							printf("YOU ARE GETTING GREEDY. I'LL RACE YOUR TURNS.\n");
						}
	//1 corner  PERFECTED START				
						else if(board3D[2][0]=='X')	//X is in bottom left
						{	//	printf("4  else if \n");
							if((board3D[2][0]=='X'&&board3D[1][2]=='X')&&(board3D[1][0]!='O'&&board3D[0][1]=='X'))	//whoa 1 6 8.. take priorty over 1 and 8   o!=4
							{
								if((board3D[0][0]!='X' && board3D[0][0]!='O'))	//take 7 
									{
										VaildPlacement=setTurn('O',7,board3D,AI);
										printf("SEEING 1  6  8. NO TRICK.\n");
									}
							}
							else if(board3D[2][0]=='X'&&board3D[0][1]=='X')	//if X is 1 and 8
							{
								if((board3D[1][0]!='X' && board3D[1][0]!='O') && board3D[1][2]!='X')	//take 4, closer between, thats X!=6
								{
									VaildPlacement=setTurn('O',4,board3D,AI);
									printf("YOU ARE IN CORNER. WILL PICK ADJACENT SPOT THATS NOT ACROSS X.\n");
								}
								else //4 is already taken
								{
									if(VaildPlacement=setTurn('O',3,board3D,AI))	//take 3 
									{
										VaildPlacement=setTurn('O',3,board3D,AI);
										printf("I FORSEE.\n");
									}
								}
							}
							else if(board3D[2][0]=='X'&&board3D[1][2]=='X')	//if X is 1 and 6
							{
								if((board3D[2][1]!='X' && board3D[2][1]!='O')&& board3D[0][1]!='X')	//take 2 closer between, thats x!=8
								{
									VaildPlacement=setTurn('O',2,board3D,AI);
									printf("YOU ARE IN CORNER. WILL PICK ADJACENT SPOT THATS NOT ACROSS X.\n");
								}
								else //2 is already taken
								{
									if((board3D[0][0]!='X' && board3D[0][0]!='O'))	//take 7 
									{
										VaildPlacement=setTurn('O',7,board3D,AI);
										printf("I FORSEE.\n");
									}
								}
							}
	
						}
	//corner 3    ?PERFECTED START 
						else if(board3D[2][2]=='X')	//X is in bottom right
						{	//	printf("6  else if \n");
							if((board3D[2][2]=='X'&&board3D[1][0]=='X')&&(board3D[1][2]!='O'&&board3D[0][1]=='X'))	// x is 3  8  4      O != 6
							{
								if((board3D[0][2]!='X' && board3D[0][2]!='O'))	//take 9 
								{
									VaildPlacement=setTurn('O',7,board3D,AI);
									printf("SEEING 3  4  8 . NO TRICK.\n");
								}			
							}
							else if(board3D[2][2]=='X'&&board3D[0][1]=='X')	//if X is 3 and 8
							{
								if((board3D[1][2]!='X' && board3D[1][2]!='O') && board3D[1][0]!='X')	//if 6 is empty, closer between, thats x!=4  
								{
									VaildPlacement=setTurn('O',6,board3D,AI);
									printf("YOU ARE IN CORNER. WILL PICK ADJACENT SPOT THATS NOT ACROSS X.\n");
								}
								else //6 is taken.
								{
									if(board3D[0][0]!='X' && board3D[0][0]!='O' && board3D[1][2]!='O')	//take 7 	okay(2 or 3 move)
									{
										VaildPlacement=setTurn('O',7,board3D,AI);
										printf("I FORSEE.\n");
									}
									else
									{
										VaildPlacement=setTurn('O',1,board3D,AI);
										printf("I FORSEE A SEEN.\n");
									}
								}
							}	
							else if(board3D[2][2]=='X'&&board3D[1][0]=='X')	//if X is 3 and 4... already checked 3 and 8
							{
								if((board3D[2][1]!='X' && board3D[2][1]!='O')&& board3D[0][1]!='X')	//take 2 closer between, thats x!=8
								{
									VaildPlacement=setTurn('O',2,board3D,AI);
									printf("YOU ARE IN CORNER. WILL PICK ADJACENT SPOT THATS NOT ACROSS X.\n");
								}
								else //2 is already taken
								{
									if(board3D[0][2]!='X' && board3D[0][2]!='O')	//take 9	(2 or 3 move)
									{
										VaildPlacement=setTurn('O',9,board3D,AI);
										printf("I FORSEE.\n");
									}
								}
							}
		
						}
	//corner 9	PERFECTED	START			
						else if(board3D[0][2]=='X')	//X is in top right
						{	//	printf(	"7  else if \n");
							if((board3D[0][2]=='X'&&board3D[2][1]=='X')&&(board3D[0][1]!='O'&&board3D[1][0]=='X'))	//x is 9 2  4   and 0 != 8
							{
								if(board3D[2][2]!='X' && board3D[2][2]!='O')	//take 7
									{
										VaildPlacement=setTurn('O',7,board3D,AI);
										printf("SEEING 2  4  9. NO TRICK.\n");
									}
							}
							else if(board3D[0][2]=='X'&&board3D[2][1]=='X')	//if X is 9 and 2
							{
								if((board3D[1][2]!='X' && board3D[1][2]!='O') && board3D[1][0]!='X')	//take 6, closer between, thats x!=4
								{
									VaildPlacement=setTurn('O',6,board3D,AI);
									printf("YOU ARE IN CORNER. WILL PICK ADJACENT SPOT THATS NOT ACROSS X.\n");
								}
								else//6 is already taken
								{
									if(board3D[0][0]!='X' && board3D[0][0]!='O' && board3D[0][1]!='O')	//take 7  if  8 is not 0
									{
										VaildPlacement=setTurn('O',7,board3D,AI);
										printf("I FORSEE.\n");
									}
									else
									{
										VaildPlacement=setTurn('O',3,board3D,AI);
										printf("I FORSEE A SEEN.\n");
									}
								}
							}
							
							else if(board3D[0][2]=='X'&&board3D[1][0]=='X')	//if X is 9 and 4
							{
								if((board3D[0][1]!='X' && board3D[0][1]!='O')&& board3D[2][1]!='X')	//take 8 closer between , thats X!=2
								{
									VaildPlacement=setTurn('O',8,board3D,AI);
									printf("YOU ARE IN CORNER. WILL PICK ADJACENT SPOT THATS NOT ACROSS X.\n");
								}
								else //8 is already taken
								{
									if(board3D[2][2]!='X' && board3D[2][2]!='O')	//take 3
									{
										VaildPlacement=setTurn('O',3,board3D,AI);
										printf("I FORSEE.\n");
									}
								}
							}
							else
							{
								VaildPlacement=setTurn('O',3,board3D,AI);
									printf("I FIND MYSELF QUESTIONING THE ACTIONS OF HUMAN THINKING.\n");
							}	
	
						}
	//corner 7	PERFECTTED	 START	
						else if(board3D[0][0]=='X')	//X is in top left
						{	//	printf("8  else if \n");
							//whoa they have deadly 3... cut infront of 7 and 2 requirments
							if((board3D[0][0]=='X'&&board3D[1][2]=='X') && (board3D[1][0]!='O'&&board3D[2][1]=='X'))	//if x is 7 2 and 6   and o!=4
							{
								if(board3D[0][2]!='X' && board3D[0][2]!='O')	//take 1
									{
										VaildPlacement=setTurn('O',1,board3D,AI);
										printf("SEEING 7  2  6. DONT TRICK\n");
									}
							}
							else if(board3D[0][0]=='X'&&board3D[2][1]=='X')	//if X is 7 and 2
							{
								if((board3D[1][0]!='X' && board3D[1][0]!='O')&& board3D[1][2]!='X')	//take 4, closer between, thats X!= 6
								{
									VaildPlacement=setTurn('O',4,board3D,AI);
									printf("YOU ARE IN CORNER. WILL PICK ADJACENT SPOT THATS NOT ACROSS X.\n");
								}
								else //4 is already taken
								{
									if(board3D[0][2]!='X' && board3D[0][2]!='O')	//take 9
									{
										VaildPlacement=setTurn('O',9,board3D,AI);
										printf("I FORSEE.\n");
									}
								}
							}	
							else if(board3D[0][0]=='X'&&board3D[1][2]=='X')	//if X is 7 and 6
							{
								if((board3D[0][1]!='X' && board3D[0][1]!='O')&& board3D[2][1]!='X')	//take 8 closer between, that s!=2
								{
									VaildPlacement=setTurn('O',8,board3D,AI);
									printf("YOU ARE IN CORNER. WILL PICK ADJACENT SPOT THATS NOT ACROSS X.\n");
								}
								else //8 is already taken
								{
									if(board3D[0][2]!='X' && board3D[0][2]!='O')	//take 1
									{
										VaildPlacement=setTurn('O',1,board3D,AI);
										printf("I FORSEE.\n");
									}
								}
							}
	
						}
						//if they are on a side, and middle is open, take it.			8					4						2					6
						else if((board3D[1][1]!='X' && board3D[1][1]!='O')&&((board3D[0][1]=='X')||(board3D[1][0]=='X')||(board3D[2][1]=='X')||(board3D[1][2]=='X')))
						{	//printf("8  else if \n");
							VaildPlacement=setTurn('O',5,board3D,AI);
							printf("FOUND MIDDLE OPEN. TAKE AND BLOCK SIDES\n");
						}
						
						else if(VaildPlacement=setTurn('O',1,board3D,AI))								//***no corner spots to mirror. preceed with taking cornner
						{	//printf("9  else if \n");
							VaildPlacement=setTurn('O',1,board3D,AI);
							printf("FOUND BOTTOM-LEFT SPOT OPEN. WILL TAKE CORNER.\n");
						}
						else if(VaildPlacement=setTurn('O',7,board3D,AI))
						{	//printf("10  else if \n");
							VaildPlacement=setTurn('O',7,board3D,AI);
							printf("FOUND TOP-LEFT SPOT OPEN. WILL TAKE CORNER.\n");
						}				
						else if(VaildPlacement=setTurn('O',9,board3D,AI))
						{	//printf("11  else if \n");
							VaildPlacement=setTurn('O',9,board3D,AI);
							printf("FOUND TOP-RIGHT SPOT OPEN. WILL TAKE CORNER.\n");
						}
						else if(VaildPlacement=setTurn('O',3,board3D,AI))
						{	//printf("12  else if \n");
							VaildPlacement=setTurn('O',3,board3D,AI);
							printf("FOUND BOTTOM-RIGHT SPOT OPEN. WILL TAKE CORNER.\n");
						}
					}//end of HARD selection
					
					if(aiSkill=='E')
					{	//AI easy path
						printf("EASY AI\n");
						srand(time(NULL));	//random number
						randomSpot= (rand() % 9) + 1;	//random 0-8, then add one.
						while(1)
						{	//if the SETTURN function returns false, than the vaild is not true, fail condtion to place and do ELSE
							if(VaildPlacement=setTurn('O',randomSpot,board3D,AI))
							{
								//it was a TRUE, vaild placement. break out of loop
								printf("Chose Randomly.\n");
								break;
							}
							else	//the IF didnt work, randomise number again, and send message. WHILE loop
							{
								while(1)
								{	//looping to not have the same number checked
									int failedPlacement;
									failedPlacement=randomSpot;
									srand(time(NULL));	//random number
									randomSpot= (rand() % 9) + 1;	//random 0-8, then add one.
									if(randomSpot==failedPlacement)
									{
										//printf("randomly chose same postion again. add 1 and try\n");			//WORKED, saw printed, dont show USER
										randomSpot=failedPlacement+1;
										if(VaildPlacement=setTurn('O',randomSpot,board3D,AI))
											break;
									}
									else	
									{	
										//printf("the adding one still didnt work. run again.\n"); 			//WORKED, saw printed, dont show USER
										//the random doesnt equal run again.
									
									}	
							}
							break;
							}
						}
					
					
					}
					
				}
			//processing back on track to 0.0, open eyes to new things.	
			aiPrediction=0.0;	
			printf("I HAVE MOVED\n<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>\n\n");
			displayBoard3D(board3D);//display the board every loop
			break;
			}
		
		//check for a winner
		winner = checkForWin(board3D);
		if (winner=='n')
			inPlay=true;
		if (winner=='x')	//x winner, x wins
		{
			printf("*************\n  X  WINS!!!*\n*************\n");
			inPlay=false;
		}
		if (winner=='o')	//o winner, o wins
		{
			printf("*************\n  O  WINS!!!*\n*************\n");
			inPlay=false;
		}
		if (winner=='c')	//c winner, cats game
		{
			printf("CAT GAME, EVERYONE IS A LOSER. (lame game right, 2 easy? NeverDye)\n");
			inPlay=false;
		}
	if(winner!='n')	//if there is an out come that wasnt the start
	{
		do{	//do at least once
			printf("\n WOULD YOU LIKE TO PLAY AGAIN?  'Y'  'N'\n");
			scanf("\n%c",&again);	//assign y or n
			if(again=='Y' || again =='y')	//only able to break WHILE loop with y or n
			{
				inPlay=true;	//play agian
				identifyBoard3D(board3D);	//clear board
				aiActive='u';
				break;
			}
			if(again=='N' || again =='n')
			{	
				inPlay=false;
				break;
			}
		}while(1);
	}
	}
	
		
return 0;	
}

// function to show the board. 
void displayBoard3D(char board3D[3][3])
{
	//displaying 2D ARRAY with FOR loop in FOR loop
//	for(int i=0;i<3;i++)	//3 loops
//	{//select the index
//			for(int s=0;s<3;s++)	//advance index subscript  3 times
//			{
//				printf("%c ",board3D[i][s]);
//			}
		printf("\n   %c | %c | %c \n  ~~~+~~~+~~~\n",board3D[0][0],board3D[0][1],board3D[0][2]);
		printf("   %c | %c | %c   \n  ~~~+~~~+~~~\n",board3D[1][0],board3D[1][1],board3D[1][2]);
		printf("   %c | %c | %c   \n",board3D[2][0],board3D[2][1],board3D[2][2]);
//	}
}
//funciton to clear board to empty slots
void clearBoard3D(char board3D[3][3])
{
		//clear data
	for(int i=0;i<3;i++)	//3 loops
	{//select the index
		for(int s=0;s<3;s++)	//advance index subscript  3 times
		{
			board3D[i][s]=' ';	//make index subscript '<space char>'
		}
	}
	
}
//fuction to identify spots
void identifyBoard3D(char board3D[3][3])
{
	//input numbering space indentifier
	char n;
	int num=1;
//	for(int i=0;i<3;i++) 	//3 loops counting down
	for(int i=2;i>=0;i--)	//3 loops counting up(num pad)
		{//select the index
			for(int s=0;s<3;s++)	//advance index subscript  3 times
			{	n=num+'0';
				board3D[i][s]=n;	//make index subscript 'number'
				num++;
			}
		}

}

//function for prompting user input number
int selectLocation(char player)
{
	int choose;
	while(1)
	{	
	printf("\nPlayer: %c  enter your desired position from range '1'-'9'\n",player);
	scanf("\n%d",&choose);
	if(choose>=1 && choose<=9)
		break;
	printf("Incorrect selection, input again.\n");
	
	}
	return choose;
}
//function to vaild and place prompted input into the given slot
bool setTurn(char player,int placement,char board3D[3][3],bool AI)
{
	bool vaildPlacement=false;
	if(AI==false)
	{
		switch(placement)
		{	//if position was int
			case 7:		//top-left
				if (board3D[0][0] != 'X' && board3D[0][0] != 'O')
				{	//if it wasnt taken by a player
					board3D[0][0]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					printf("Position %d is already taken by %c.\n",placement,board3D[0][0]);
					break;
				}
			case 8:		//top-mid
				if (board3D[0][1] != 'X' && board3D[0][1] != 'O')
				{
					board3D[0][1]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					printf("Position %d is already taken by %c.\n",placement,board3D[0][1]);
					break;
				}
			case 9:	//top-right
				if (board3D[0][2] != 'X' && board3D[0][2] != 'O')
				{
					board3D[0][2]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					printf("Position %d is already taken by %c.\n",placement,board3D[0][2]=player);
					break;
				}
			case 4:	//midleft
				if (board3D[1][0] != 'X' && board3D[1][0] != 'O')
				{
					board3D[1][0]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					printf("Position %d is already taken by %c.\n",placement,board3D[1][0]);
					break;
				}
			case 5:	//mid-mid
				if (board3D[1][1] != 'X' && board3D[1][1] != 'O')
				{
					board3D[1][1]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					printf("Position %d is already taken by %c.\n",placement,board3D[1][1]);
					break;
				}
			case 6:	//mid right
				if (board3D[1][2] != 'X' && board3D[1][2] != 'O')
				{
					board3D[1][2]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					printf("Position %d is already taken by %c.\n",placement,board3D[1][2]);
					break;
				}
			case 1:	//bot left
				if (board3D[2][0] != 'X' && board3D[2][0] != 'O')
				{
					board3D[2][0]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					printf("Position %d is already taken by %c.\n",placement,board3D[2][0]);
					break;
				}
			case 2: //bot mid
				if (board3D[2][1] != 'X' && board3D[2][1] != 'O')
				{
					board3D[2][1]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					printf("Position %d is already taken by %c.\n",placement,board3D[2][1]);
					break;
				}
			case 3:	//botom right
				if (board3D[2][2] != 'X' && board3D[2][2] != 'O')
				{
					board3D[2][2]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					printf("Position %d is already taken by %c.\n",placement,board3D[2][2]);
					break;
				}			
			default:
				printf("The spots are taken.\n");
				vaildPlacement=false;
		}
	}
//IF AI is true, this is their move	
	if(AI)	//removed all notifications of invaild placement. contuine to try, until placed.
	{
		switch(placement)
		{	//if position was int
			case 7:		//top-left
				if (board3D[0][0] != 'X' && board3D[0][0] != 'O')
				{	//if it wasnt taken by a player
					board3D[0][0]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					break;
				}
			case 8:		//top-mid
				if (board3D[0][1] != 'X' && board3D[0][1] != 'O')
				{
					board3D[0][1]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					break;
				}
			case 9:	//top-right
				if (board3D[0][2] != 'X' && board3D[0][2] != 'O')
				{
					board3D[0][2]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					break;
				}
			case 4:	//midleft
				if (board3D[1][0] != 'X' && board3D[1][0] != 'O')
				{
					board3D[1][0]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					break;
				}
			case 5:	//mid-mid
				if (board3D[1][1] != 'X' && board3D[1][1] != 'O')
				{
					board3D[1][1]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					break;
				}
			case 6:	//mid right
				if (board3D[1][2] != 'X' && board3D[1][2] != 'O')
				{
					board3D[1][2]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					break;
				}
			case 1:	//bot left
				if (board3D[2][0] != 'X' && board3D[2][0] != 'O')
				{
					board3D[2][0]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					break;
				}
			case 2: //bot mid
				if (board3D[2][1] != 'X' && board3D[2][1] != 'O')
				{
					board3D[2][1]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					break;
				}
			case 3:	//botom right
				if (board3D[2][2] != 'X' && board3D[2][2] != 'O')
				{
					board3D[2][2]=player;
					vaildPlacement=true;
					break;
				}
				else
				{
					break;
				}			
			default:
				vaildPlacement=false;
		}
	}
	return vaildPlacement;
}

//funciton to check after placement, if the game would be ended in victory or truce.
char checkForWin(char board3D[3][3])
{
	char winner = 'n';	//return 'n' winner
	int counterX=0;
	int counterO=0;
	//check FOR loop for horizontal winner.
	for(int i=0;i<3;i++)	//3 loops
		{//select the index
			counterX=0;	//move one index, set counter to 0
			counterO=0;
			for(int s=0;s<3;s++)	//advance index subscript  3 times
			{
				if(board3D[i][s]=='X')
				{	//X has passed a step
					counterX++;
				}	//make index subscript '<space char>'
				if(board3D[i][s]=='O')
				{	//X has passed a step
					counterO++;
				}	//make index subscript '<space char>'
			
			}
			if(counterX==3)
			{	//if the count 3 in an index is true, return X winner
				winner='x';
			//	printf("the counterX is 3 horozintally using IndexSub counts.\n");
				return winner;
			}
			if(counterO==3)
			{	//if the count 3 in an index is true, return Y winner.
				winner='o';		
			//	printf("the counterO is 3 horozintally using IndexSub counts.\n");	
				return winner;
			}
		}
//reset counters, check FOR loop with Vertically
	counterX=0;
	counterO=0;
	for(int s=0;s<3;s++)	//3 loops
		{//select the SubIndex
			counterX=0;	//move the SubIndex, set counter to 0
			counterO=0;
			for(int i=0;i<3;i++)	//advance index  3 times
			{
				if(board3D[i][s]=='X')
				{	//X has passed a step
					counterX++;
				}	//make index subscript '<space char>'
				if(board3D[i][s]=='O')
				{	//X has passed a step
					counterO++;
				}	//make index subscript '<space char>'	
			}
			if(counterX==3)
			{	//if the count 3 in an index is true, return X winner
				winner='x';
			//	printf("the counterX is 3 vertically using Index counts.\n");
				return winner;
			}
			if(counterO==3)
			{	//if the count 3 in an index is true, return Y winner.
				winner='o';
			//	printf("the counterO is 3 vertically using Index counts.\n");		
				return winner;
			}
		}
	//FOR loop for checking Diagnally square cordinates
	counterX=0;	//reset counters
	counterO=0;
	for(int p=0;p<3;p++)
	{
		if(board3D[p][p]=='X') //if poistion diagnally X topleft to botright
			counterX++;
 		if(board3D[p][p]=='O') //if poistion diagnally O topleft to botright
			counterO++;
		if(counterX==3)
		{
			winner='x';
		//	printf("counterX is 3 diagonally top-left, mid-mid, bot-right.\n");		
			return winner;
		}
		if(counterO==3)
		{	//if the count 3 in an index is true, return Y winner.
			winner='o';
			//printf("counterO is 3 diagonally top-left, mid-mid, bot-right.\n");		
			return winner;
		}
	}
	//check diagonally
	if(board3D[2][0]=='X' && board3D[1][1]=='X' && board3D[0][2]== 'X')
	{//X has diagnaolly win botleft to topright
		winner='x';
		//printf("X has 3 diagonally bot-left, to top-right.\n");
		return winner;
	}
	if(board3D[2][0]=='O' && board3D[1][1]=='O' && board3D[0][2]== 'O')
	{//O has diagnaolly win botleft to topright
		winner='o';
		//printf("O has 3 diagonally bot-left, to top-right.\n");
		return winner;
	}
	
	int counterCat=0;
	//check for CAT GAME, all spots filled.
	for(int i=0;i<3;i++)	//3 loops
	{//select the index
	//reset counterCat
		for(int s=0;s<3;s++)	//advance index subscript  3 times
		{
			if(board3D[i][s]=='O' || board3D[i][s]=='X')	//check every slot for X OR Y
			{
				counterCat++;
			}
		}
		if(counterCat==9)
		{				
			winner='c';
			return winner;
		}
	}
	
//return the pre defined 'n', because it passed all returns in conditions.
return winner;
}


//function for AI moves
float aiDecision(char board3D[3][3])
{
	int XPlayerDanger=0;
	int XPlayerTermination=0;
	int counterX=0;
	int counterO=0;
	//check FOR loop for horizontal winner.
	for(int i=0;i<3;i++)	//3 loops		//scan ALL of it for winning.
	{//select the index
		counterX=0;	//move one index, set counter to 0
		counterO=0;
		for(int s=0;s<3;s++)	//advance index subscript  3 times
		{
			if(board3D[i][s]=='X')
			{	//X has passed a step
				counterX++;
			}	
			if(board3D[i][s]=='O')
			{	//X has passed a step
				counterO++;
			}	
		}
		if(counterO + counterX ==3)
		{	//the horizontal row is full
			counterO=0;	//its all full, skip the calculations of input
			counterX=0;				
		}
		if(counterO==2)
		{	//Close to wining
			XPlayerTermination=i;	//close to crushing human.
			printf("YOU ARE TERMINATED\n");	
			return (0.8 + XPlayerTermination);	// .8 being wining horizontal
		}
	}
	for(int i=0;i<3;i++)	//3 loops		//scan ALL of it for losing
	{//select the index
		counterX=0;	//move one index, set counter to 0
		counterO=0;
		for(int s=0;s<3;s++)	//advance index subscript  3 times
		{
			if(board3D[i][s]=='X')
			{	//X has passed a step
				counterX++;
			}	
			if(board3D[i][s]=='O')
			{	//X has passed a step
				counterO++;
			}	
		
		}
		if(counterO + counterX ==3)
		{	//the horizontal row is full
			counterO=0;	//its all full, skip the calculations of input
			counterX=0;				
		}
		if(counterX==2)//player is close to winning, stop it
		{	//must be crushed. in index.
			XPlayerDanger=i;	//set the index as the known imment defeat row horizontal.
			printf("I SEE IMMINENT DEFEAT, MUST REACT\n");
			return (0.2 + XPlayerDanger);	// .2 being losing horizontal
		}
	}
//reset counters, check FOR loop with Vertically winning
	for(int s=0;s<3;s++)	//3 loops
	{//select the SubIndex
		counterX=0;	//move the SubIndex, set counter to 0
		counterO=0;
		for(int i=0;i<3;i++)	//advance index  3 times
		{
			if(board3D[i][s]=='X')
			{	//X has passed a step
				counterX++;
			}	//make index subscript '<space char>'
			if(board3D[i][s]=='O')
			{	//X has passed a step
				counterO++;
			}	//make index subscript '<space char>'	
		}
		if(counterO + counterX ==3)
		{	//the vertical row is full
			counterO=0;	//its all full, skip the calculations of input
			counterX=0;				
		}
		if(counterO==2)
		{	//Close to wining
			XPlayerTermination=s;	//close to crushing human.
			printf("YOU ARE TERMINATED\n");	
			return (0.9 + XPlayerTermination);	// .9 being wining vertically
		}
	}
//check vertically for losing
	for(int s=0;s<3;s++)	//3 loops
	{//select the SubIndex
		counterX=0;	//move the SubIndex, set counter to 0
		counterO=0;
		for(int i=0;i<3;i++)	//advance index  3 times
		{
			if(board3D[i][s]=='X')
			{	//X has passed a step
				counterX++;
			}	//make index subscript '<space char>'
			if(board3D[i][s]=='O')
			{	//X has passed a step
				counterO++;
			}	//make index subscript '<space char>'	
		}
		if(counterO + counterX ==3)
		{	//the vertical row is full
			counterO=0;	//its all full, skip the calculations of input
			counterX=0;				
		}
		if(counterX==2)
		{	//if the count 3 in an index is true, return X winner
			XPlayerDanger=s;	//set the index as the known imment defeat row verticaly.
			printf("I SEE IMMINENT DEFEAT, MUST REACT\n");
			return (0.1 + XPlayerDanger);	// .1 being losing verticaly
		}
	}
//checking for diagonal		7  5  3
	//FOR loop for checking Diagnally square cordinates
	counterX=0;	//reset counters
	counterO=0;
	for(int p=0;p<3;p++)
	{
		if(board3D[p][p]=='X') //if poistion diagnally X topleft to botright
			counterX++;
 		if(board3D[p][p]=='O') //if poistion diagnally O topleft to botright
			counterO++;
		if(counterO + counterX ==3)
		{	//the digonally square cordinates are full
			counterX=0;	//its all full, skip the calculations of input
			counterO=0;				
		}
		if(counterO==2)
		{	//Close to wining	//close to crushing human.
			printf("YOU ARE TERMINATED\n");	
			return 0.333;	// .33 being wining vdigonaly top-left to bot-right
		}
		if(counterX==2)
		{	
			printf("I SEE IMMINENT DEFEAT, MUST REACT\n");
			return 0.333;	// .33 being losing digonaly top-left to bot-right
		}		
	}
	//-----------------------------------------------------------------
	//check diagonally top-right, bot-left 1  5 9
	counterX=0;	//reset counters
	counterO=0;
	if(board3D[2][0]=='X')
		counterX++;
	if(board3D[1][1]=='X')
		counterX++;
	if(board3D[0][2]== 'X')
		counterX++;
	if(board3D[2][0]=='O')
		counterO++;
	if(board3D[1][1]=='O')
		counterO++;
	if(board3D[0][2]== 'O')
		counterO++;
	//check for how many
	if(counterO + counterX ==3)
	{	//the digonally square cordinates are full
		counterO=0;	//its all full, skip the calculations of input
		counterX=0;	
	}
	if(counterO==2)
	{	//Close to wining
	//close to crushing human.
		printf("YOU ARE TERMINATED\n");	
		return 0.444;	// .77 being wining vdigonaly top-right, bot-left 1  5 9
	}	
	if(counterX==2)
	{	
		printf("I SEE IMMINENT DEFEAT, MUST REACT\n");
		return 0.444;	// .77 being losing digonaly   top-right, bot-left 1  5 9
	}
			
	printf("DID NOT FIND DANGER OR VICTORY\n");
	//FOR loop for checking Diagnally square cordinates
return 0;	
}



