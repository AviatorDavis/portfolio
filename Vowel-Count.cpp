#include <stdio.h>
#include <stdlib.h>
/*
DONALD DAVIS
10/17/2016
Vowel Count Stings


*/
void countStringVowels(char inputString[30],int numberVowels[5],int *);

int main()
{
	char inputString[50];
	int numberVowels[5]={0,0,0,0,0};
	char vowelLetters[5]={'A','E','I','O','U'};
	printf("Enter A line of string.\n");
	int totalVowels=0;
//	scanf("%s", inputString);
	gets(inputString);
	
		//FUNCTION to count vowels one CHAR at time, and sending POINTER for modifiying INT TOTAlVOWELS outside FUNCTION,
	countStringVowels(inputString,numberVowels,&totalVowels);
	
	printf("\n");

	//print FOR loop
	for(int i=0;i<5;i++)
	{	
		if(i==0)
		{	//for A, print total next
			printf("\nTotal\t%c's:  '%p\n", vowelLetters[i],&numberVowels[i]);
		}
		else
		{	//print rest tabbed after line
			printf("\t%c's:  '%p\n", vowelLetters[i],&numberVowels[i]);
		}
		
	}	//total counted inside of FUNCTION
	printf("\nTotal vowels: %d\n", totalVowels);	

	
return 0;
}



void countStringVowels(char *inputString,int *numberVowels,int *totalVowels)
{
	int i=0;
	*totalVowels=0;
	while (*inputString)
	{
		switch(*inputString++)
		{
			case 'A': case 'a':
				numberVowels[0]++;
				*totalVowels++;	
				break;
				
			case 'E': case 'e':
				*(numberVowels+1)+=1;	//use pointer to memory location, plus 1 over.
				*totalVowels+=1;
				break;
				
			case 'I': case 'i':
				numberVowels[2]++;
				*totalVowels+=1;
				break;
				
			case 'O': case 'o':
				numberVowels[3]++;
				*totalVowels+=1;
				break;
				
			case 'U': case 'u':
				numberVowels[4]++;
				*totalVowels+=1;
				break;
		}
	i++;

	
	}
	
}
