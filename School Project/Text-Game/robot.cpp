/************************************************************************/
/*Assignment:     3                                                     */
/*Subject & code: OOP244B                                               */
/*Program:        robot.cpp                                             */
/*Due date:       April 06, 2012                                        */
/*Date submitted: April 13, 2012                                        */
/*Student name:   Freddy Cheungh                                        */
/*Student Id:     039-644-117                                           */
/*Instructor:     Danny Abesdris                                        */
/*Purpose:        Create certain functions, constructors and operator   */
/*                overload to comply with a a3main.o. Using both to make*/
/*		  a robot beat the wizard Weaver in a text-based game.  */
/************************************************************************/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include"robot.h"

using namespace std;

robot::robot(){
    number_command=0;
    max_command=5;
    commands = new command[5];
    name = new char[10];
    strcpy(name, "univac.dat");
}

/*Allocates memory to store a series of commands, also sets the robot name to the string of
nm. Initializes array items and treasures.*/
robot::robot(int num_of_cmds, const char *nm){

	commands = new command[num_of_cmds];
	
	int l=(nm == NULL) ? 0 : strlen(nm);
	try{
		name = new char[l + 1];
	}
	catch(std::bad_alloc){
		name = NULL;
	}
	if(name){
		if(nm == NULL)
			strcpy(name, "");
		else
			strcpy(name, nm);
	}

	for(int i=0; i<3; i++){
		treasure[i]=0;
	}
	for(int c=0; c<8; c++){
		strcpy(items[c],"");
	}
	max_command=num_of_cmds;
	number_command=0;
}
/*Copy constructor*/
robot::robot(const robot &from){
	int l=0;
	strcpy(name,from.name);
	max_command=from.max_command;
	commands=new command[max_command];
	for(l=0;l<max_command;l++){
		commands[l]=from.commands[l];
	}
	for(l=0;l<3;l++){
	treasure[l]=from.treasure[l];
	}
	for(l=0;l<8;l++){
		strcpy(items[l],from.items[l]);
	}
	number_command=from.number_command;
}

/*Used to return the robot name*/
const char* robot::get_name() const{
	return name;
}

/*Returns a command at position 'pos'. Returns a default command if 'pos' does not reference
one of the robot's commands*/
command robot::get_command(int pos) const{
	command temp;
	if(pos > max_command){
		return temp;
	}
	else 
		return commands[pos];

}

/*Used to return the number of command objects currently being stored in the robot*/
int robot::get_command_count() const{
	return number_command;
}

/*Copies the string 'item' into the array of 'item' strings at position 'pos'*/
void robot::set_item(const char item[], int pos){
	if(pos<8 && pos>-1){
		strcpy(items[pos], item);
	}
}

/*Returns the string item located at position 'pos'*/
const char* robot::get_item(int pos) const{
	return items[pos];
}

/*Adds the value stored in 'num' to the array of 'silver', 'gold', or 'platinum' pieces
being stored by the robot*/
void robot::set_treasure(int pos, int num){
	if(pos>=0 && pos<=2){
		treasure[pos]+=num;
	}
}

/*Returns the treasure being stored by voyager*/
int robot::get_treasure(int pos) const{
	if(pos>=0 && pos<=2){	
		return treasure[pos];
	}
}

/*Reads lines from the file named in the string "fname" and adds to the end of the list
of commands stored by the robot*/
int robot::readfile(const char fname[]){
char temp[162];
int valid=0;
FILE *fp;
	fp=fopen(fname, "r");
	for(number_command;number_command<max_command;number_command++){
		fgets(temp,161,fp);
		commands[number_command].init(temp);
		valid++;
	}
	fclose(fp);
	return valid;
}
	
/*Add commands to a robot by overloading the += operator*/
void robot::operator+=(command &old_command){
	if(number_command<max_command){
		commands[number_command]=old_command;
	}
	number_command++;
}
	
/*Overload the operator == to compare if commands are available*/
int robot::operator==(char *str){
int valid=0,y=0,final=0,sum=0;;
	for(y=0;y<max_command;y++,sum++){
		valid=commands[y].valid_command(str);
			if(valid!=0){
				y=max_command;
			}
			if(y==max_command && valid==0){
				y=0;
				valid=1;	
			}
	}
	final=sum*10+(valid-1);
	return final;
}

/*overload the = operator in order to pass values to objects*/
void robot::operator=(const robot &from){
	int l=0;
	strcpy(name,from.name);
	max_command=from.max_command;
	for(l=0;l<max_command;l++){
		commands[l]=from.commands[l];
	}
	for(l=0;l<3;l++){
		treasure[l]=from.treasure[l];
	}
	for(l=0;l<8;l++){
		strcpy(items[l],from.items[l]);
	}
	number_command=from.number_command;
}

/*Write the commands down on a .txt format*/
int robot::execute(char *str){
	int num=0,count=0;
	FILE *fp;
	fp=fopen(name, "a");
	for(int i=0; i < max_command; i++){
		num=commands[i].valid_command(str);
		if(num!=0){
			fprintf(fp, "%s\n", str);
			count=1;
			i==max_command;
		}
		else{
			count=0;
		}
	}
	fclose(fp);
	return count;
}

/*Set/Lease back memory to the system*/
robot::~robot(void){
delete [] name;
delete [] commands;
}

/*-----------------------------------------------------------*/
/* |"This assignment represents my own work in accordance  | */
/* |with Seneca Academic Policy"                           | */
/* |                                                       | */
/* |Signature: Freddy Cheungh                              | */
/*-----------------------------------------------------------*/



