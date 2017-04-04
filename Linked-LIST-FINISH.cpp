#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>


/*
DONALD DAVIS
11/2/2016
Linked List Project
a menu of choices for the user. Consits of allocating free memory. mantain numerical order. 
use maloc
free()
DONT USE SORT
*/

//the Defintion of Structer ListParts
typedef struct ListPart{
//	struct node *head;
	int partNum;
	int quantity;
	float price;
	struct ListPart *next;
};
//prototypes
void Add(struct ListPart **root,struct ListPart **tail, int partNum, int quantity, float price);
void print(struct ListPart *root);
void Insert(struct ListPart *current, struct ListPart *ahead, int partNum, int quantity, float price);
void beginningInsert(struct ListPart **root, struct ListPart **current, int partNum, int quantity, float price);
void endInsert(struct ListPart *current, struct ListPart *ahead, int partNum, int quantity, float price);
void create(struct ListPart **root);
void remove(struct ListPart **root);
void saveList(struct ListPart **root);
void openList(struct ListPart **root);
void printPart(struct ListPart *root);
void changePart(struct ListPart *root);




int main()
{

//create the head/root/start of list
	ListPart* root = NULL;
	root = (ListPart*)malloc(sizeof(ListPart));
	root->next = NULL;
	
//create the tail, last ending of list.
	ListPart* tail = NULL;
	tail = (ListPart*)malloc(sizeof(ListPart));
	tail->partNum=0;
	tail->next = NULL;
		   
	char userSelect = '-';	//blah, non selected input.
	int n=0;
	int partNum=0;
	int quantity=0;
	float price=0;

//MENU SELECTION DISPLAY
	while (userSelect != 'i') //first setting, entering the menu seleciton. HOME
	{	
// display the first PART, for testing purposes
//		printf("Display the start of the list.\n");
//		printf("Have Part %d, Quantity %d, Price $%.2f \n", root->partNum, root->quantity, root->price);

		printf("\n--------------------------------------------------\n");
		printf("A. Create a new linked list of part number, quantity and price\n");
		printf("B. Add to an existing list(read from a file)\n");
		printf("C. Print the entire list\n");
		printf("D. Print the information for one user selected part number\n");
		printf("E. Inert a new structure into the sorted linked list\n");
		printf("F. Modify an existing structure into the linked list\n");
		printf("G. Delete an existing structure from the list\n");
		printf("H. Save a list(to a file)\n");
		printf("I. Exit from the program\n");
	    scanf(" %c", &userSelect);
	//if selected CREATE
		if(userSelect == 'a'){
			create(&root);
		}
		
	//load a list
		else if(userSelect == 'b'){	
			openList(&root);
		}
		
	//selected PRINT, display the list parts.. cal function		
		else if(userSelect == 'c'){	
			print(root);
		}
		
	//selected print one item.
		else if(userSelect == 'd'){
			printPart(root);
		}
		
	//insert an item		
		else if(userSelect == 'e'){	
			Add(&root, &tail, partNum, quantity, price);
		}
		
	//modify part
		else if(userSelect == 'f'){
			changePart(root);
		}	

	//selected Delete.	
		else if(userSelect == 'g'){
			remove(&root);
		}
	
	//save list	
		else if(userSelect == 'h'){
			saveList(&root);
		}
		
	//selected QUIT, get out.		
		else if(userSelect == 'i'){
			printf("Bye Bye\n");
		}
		
	//wrong input, repeat question.	
		else{
			printf("\nInvaild Input.");
		}	
	}//end of while loop menu, (pressed quit)
	
return 0;
}

//CREATE function. create 
void Add(struct ListPart **root, struct ListPart **tail, int partNum, int quantity, float price)
{
//create local varriables to passthrough linklist.
	ListPart *current, *ahead;
	current = *root;	//set current on starting first node.
	if(partNum==0)
	{
	//prompt part number
	printf("Enter the part number of item:\n");
	scanf("%d", &partNum);
	//prompt quantiy
	printf("Enter quantity of item:\n");
	scanf("%d", &quantity);
	//prompt price
	printf("Enter price of item:\n");
	scanf("%f", &price);
	}
	if(partNum < 1)
	{
		printf("ERROR #ID10T: No such Part Number can exist. \n");
		return;
	}
//first time creating. start =NULL, input information.
	if ((*root)->next == NULL) 
	{	printf("placing the items into address location: %p\n", *root);
		(*root)->partNum = partNum;
 	 	(*root)->quantity = quantity;
 	  	(*root)->price = price;
		(*root)->next = *tail;	//set the first part to equal start poistion and point towards tail.
		return;
	}
	else if(partNum < (*root)->partNum)	//if the inserted partNum is LESS than the STARTing first linked part.
	{	//make the new items the new root.
		beginningInsert(root, &current, partNum, quantity, price);
	
		printf("after returning from (beginningInsert)... (new)Root: %p    Current(should be old root): %p \n", *root,current);
		return;
	} 
	while(current->next != NULL)	//there is a chain link after the currently selected PART.
	{
		
		ahead = current->next;	//set another pointer ahead of current to check next part number.     current.partNum < ahead.partNum.
		if(current->partNum == partNum)
		{  //number inputed is same as a LIST PartNUM
			printf("INVALID INPUT:  partNum already exsits in list @location(%p).\n",current);
			return;
		}

		else if((partNum > current->partNum) && (partNum < ahead->partNum) && (ahead->next != NULL))	
		{
			//place the newly inserted data here.
			Insert(&*current,&*ahead, partNum, quantity, price);
			return;	//return. STOP searching. been placed.			
		}
//		advance the selection	..because, 1)there must be a following link 
//		2) part is NOT greater than current AND part is NOT less than next part
//		3) ahead could be NULL, meaning have no vaule yet for partNUM to compare.
		else 
		{
			if(ahead->next != NULL)		//if ahead slection isnt end of link advance
			{	
				current = current->next;	//advance current selection						
				ahead = ahead->next;
			}
			else	//ahead.next points to NULL...last link. place part here.
			{
				endInsert(&*current,&*ahead, partNum, quantity, price);
				return;	
			}
		}
	}
	
}

//PRINT function. displaying the list
void print(struct ListPart *root)
{
	ListPart *current = root;

	printf("Linked List: \n");
	while(current->next!=NULL)
	{
	  	printf("Part %d    	Quantity %d  	Price $%.2f  	ADRESS:%p\n", current->partNum, current->quantity, current->price, current);
		current=current->next;	//increment the next partNum
	}
	printf("End of List\n");
	
}

//INSERT funciton, to input current location between LINKS.
void Insert(struct ListPart *current, struct ListPart *ahead, int partNum, int quantity, float price)
{	//create space. placement
	ListPart* placement = NULL;
	placement = (ListPart*)malloc(sizeof(ListPart));
	//enter PART ahead of current redirect current.NEXT too newITEM.
	current->next = placement;
	//enter the data
	placement->partNum = partNum;
	placement->quantity = quantity;
	placement->price = price;
	//redirect new part.NEXT too the link after.
	placement->next = ahead;
	printf("Finished placeing new part. Inserted after current and before following link.\n");
}

//NEW root insert.
void beginningInsert(struct ListPart **root, struct ListPart **current, int partNum, int quantity, float price)
{	
	ListPart* placement = NULL;
	placement = (ListPart*)malloc(sizeof(ListPart));
	//enter the data
	placement->partNum = partNum;
	placement->quantity = quantity;
	placement->price = price;
	//should be new root.
	*root = placement;
	//now the root points to what used to be the root.
	(*root)->next = *current;
	printf("Finished placeing new part. Inserted as new ROOT{root->next = current;}.\n");
}

//END INSERT funciton, putting the link at the end.
void endInsert(struct ListPart *current, struct ListPart *ahead, int partNum, int quantity, float price)
{	//create space. placement
	ListPart* placement = NULL;
	placement = (ListPart*)malloc(sizeof(ListPart));
	//enter PART ahead of current redirect current.NEXT too newITEM.
	current->next = placement;
	//enter the data
	placement->partNum = partNum;
	placement->quantity = quantity;
	placement->price = price;
	//redirect new part.NEXT too the link after.
	placement->next = ahead;
	printf("Finished placeing new part. Inserted as last Part, end of LIST.\n");
}
//CREATE function, deleting the old, and enting in new.
void create(struct ListPart **root)
{
	printf("Creating a New List of Items.\n Deleting old list...\n");
	ListPart *node, *temp;
	node = *root;
	//while root has a link after.
	while(node != NULL)
	{	
		temp = node;
		node = node->next;
		temp->next = NULL;
		free(temp);
	}

	
//	ListPart* root = NULL;
	*root = (ListPart*)malloc(sizeof(ListPart));
	(*root)->next = NULL;
	
////create the tail, last ending of list.
	ListPart* tail = NULL;
	tail = (ListPart*)malloc(sizeof(ListPart));
	tail->next = NULL;
//		  	  
	int numParts=0, x;
//	ListPart* tail = NULL;
//	tail = (ListPart*)malloc(sizeof(ListPart));
//	tail->next = NULL;
	printf("How many Parts do you wish to enter?\n");
	scanf("\n%d",&numParts);
	for(x=0; x < numParts; x++)
	{
		Add(root, &tail, 0, 0, 0);
	}
}

//delete list 
void remove(struct ListPart **root)
{
//	printf("Succesfully entered (Remove)\n");
	int partNum=0;
//	printf("Succesfully {int partNum=0;}\n");
	ListPart *current, *behind, *ahead;
//	printf("Succesfully {	ListPart *current, *behind, *ahead;}\n");
	behind = *root;		//behind selected part (1st) 
//	printf("Succesfully {	behind = *root;	}\n");
	current = (*root)->next;	//current selected part (2nd)
//	printf("Succesfully {	current = (*root)->next;}\n");
	if(current == NULL)
	{
		printf("List is empty. Nothing left to delete.\n");
		return;
	}
	ahead = current->next;	//ahead selected part (3rd)
//	printf("ahead = current->next;}\n");
	printf("Enter the Part Number you wish to delete:\n");
	scanf("\n%d",&partNum);
	while(behind->next!=NULL)	//meaning there is a link infront
	{
		if((*root)->partNum == partNum)	//part number equals first Part
		{
			printf("Found number %d in ROOT.\n", partNum);
			*root = current;	//set 2nd as new root.
	
			(*root)->next = ahead;	
			behind->next = NULL;
			free(behind);
			break;
		}
		else if(current->partNum == partNum)
		{
			printf("LINK %d(%p)-->> %d(%p)\n",behind->partNum,behind,ahead->partNum,ahead);
			behind->next = ahead;
			printf("Will Delete %d from list.\n",partNum);
			current->next = NULL;
			free(current);
			break;
		}
		//shorter processing. if partNumber is Less than the current PartNumber (stop searching. because List is in order. thus already would have been found.)
		else if((current->partNum != partNum) && (current->partNum > partNum))	//didnt find number, and there is no next link.			
		{
			printf("Number %d was not found in list.\n", partNum);
			break;
		}
		else	// increment the nodes, compare next Part to find number.
		{
			current=current->next;	//(2)..(3)..(4)
			behind=behind->next;	//(1)..(2)..(3)
			ahead=ahead->next;		//(3)..(4)..(5)
		}
	}
}

//save list function
void saveList(struct ListPart **root)
{
   FILE *fptr;
   fptr = fopen("D:\\C programing CIS-170\\SavedListData\\savedlist.txt","w");
//if the fptr is not exsitant. error. stop
   if(fptr == NULL)
   {
      printf("Error, unable to save!");   
      exit(1);             
   }

	ListPart *current = *root;
	while(current->next!=NULL)
	{
	  	fprintf(fptr,"%d,%d,%f\n", current->partNum, current->quantity, current->price);
		current=current->next;	//increment the next partNum
	}
   fclose(fptr);
   printf("Saved List... completed\n");
}

//open list function
void openList(struct ListPart **root)
{   
	ListPart *current = *root;
	FILE *fptr;
   	int partNum=0, quantity=0, first=1;
	float price=0.0;
	if ((fptr = fopen("D:\\C programing CIS-170\\SavedListData\\savedlist.txt","r")) == NULL)
	{
       printf("Error! opening file");
       // Program exits if the file pointer returns NULL.
       exit(1);
	}
	
	ListPart *node, *temp;
	node = *root;
	//while root has a link after.
	while(node != NULL)
	{	
		printf("temp = node;		node = node->next;\n ");
		temp = node;
		node = node->next;
		printf("free temp\n");

		temp->next = NULL;
		free(temp);
	}

//	ListPart* root = NULL;
	*root = (ListPart*)malloc(sizeof(ListPart));
	printf("(Create) Root: %p\n", *root);
	(*root)->next = NULL;
	printf("(create) after {*root->next = NULL} ROOT: %p\n", *root);
	
////create the tail, last ending of list.
	ListPart* tail = NULL;
	tail = (ListPart*)malloc(sizeof(ListPart));
	tail->next = NULL;
//		  	  


   char line [ 100 ]; 
    while ( fgets ( line, sizeof line, fptr ) != NULL ) /* read a line */
    {
//   	fputs ( line, stdout ); /* write the line */
    // 	fscanf(fptr,"%d,%d,%f,p%\n",partNum,quantity,price);
              
    	sscanf(line, "%d,%d,%f",&partNum,&quantity,&price);
    	Add(root, &tail, partNum, quantity, price);
    }
    printf("Loaded List...completed.\n");
   fclose(fptr); 	
}


void printPart(struct ListPart *root)
{
	int partNum=0;
	//prompt part number 
	printf("What Part Number would you like to view?\n");
	scanf("%d",&partNum);
	//create temp search
	ListPart *current = root;
//search till end of list
	while(current->next!=NULL)
	{
		if(current->partNum == partNum)
		{
	  	printf("Part %d    	Quantity %d  	Price $%.2f  	ADRESS:%p\n", current->partNum, current->quantity, current->price, current);
	  	return;
	  	}
	  	if(current->partNum > partNum)
	  	{
	  		printf("Part Number not found in list.\n");
	  		return;
		}
		current=current->next;	//increment the next partNum
	}

}


void changePart(struct ListPart *root)
{
	int partNum=0;
	//prompt part number 
	printf("Part Number would you like to modify?\n");
	scanf("%d",&partNum);
	//create temp search
	ListPart *current = root;
//search till end of list
	while(current->next!=NULL)
	{
		if(current->partNum == partNum)
		{
	  	printf("What is the new Quantity?\n");
	  	scanf("%d",&current->quantity);
	  	printf("What is the new Price?\n");
	  	scanf("%f",&current->price);
	  	return;
	  	}
	  	if(current->partNum > partNum)
	  	{
	  		printf("Part Number not found in list.\n");
	  		return;
		}
		current=current->next;	//increment the next partNum
	}
}
