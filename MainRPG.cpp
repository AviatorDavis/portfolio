/*
RPG Project.
Journey of a hero. Go along the path, and fight different monsters.  
Choose a hero, elf,human,dwarf.
choice to rest, or contuine,
different weapons, for dmg, and proficency.
different powers based on Type.


*/
#include <cstdlib>
#include <ctime>
#include <iostream>
#include<string.h> 
#include<vector>

using namespace std;

//global current line
int ActiveLine = 3;
int BattlePortraitLines =3;
char wait;
string town = "'Peaceable Town'";
string cave = "'Stonedown Mine'";
	
//CURSOR HANDILING
#include <windows.h>
//press key to contine
void EnterToContinue()
{	//clear buffer, and loop till enter is pushed
	//std::cin.clear();
//	cout << '\n' << "Press Enter to continue...";
//	cin.ignore();
//	while (cin.get() != '\n'){}
//	do 
//	{
//		//cout << '\n' << "Press Enter to continue...";
//	} while (cin.get() != '\n');
cout << '\n' << "Press Enter to continue...";
 fflush(stdin);
 getchar();
}
//go to cordinates
int GotoXY( int x, int y)
{
   COORD coord;
   coord.X = x;
   coord.Y = y;
   SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
   return y;
}
//set cursorto
void setCursorTo(int x, int y)
{
     HANDLE handle;
     COORD position;
     handle = GetStdHandle(STD_OUTPUT_HANDLE);
     position.X = x;
     position.Y = y;
     SetConsoleCursorPosition(handle, position);
}

//For Wiping screen and entering a fancy border
void newScreenBorder()
{
	system("CLS");
	cout<<"__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)__)"<<endl;
	cout<<"(  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  (  ( "<<endl;
	ActiveLine=2;
	setCursorTo(0,2);
	
}

void defeatScreen()
{
	system("CLS");
	setCursorTo(0,10);
	cout<<"     _        _  \n   _| |      | |_ \n   |_ \\      / _| \n     \\ \\____/ / \n      \\/_  _\\/ \n       \\*  */ \n        |/\\| \n       /\\__/\\ \n     _/ /  \\ \\_\n    |_ /    \\ _| \n     |_|    |_| ";
	cout<<"\n\n\n\nDEFEAT";
	exit(0);
}

void win()
{
	cout<<"Victory!";
	cout<<endl<<"Through much pain and struggle you have purged the evil from this land. "<<endl<<town<<" has been saved and forever in your debt!";
	cout<<endl<<"A debt they willingly pay in full, when you return to "<<town<<"."<<endl;
	cout<<endl<<"Go home hero, or unto the next adventure....";
	EnterToContinue();	
	exit(0);	
}
//quiting or retreating
void quit()
{
	newScreenBorder();
	cout<<endl<<"You turn around and leave this dark "<<cave<<". Whether for your own life or your care not to save others"<<endl;
	cout<<"you will never see another monster again. You leave to live the simple life, a heroes call was not for you."<<endl; 
	cout<<"Its not only about others, you have your own life to live. People will accept that, right?"<<endl;
	cout<<endl;
	cout<<"Regardless you are still alive able to tell the story however you want."<<endl;
	cout<<"No one else will know the truth the real truth."<<endl;
	cout<<endl<<"Except for the town folk of "<<town<<" who are now dying to the terrorizing evils of demons from that cave you abandon."<<endl;
	EnterToContinue();
	exit(0);
}

void retreated()
{
	newScreenBorder();
	cout<<"Wow what fast feet you have."<<endl;
	cout<<"You have successfully made it out of the cave alive!"<<endl;
	cout<<"The terror of "<<cave<<" and horror for "<<town<<" still Exists."<<endl;
	cout<<"However, you get to survive and live another day!"<<endl;
	EnterToContinue();
	exit(0);
}


//Weapon Class
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Weapon
{
	private:
		string name;
		int WType;
		int damage;

	public:	//construtors defualt and overloaded for full weapon
		Weapon(int wt= 0, string n="Unarmed", int dmg=0){WType=wt; name = n; damage=dmg;}
		Weapon(Weapon &w){ name = w.getName(); WType= w.getWType(); damage = w.getWDamage(); }
		//gets
		string getName(){return name; }
		int getWType(){return WType; }
		int getWDamage(){return damage; };
		//get full weapon
		//Weapon getWeapon(){ return this; }
		//sets
		void setName(string n){	name=n; }
		void setWType(int w){ WType=w; }
		void setDamage(int d) { damage=d; }
		string getWeaponType();
		
};


string Weapon::getWeaponType()
{
	switch (getWType())
	{
		case 0: return "Unarmed";
		case 1: return "Sword";
		case 2: return "Bow";
		case 3: return "Blunt";
		case 4: return "Conjured";
	}
	return "Unarmed";
}

//CREATURE CLASS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Creature
{
	private:
		int type;
		int strength;
		int hitpoints;
		int maxHitpoints;
		Weapon item;
		int weaponSkill;
		int poisoned =0;
		
	public:
		//Creature();	//intilize to human 10/10
		Creature(int Strength=10,int Hit=10,int Type=10){ type=Type; strength=Strength; hitpoints=Hit; maxHitpoints=hitpoints; weaponSkill=0; }
		Creature(Weapon w, int Strength=10,int Hit=10,int Type=10){ type=Type; strength=Strength; hitpoints=Hit; maxHitpoints=hitpoints; weaponSkill=0; item = w;}
		void setType(int);
		void setStrength(int);
		void setHitpoints(int);
		void setMaxHitpoints(int);
		void setWeapon(Weapon i);
		virtual void attack(Creature);
		int getType();
		int getStrength();
		int getHitpoints();
		int getMaxHitpoints();
		string getSpecies();
		virtual int getDamage();	//return amount of damage this creature inflicts in one round of combat
		virtual void hurt(int);
		virtual void victory(){}	//after winning a battle
		virtual void flee(){}	//after fleeing a battle
		virtual int getWeaponSkill(){ return 0;}
		Weapon getWeapon(){ return item;	}
		virtual void heal(int);
		int getPoisoned(){return poisoned;}
		void setPoisoned(int p){poisoned = p;}
				
};
//return species
string Creature::getSpecies()
{
	switch (type)
	{
		case 0: return "Human";
		case 1: return "Elf";
		case 2: return "Dwarf";
		case 5: return "Goblin";
		case 6: return "Troll";
		case 7: return "Imp";
		case 8: return "Balrog";
		case 9: return "Demonic";
	}
	return "Unknown";
}
//GETS 
int Creature::getStrength(){
	return strength;		}
int Creature::getHitpoints(){
	return hitpoints;	}
int Creature::getType(){
	return type;		}
int Creature::getMaxHitpoints(){
	return maxHitpoints;	}
//SETS
void Creature::setHitpoints(int hit){
	hitpoints = hit;	}
void Creature::setStrength(int st){
	strength = st;	}
void Creature::setType(int t){
	type=t;		}
void Creature::setMaxHitpoints(int mh){
	maxHitpoints= mh;	}
void Creature::setWeapon(Weapon i){
	item = i;
}
//calc damage done per attack
int Creature::getDamage()
{	//calc dmg,
	int dmg;
	//test for positive strength to stop breaking random calcultor
	if(getStrength() < 1)
		dmg=1;
	else
		dmg = (rand()% getStrength() )+1 + getWeapon().getWDamage() + getWeaponSkill();
	cout<<getSpecies()<<" attacks for "<< dmg<<" points using "<<getWeapon().getName()<<"("<<getWeapon().getWDamage() + getWeaponSkill()<<")! "<<endl;
return dmg;
}

void Creature::attack(Creature character)
{
	getDamage();
		
}

void Creature::hurt(int dmg)
{	//set new hitpints, to ( health- dmg);
	setHitpoints( (getHitpoints() - dmg) );
	cout<<getSpecies()<<" takes "<< dmg << " points of damage, with a current "<< getHitpoints() <<" hitpoints left.\n";
	
}
//increase health, but not above max
void Creature::heal(int h)
{
	int hp = getHitpoints();
	int max = getMaxHitpoints(); 
	if( max < (h + hp))	//if healing would add higher than max	then set to max
	{
		setHitpoints(getMaxHitpoints()); //setHitPoints to MAXhitPoints
	}
	else		//it wouldnt heal you over max
	{
		setHitpoints(getHitpoints() + h);	//then get current, and add heal, and set it in new Current
	}
}

//Elf Class
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Elf : public Creature
{
	public:
		Elf(int Strength=10,int Hit=10):Creature(Strength,Hit,1){}
		virtual int getDamage();
		virtual int getWeaponSkill();
};

int Elf::getDamage()
{//create local dmage
	int dmg;
	dmg = Creature::getDamage();
	if(dmg==1 || dmg==2)
	{
		cout<<"Recover from a failed attack, and attack again with [Elven Grace]"<<endl;
		dmg = Creature::getDamage();
	}
	//Elves have a chance to inflic double dmg
	if((rand()%10)==0)
		{
			cout<<"Magical attack inflicts "<<dmg << " additional damage points from [Ancient Proficiency]!"<<endl;
			dmg = dmg *2;
		}
	return dmg;
}

int Elf::getWeaponSkill()
{
	//if weapon type==2 bows
	if(getWeapon().getWType()==2)
	{
		return 3;
	}
	if(getWeapon().getWType()==3)	//blunt
		return -3;
	return 0;
}

//Human Class
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Human : public Creature
{
	private:
		int confidence;
	public:
		Human(int Strength=10,int Hit=10):Creature(Strength,Hit,0){ confidence = 1; }
		virtual int getDamage();
		int getConfidence(){ return confidence; }
		void setConfidence(int c){ confidence = c;}
		void addConfidence(){confidence++;}
		virtual void victory();
		virtual void flee();
		virtual int getWeaponSkill();
};

int Human::getDamage()
{//create local dmage
	int dmg;
	dmg = Creature::getDamage();
	//Humans get more confidence with victories.
	if(confidence==1)
		cout<<"The naive "<< getSpecies() << ", feeling on top of the world does " <<getConfidence() * 2<<" additional damage from [Confidence].\n";
	else
		cout<<getSpecies()<<" does an additional "<<getConfidence() * 2 << " points of damage from [Confidence].\n";
	//double confidence in damage
	dmg = dmg + getConfidence() * 2;
	return dmg;
}

void Human::victory(){	//upon victory, confidnce is incremeted
addConfidence();}

void Human::flee(){
	cout<<"After retreating in failure, "<<getSpecies()<< "'s [Confidence] has dwindled."<<endl;
	if(getConfidence() > 2)	//decrease by 2
		setConfidence((getConfidence() - 2));
	else		//if at 2 or less, than drop to one... cant go below 1
		setConfidence(1);		
}

int Human::getWeaponSkill()
{
	//if weapon type==0 (unarmed/fist)
	if(getWeapon().getWType()==1 || getWeapon().getWType()==2)
	{
		return 1;
	}
	if(getWeapon().getWType()==3)
		return -2;
	return 0;
}
//Dwarf Class
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Dwarf : public Creature
{
	private:
	public:
		Dwarf(int Strength=10,int Hit=10):Creature(Strength,Hit,2){ }
		virtual int getDamage();
		virtual void hurt(int);
		virtual int getWeaponSkill();
		virtual void victory();
};

int Dwarf::getDamage()
{//create local dmage
	int dmg;
	dmg = Creature::getDamage();
	//double confidence in damage
	return dmg;
}

void Dwarf::hurt(int dmg)
{	//Dwarves have a chance to dodge.
	if((rand()%10)==0)
	{
		cout<<getSpecies()<<" dodges the attack, taking 0 damage from [Drop to the Ground].\n";
	}
	else	
	{//set new hitpints, to ( health- dmg);
		setHitpoints( (getHitpoints() - dmg) );
		cout<<getSpecies()<<" takes "<< dmg << " points of damage, with a current "<< getHitpoints() <<" hitpoints left.\n";
	}
}

int Dwarf::getWeaponSkill()
{
	//if weapon type==0 (unarmed/fist)
	if(getWeapon().getWType()==0)
		return 4;
	if(getWeapon().getWType()==2)		//bows
		return -2;
	if(getWeapon().getWType()==1)		//blunt
		return 1;
	return 0;
}

void Dwarf::victory()
{
	setMaxHitpoints(getMaxHitpoints() + 5);
	heal(5);
	cout<<getSpecies()<<" gains 5 more Maximum Hitpoints from [Thicken Scars]"<<endl;
}
//DEMON CLASS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Demon : public Creature
{
	private:
		
	public:
		Demon(int Strength=10,int Hit=10,int Type=10):Creature(Strength,Hit,Type){}	
		virtual int getDamage();		
};

//calc damage done per attack
int Demon::getDamage()
{	//calc dmg,
	int dmg;
	//test for positive strength to stop breaking random calcultor
	if(getStrength() < 1)
		dmg=1;
	else
		dmg = (rand()% getStrength() )+1 + getWeapon().getWDamage() + getWeaponSkill();
	cout<<getSpecies()<<" attacks for "<< dmg<<" points using "<<getWeapon().getName()<<"("<<getWeapon().getWDamage() + getWeaponSkill()<<")! "<<endl;
	
//if a demon(cyber or balrogs)	extra 50
	if((rand()%100)<5)
	{
		dmg=dmg +30;
		cout<<"Demonic attack inflicts 30 additional damage points from [Devilish Curse]" <<endl;
	}
return dmg;
}

//Imp class
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Imp : public Demon
{
	private:
		
	public:
		Imp(int Strength=10,int Hit=10):Demon(Strength, Hit,7){ Weapon claws(0,"Claws",2); setWeapon(claws);}
		virtual int getDamage();
		virtual void hurt(int);
};

int Imp::getDamage()
{//create local dmage
	int dmg;
	dmg = Demon::getDamage();
	int dmg2 = (rand()% getStrength() )+1;
	return dmg;
}

void Imp::hurt(int dmg)
{	//Imps have 33% take half damage
	if((rand()%2)==0)
	{
		dmg/2;
		setHitpoints( (getHitpoints() - dmg) );
		cout<<"Imp phases taking only " <<dmg/2 <<" points of damage from [Dimensional Phase], with a current "<< getHitpoints() <<" hitpoints left.\n";
	}
	else	
	{//set new hitpints, to ( health- dmg);
		setHitpoints( (getHitpoints() - dmg) );
		cout<<getSpecies()<<" takes "<< dmg << " points of damage, with a current "<< getHitpoints() <<" hitpoints left.\n";
	}
}

//Balrog class
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Balrog : public Demon
{
	private:
		
	public:
		Balrog(int Strength=10,int Hit=10):Demon(Strength, Hit,8){ Weapon whip(4,"Whip",4); setWeapon(whip);}
		virtual int getDamage();
};

int Balrog::getDamage()
{//create local dmage
	int dmg;
	dmg = Demon::getDamage();
	//Balrogs attack twice
	int dmg2 = (rand()% getStrength() )+1;
	if((rand()%100)<5)
	{
		dmg2=dmg2 +50;
		cout<<"Demonic attack inflicts 50 additional damage points from [Devilish Curse]" <<endl;
	}
	cout<<"Balrog speed attack inflicts "<<dmg2<<" additional damage from [Blazing Strike]"<<endl;
	dmg = dmg + dmg2;
	return dmg;
}


//Troll class
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Troll : public Creature
{
	private:
		
	public:
		Troll(int Strength=10,int Hit=10):Creature(Strength, Hit,6){ Weapon club(3,"Club",5); setWeapon(club);}
		virtual int getDamage();
};

int Troll::getDamage()
{//create local dmage
	int dmg;
	if(getStrength() < 1)
		dmg=1;
	else	//roll dmg multiplier 3 times  betweeen 3-(3*strength)
		dmg = ((rand()% getStrength() )+1) + ((rand()% getStrength() )+1) + ((rand()% getStrength() )+1) + getWeapon().getWDamage() + getWeaponSkill();
	//Trolls attack once and either smash completly with 25% chance, or just do shaking
	if(((rand()%4)+1) == 1)	//if its 25%
	{
		cout<<getSpecies()<<" [Smashes] for "<< dmg<<" points using "<<getWeapon().getName()<<"("<<getWeapon().getWDamage() + getWeaponSkill()<<")! "<<endl;
		return dmg;
	}
	else	//it 75% small shockwave dmg
	{
		dmg = dmg/3;
		cout<<getSpecies()<<" [Smacks and Bumps] for "<< dmg<<" points with a blustering fit of body mass! "<<endl;
		return dmg;
	}
}

//goblin class
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Goblin : public Creature
{
	private:
		
	public:
		Goblin(int Strength=10,int Hit=10):Creature(Strength, Hit,5){ Weapon knife(1,"dagger",1); setWeapon(knife);}
		virtual int getDamage();
		virtual int getWeaponSkill();
};

int Goblin::getDamage()
{//create local dmage
	int dmg;
	dmg = Creature::getDamage();
	//double confidence in damage
	return dmg;
}
//goblins deal extra dmg with daggers
int Goblin::getWeaponSkill()
{
	//if weapon type==0 (unarmed/fist)
	if(getWeapon().getWType()==1)
	{
		return 4;
	}
}

//MAIN FUNCTIONS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//This places cursor , with retrospec of side... in preperation of printing.
//choice for selecting path or action on juroney
char pathChoice()
{	//set y for displaying decisions lines, and increment
	int y=25;
	char choice='0';
	while(choice !='1' && choice !='2' && choice !='q')
	{
		y=25;
		setCursorTo(3,y); y++;
		cout<<"1) Continue Further in";
		setCursorTo(3,y); y++;
		cout<<"2) Rest ";
		setCursorTo(3,y); y++;
		cout<<"Q) Quit ";
		setCursorTo(3,y); y++;
		cin>>choice;
	}
	setCursorTo(0,(ActiveLine+2));
return choice;
}

//change the passed weapon to a random weapon. or select argu
void generateWeapon(Weapon &w, int select=-1)
{	//weapons
	static Weapon brassKnuckles(0,"Cestus",3);	//0
	static Weapon knife(1,"Knife",2);			//1
	static Weapon ironSword(1,"Iron Sword",4);	//2
	static Weapon longSword(1,"Long Sword",6);	//3
	static Weapon shortBow(2,"Short Bow", 3);	//4
	static Weapon longBow(2, "Long Bow", 5);	//5
	static Weapon crossbow(2,"Cross Bow",6);	//6
	static Weapon sledge(3,"SledgHammer",6);	//7
	static Weapon mithrilSword(1,"Mithril Sword",10);	//8
	static Weapon armory[] = {brassKnuckles,knife,ironSword,longSword,shortBow,longBow,crossbow,sledge,mithrilSword};
//check range is within bounds
	cout<<"weapon";
	if(select < -1 || select > 8)
		select=-1;
	if(select==-1)		//if not given, random
	{ int random = rand()%9;
		w = armory[random];
	}
	else				//if given, then select from array
		w = armory[select];

}

char battleChoice()
{	//set y for displaing descisions line, and increment
	int y=25;
	char choice='0';
	while(choice !='1' && choice !='2')
	{
		y=25;
		setCursorTo(3,y); y++;
		cout<<"1) ATTACK ";
		setCursorTo(3,y); y++;
		cout<<"2) FLEE ";
		setCursorTo(3,y); y++;	
		cin>>choice;
	}
	setCursorTo(0,(ActiveLine+1));
return choice;
}

int portraitPlace(int line, string side)
{	int returnedLine;
	int x=64;
	//side = positioning onscreen
	if(side=="right")
		x=56;		//right side
	else if(side=="center")
		x=42;
	else
		x=8;	//defualt left
	//set cordinets to x and y
	returnedLine=GotoXY( x, line);
	return returnedLine + 1;	
}

//clear portraits information between battles
int clearPortraits(Creature& character, string position="left")
{
	int endOfPortrait = 0;
	if(position=="left")
		endOfPortrait = 32;
	if(position=="right")
		endOfPortrait = 80;
	int line= ActiveLine;
	BattlePortraitLines= line;
 	line = portraitPlace(line, position);
	cout<<"                           "<<endl;
	line = portraitPlace(line, position);
	cout<<"                           ";
	line = portraitPlace(line, position);
	cout<<"                           "<<endl;
	line = portraitPlace(line, position);
	cout<<"                           ";
	line = portraitPlace(line, position);
	cout<<"                           ";
	line = portraitPlace(line, position);
	cout<<"                           ";
	line = portraitPlace(line, position);
	cout<<"                           "<<endl;
return line;
}
	
//Display Portrait, 	the creature,  'left' or 'right' position
int portrait(Creature& character, string position="left")
{	//find the end(right) side of portrait, for correct size
	int endOfPortrait = 0;
	if(position=="left")
		endOfPortrait = 34;
	if(position=="right")
		endOfPortrait = 82;
	//set the printing line to ActiveLine
	int line = ActiveLine+1;
//	BattlePortraitLines= line;
	//top border
 	line = portraitPlace(line, position);
	cout<<"..........................."<<endl;
	line = portraitPlace(line, position);
	cout<<"|Race = "<<character.getSpecies();setCursorTo(endOfPortrait,line-1);cout<<"|";
	line = portraitPlace(line, position);
	cout<<"|_________________________|"<<endl;
	//print strength
	line = portraitPlace(line, position);
	cout<<"|Strength =  "<<character.getStrength();setCursorTo(endOfPortrait,line-1);cout<<"|";
	//print hitpoits
	line = portraitPlace(line, position);
	cout<<"|Hitpoints =  "<<character.getHitpoints()<<" / "<< character.getMaxHitpoints();setCursorTo(endOfPortrait,line-1);cout<<"|";
	//print weapon, get copy of item out first.
	line = portraitPlace(line, position);
	cout<<"|"<<character.getWeapon().getName()<<">> "<<character.getWeapon().getWDamage()<<" + "<< character.getWeaponSkill();setCursorTo(endOfPortrait,line-1);cout<<"|";
	//bottom border
	line = portraitPlace(line, position);
	cout<<"```````````````````````````"<<endl;
return line;
}

//Display Item
int portraitItem(Weapon& item, string position="left")
{	//find the end(right) side of portrait, for correct size
	int endOfPortrait = 0;
	if(position=="left")
		endOfPortrait = 30;
	if(position=="right")
		endOfPortrait = 78;
	//set the printing line to ActiveLine
	int line = ActiveLine+1;
//	BattlePortraitLines= line;
	//top border
 	line = portraitPlace(line, position);
	cout<<"......................."<<endl;
	//print name 
	line = portraitPlace(line, position);
	cout<<"|"<<item.getName();setCursorTo(endOfPortrait,line-1);cout<<"|";
	//type 
	line = portraitPlace(line, position);
	cout<<"|"<<item.getWeaponType()<<" >>dmg>> "<<item.getWDamage();setCursorTo(endOfPortrait,line-1);cout<<"|";
	//bottom border
	line = portraitPlace(line, position);
	cout<<"```````````````````````"<<endl;
return line;
}

int portraitBattle(Creature& unit1, Creature& unit2)
{
//	newScreenBorder();
	ActiveLine = BattlePortraitLines;
	int line = BattlePortraitLines;
	//unit 1, on left side
	clearPortraits(unit1, "left");
	line = portrait(unit1, "left");
	portraitPlace(ActiveLine + 3, "center");		//print 3 lines lower than the top of battle
	cout<<"BATTLE!\n";
	clearPortraits(unit2, "right");
	line = portrait(unit2, "right");
	//now after portraits are done, move CurrentLine down
	return line;
//UNIT 2 , on right side

}

int attacking(Creature& character)
{
	int dmg;
	dmg = character.getDamage();
	return dmg;
}

//Battle functions, input 2 creatures and if suprise.
bool battle(Creature& unit1, Creature& unit2, bool suprise=false)
{	//Screen and set BattlePortraiterLines equal to ActiveLine.
	newScreenBorder();
	if(suprise)
	{
		if(unit1.getType()==1)
			cout<<"Elves are not suprised. [Elven Grace]";
		else
		{
		cout<<"In a sudden suprise you have been attacked by a "<< unit2.getSpecies() <<"!"<<endl;
		unit1.hurt(attacking(unit2));
		}
	}
	else
		cout<<"You have encountered a "<< unit2.getSpecies() <<"!"<<endl;
	ActiveLine += 2;
	//turn counter
	int turn=1;
	char choice='0';
	bool flee = false;
	//if suprise agaisnt goblin
	if((suprise) && unit2.getType() ==5)
	{
		cout<<"A Goblin gets to strike extra on an ambush, being [Sneaky]"<<endl;
		unit1.hurt(attacking(unit2));
		ActiveLine+=2 ;
	}
		BattlePortraitLines = ActiveLine;
//	ActiveLine=portraitBattle(unit1,unit2);
	//while both units are above 0 health, keep fighting
	while( (unit1.getHitpoints() > 0 && unit2.getHitpoints() > 0) && (!flee))
	{	//unit 2 is hurt( attacked by( unit1) );
		ActiveLine = portraitBattle(unit1,unit2);
		cout<<"--ROUND "<<turn<<"--"<<endl;
	//for players original choice, unless its suprise. or if its a suprise and you are an elf(eleves arent suprised)
		if(choice =='0' && (suprise==false || unit1.getType() == 1)){
			choice = battleChoice();
		}
	//player makes choice for action
		if(choice=='2'){
			cout<<"You attempt to flee!\n";
			flee=true;
		}
		else if(choice=='1')
			unit2.hurt( attacking(unit1) );
	//Enemies turn to attack
		if(unit1.getHitpoints() > 0 && unit2.getHitpoints() > 0)
			unit1.hurt( attacking(unit2) );
		turn++;
		//display battleportraits
		ActiveLine = portraitBattle(unit1,unit2);
		if((!flee) && (unit1.getHitpoints() > 0 && unit2.getHitpoints() > 0)){
			choice = battleChoice();
		}
		else{
			setCursorTo(30,20);
			EnterToContinue();
		}
		newScreenBorder();
		//the first suprise round is over
		suprise=false;
	}
	if( unit1.getHitpoints() < 0)
	{
		setCursorTo(30,20);
		if(flee)
			cout<<unit1.getSpecies()<<" attempted to flee but was been slain by "<< unit2.getSpecies()<<endl;
		else
			cout<<unit1.getSpecies()<<" has been slain by "<<unit2.getSpecies()<<endl;
		EnterToContinue();
		defeatScreen();
	}
	else if( unit2.getHitpoints() < 0 )
	{
		setCursorTo(30,20);
		cout<<unit1.getSpecies()<<" has slain "<<unit2.getSpecies()<<endl;
		unit1.victory();
	}
	else if((flee) && unit1.getHitpoints() > 0)
	{
		setCursorTo(30,20);
		cout<<unit1.getSpecies()<<" has successfully fled without fatal wounds."<<endl;
		unit1.flee();
	}
	EnterToContinue();
	newScreenBorder();
	//if you fled return false, failed encounter
	if(flee)
		return false;
	else	//or return true, you passed the encounter battle
		return true;
}

Creature* selectHero()
{
	char select=0;
	newScreenBorder();
	//create the heroes
	Human hero1(20,97);
	Elf hero2(25,89);
	Dwarf hero3(17,118);
	
	Weapon humans;
	Weapon elfs;
	generateWeapon(humans,1);
	hero1.setWeapon(humans);
	generateWeapon(elfs,4);
	hero2.setWeapon(elfs);
	ActiveLine++;
	//display heros
	ActiveLine = portrait(hero1);
	ActiveLine = portrait(hero2);
	ActiveLine = portrait(hero3);
//human
	setCursorTo(1,5);
	cout<<"1)";
	setCursorTo(39,6);
	cout<<"Humans have a average skill with all weapons.";
	setCursorTo(39,7);
	cout<<"Also, after succeding in fights they build [Confidence] for extra damage.";
//elf
	setCursorTo(1,13);
	cout<<"2)";
	setCursorTo(39,14);
	cout<<"Elves are skilled with a bow, and NOT with blunt weapons.";
	setCursorTo(39,15);
	cout<<"They have chance to deal double damage with attacks from [Ancient Proficiency]";
	setCursorTo(39,16);
	cout<<"Eleves get to reroll lowest scoring attacks, and cannot be suprised with [Elven Grace]";
//dwarf
	setCursorTo(1,20);
	cout<<"3)";
	setCursorTo(39,22);
	cout<<"Dwarves are skilled with fists and hammers";
	setCursorTo(39,23);
	cout<<"They have chance to dodge an attack with [Drop to the Ground]";
	setCursorTo(39,24);
	cout<<"They also will gain health after victories [Thicken Scars]";
	
	setCursorTo(3,26);
	while(select!='1' && select!='2' && select!='3')
	{
		cin>>select;
		if(select=='1')
			return new Human(20,97);
		if(select=='3')
			return new Dwarf(17,118);
		if(select=='2')
			return new Elf(25,89);
	}
}
//Random IMP
Imp generateImp()	
{
//	newScreenBorder();
	int die1,die2,power,str,health;
	//random dice for power
	die1= (rand()%13)+18;
	die2= (rand()%13)+18;
	power= die1 + die2;
//	cout<<"power="<<power<<"<><>";
	//now randomly split power into strength and health
	health=(power - ((rand()%18 + 10)));	// take power and subtract between 8->20 (thats the left over health)
	str = power-health;
//	cout<<"health= "<<health<<"________str= "<<str;
	if(health<20)
		health=25;
	if(str<15)
		str=20;
//	cout<<"+++++++++health= "<<health<<"________str= "<<str;
	//create imp.
	Imp im(str,health);
//	ActiveLine=portrait(im);
return im;
}
//Random Balrog
Balrog generateBalrog()	
{
//	newScreenBorder();
	int die1,die2,power,str,health;
	//random dice for power	// 15->35 *2 = 30->70
	die1= (rand()%20)+15;		
	die2= (rand()%20)+15;
	power= die1 + die2;
//	cout<<"power="<<power<<"<><>";
	//now randomly split power into strength and health
	health=(power - ((rand()%10 + 30)));	// take power and subtract between 8->20 (thats the left over health)
	str = power-health;
//	cout<<"health= "<<health<<"________str= "<<str;
	if(health<25)
		health=25;
	if(str<30)
		str=30;
//	cout<<"+++++++++health= "<<health<<"________str= "<<str;
	//create imp.
	Balrog b(str,health);
//	ActiveLine=portrait(b);
return b;
}
//Random TRoll
Troll generateTroll()
{
//	newScreenBorder();
	int die1,die2,die3, power,str,health;
	//random dice for power		// 20->40 + 20->40 + 20->40= 60->120.  
	die1= (rand()%20)+20;
	die2= (rand()%20)+20;
	die3= (rand()%20)+20;
	power= die1 + die2 + die3;
//	cout<<"power="<<power<<"<><>";	
	//now randomly split power into strength and health
	health=(power - ((rand()%20)+ 10));	// take power and subtract between 15->35 (thats the left over health)
	str = power-health;
//	cout<<"health= "<<health<<"________str= "<<str;
	if(health<70)
		health=70;
	if(str<20)
		str=20;
	if(str>(health/2))
		str=health/2;
//	cout<<"+++++++++health= "<<health<<"________str= "<<str;
	//create imp.
	Troll t(str,health);
//	ActiveLine=portrait(b);
return t;
}

//Random Goblin
Goblin generateGoblin()
{
//	newScreenBorder();
	int die1,die2,die3, power,str,health;
	//random dice for power		// 20->40 + 20->40 + 20->40= 60->120.  
	die1= (rand()%15)+3;
	die2= (rand()%15)+3;
	die3= (rand()%15)+3;
	power= die1 + die2 + die3;
//	cout<<"power="<<power<<"<><>";	
	//now randomly split power into strength and health
	health=(power - ((rand()%27)+ 15));	// take power and subtract between 15->35 (thats the left over health)
	str = power-health;
//	cout<<"health= "<<health<<"________str= "<<str;
	if(health<20)
		health=20;
	if(str<20)
		str=20;
//	cout<<"+++++++++health= "<<health<<"________str= "<<str;
	//create imp.
	Goblin g(str,health);
//	ActiveLine=portrait(b);
return g;
}


//random event 
bool event(Creature& player)
{	//Declare variables cave
	newScreenBorder();
	Weapon item;
	char action = 'z';
	int random=0, enemyType=-1, rested=0;
	//monsters
	Imp nasty;
	Troll smelly;
	Goblin sneak;
	//returned values
	bool outcome = true, suprise= true;
	if(player.getPoisoned() > 0){
		cout<<"You feel sicker and weaker as time goes on."<<endl;
		player.hurt(player.getPoisoned());
		ActiveLine+=2;
		if(player.getHitpoints()<0)
		{
			cout<<"You have died from Posion!";
			EnterToContinue();
			defeatScreen();
		}
		player.setPoisoned(player.getPoisoned()+1);
	}
	ActiveLine +=1;
	ActiveLine = portrait(player);
	char choice = pathChoice();
	//after choice then you clear
	newScreenBorder();
	if(choice == '1')
	{	//1->4.. if not one, fight
		if(((rand()%3)+1) > 1){
			enemyType = (rand()%4 + 1);	//1->3
			if(enemyType == 1)
				outcome = battle(player, nasty=generateImp());
			if(enemyType == 2)
				outcome = battle(player, smelly=generateTroll());
			if(enemyType == 3)
				outcome = battle(player, sneak=generateGoblin());
		}
		//come across something
		else{
			cout<<"Deeper still, you find an old looking chest that is covered in dust.\n";
			cout<<"Do you wish to open it or pass on by? ('y' , 'n')";
			while(action != 'y' && action != 'n')
				cin>>action;
			if(action == 'y')
			{
				cout<<"You reach out a hand to open the box.\n";
				random = (rand()%6) + 1; //1,2,3,4,5,6
				if(random==1 || random==2)	//1,2,
				{
					generateWeapon(item);
					action = 'z';
					cout<<"Slowly it creaks open..."<<endl;
					cout<<"You open up to find a "<< item.getName()<<" inside the chest!";
          			ActiveLine += 5;  //four lines passed 					
					ActiveLine = portraitItem(item);
					cout<<"Do you wish take the item and exchange it, or leave it, for keeping the one you already have? ('y' , 'n')"<<endl;
					cout<<"Currently eqquipped->>";
					ActiveLine += 2; 
					ActiveLine = portrait(player);
					while(action != 'y' && action != 'n')
						cin>>action;
					if(action == 'y'){
						cout<<"You have equipped the "<<item.getName()<< " swapping it with your "<<player.getWeapon().getName()<<endl;
						ActiveLine += 3;	//one more line
						player.setWeapon(item);
					}
					else
						cout<<"You decide the find is not better than your own."<<endl;
				}
				if(random == 3)
				{
					cout<<"Slowly it creaks open..."<<endl;
					cout<<"A BAT SUDDENLY SCREECHES AND BITES YOU! Then flys out twoards the entrence of the cave."<<endl;
					cout<<"You are left with these stingning pain where its teeth sunk into your skin."<<endl;
					player.setPoisoned(player.getPoisoned() + 5);
				}
				if(random == 4)
				{
					cout<<"The Chest pops open and fires a spring loaded crosswbolt AT YOUR FACE!"<<endl;
					player.hurt( (rand()%8) + (rand()%8) + (rand()%8) + (rand()%8) + 5);
					cout<<"A darn goblin must have thought that gift was pretty funny to leave for someone like you to find."<<endl;
				} 
				if(random == 5 || random == 6)
				{
					cout<<"Slowly it creaks open..."<<endl;
					cout<<"Its contains only dried up dead bugs."<<endl;
					cout<<"With nothing inside you feel dismayed, but contiune on, not really expecting to find treasures in such a dark pit of the earth."<<endl;		
				}
			}
			else
			{
				cout<<"You pass on by, to contiune deeper in to the cave, forever wondering if you passed on something favorous towards your luck."<<endl;
			}
			EnterToContinue();
		}
	}
	if(choice == '2')
	{
		cout<<"You chose to rest, and recover your wounds."<<endl;
		//1->3.. if not one, then rest
		if(((rand()%2)+1) > 1){
			rested = player.getMaxHitpoints()/3;
			cout<<"You rest peacefully, being able to recover "<< rested<<" hitpoints."<<endl;
			player.heal(rested);
			outcome = false;
			EnterToContinue();
		}
		else{
			rested = player.getMaxHitpoints()/5;
			player.heal(rested);
			cout<<"In the middle of your rest you are inturrupted, only able to recover "<<rested<<" hitpoints!"<<endl;
			enemyType = ((rand()%2) + 1);	//1->2
			EnterToContinue();
			if(enemyType == 1)
				battle(player, nasty=generateImp(), suprise);
			else
				battle(player, sneak=generateGoblin(), suprise);
			outcome=false;
			}
	}
	if(choice == 'q')
		quit();
	return outcome;
}


//intro and explanation
void newGame()
{	//game intro
	string town = "'Peaceable Town'";
	string cave = "'Stonedown Mine'";
	newScreenBorder();
	cout<<endl<<"The old "<<cave <<" has recently fallen to the dominion of numerous monsters from shadow spaces"<<endl;
	cout<<"known of magic and conflict. This rumor is just today been circling around "<<town<<" and "<<endl;
	cout<<"destiny choose you. "<<endl<<endl;
	cout<<"As an agent of destiny you must take up this mighty quest to resuce the residents "<<endl;
	cout<<"of "<<town<<". The monster can not live, you face dangers in "<< cave<<" for some "<<endl;
	cout<<"lucrative wealth store and a heroic title. This quest will be the monster final days of breathing..."<<endl;
	cout<<"or through misforture and failure, it will be yours."<<endl;
	EnterToContinue();
	//now game help
	cout<<endl<<endl<<endl<<"You will be playing as a hero entering the caves, in search of the evil that is controling this mountain"<<endl;
	cout<<"After choosing your hero, you will have actions to contiune deeper in the depths of the cave, or to rest and recover."<<endl;
	cout<<"Through your actions you have a chance to come across good favor, or bad."<<endl;
	cout<<"Be weary of goblins ambushing you!"<<endl;
	cout<<endl<<"\t\t\t__________________________"<<endl;
	cout<<endl<<"\t\t\t| Long Sword >> 2  +  1	|  <----{is the weapon skill, based on Creature using certain weapon type}"<<endl;
	cout<<endl<<"\t\t\t``````````````````````````"<<endl;
		  cout<<"\t\t\t     ^          ^"<<endl;
	cout<<"\t\t{Weapon name}^          ^"<<endl;
	cout<<"\t\t                        ^{is the weapon base dmg}"<<endl;
	
	EnterToContinue();

}
//MAIN
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
/*
Activeline= portrait('creature');......currentline +=6 after portrait.
newScreenBorder();............Clears Screen and resets ActiveLine=3;
battle('creature','creature').........battles 2 units, first place is for player that quits after losing.
//create random list of monsters
//create creature (attack/Health/Type);
//Create Demon (attack/Health/Type);
*/
//prime random generator
	unsigned int seed= time(0);
	srand(seed);
//new border
	newGame();
	
	newScreenBorder();
	Creature *player;
	bool outcome;
	//Creature player;
	//playerPointer = &player;
	Weapon starter;


//HERO SELECION
	player=selectHero();	
	//after selecting if human, give knife, if elf give shortbow
	if(player->getType() == 0){
		generateWeapon(starter,1);
		player->setWeapon(starter);
	}
	if(player->getType() == 1){
		generateWeapon(starter,4);
		player->setWeapon(starter);
	}
//chosen hero
	newScreenBorder();	
	cout<<"Your Hero, to set out on your quest!"<<endl;
	ActiveLine = portrait(*player);
	ActiveLine = portraitItem(starter);
	EnterToContinue();
	
//Adventure, untill 8 events
	for (int rounds=0; rounds <10; rounds++){
	//call Choose path, and event	
		outcome = event(*player);
		if(!outcome)	//the event was a faluire. (fleeing)	slow down progression
			rounds--;
	//	EnterToContinue();
	}
	newScreenBorder();
	cout<<"You have find yourself finally stumbling into the darkest chamber of the cave yet."<<endl;
	cout<<"Do you wish to rest before finding this great evil?"<<endl;
	char choice = pathChoice();
	if(choice == '2')
	{
			cout<<"You chose to rest, and recover your wounds."<<endl;
			int rested = player->getMaxHitpoints()/2;
			cout<<"You rest peacefully, being able to recover "<< rested<<" hitpoints."<<endl;
			player->heal(rested);
			outcome = false;
			EnterToContinue();
			newScreenBorder();
	}
	if(choice == 'q')
	{
		quit();
	}
	else
	{
	//boss fight
		newScreenBorder();
		cout<<"This must be the place of orgin of dark evil that spews horror out across these lands."<<endl;
		cout<<"You see this figure made of Shadow and Flame come forth."<<endl;
		EnterToContinue();
		int retreat=0;
		outcome=false;
		Balrog flame(19,150);
		while(outcome==false && retreat < 10)
		{
			outcome = battle(*player, flame);
			if(outcome ==false)
			{
				cout<<"You retreat back a room, heading for the exit of the cave with the Balrog roaring after you breathing fire!"<<endl;
				retreat++;
				//poison
				if(player->getPoisoned() > 0){
					cout<<"You feel sicker and weaker as time goes on."<<endl;
					player->hurt(player->getPoisoned());
					ActiveLine+=2;
					if(player->getHitpoints()<0)
					{
						cout<<"You have died from Posion!";
						EnterToContinue();
						defeatScreen();
					}
					player->setPoisoned(player->getPoisoned()+1);
				}
				EnterToContinue();
			}
		}
		if(retreat == 10)	//you have successfully fled the boss
		{
			retreated();
		}
	}
	win();

return 0;
}
