/************************************************************************/
/*Assignment:     2                                                     */
/*Subject & code: OOP244B                                               */
/*Program:        command.cpp                                           */
/*Due date:       February 27, 2012                                     */
/*Date submitted: February 28, 2012                                     */
/*Student name:   Freddy Cheungh                                        */
/*Student Id:     039-644-117                                           */
/*Instructor:     Danny Abesdris                                        */
/*Purpose:        Provide an improvement for assign1.c allowing the     */
/*                user to set a series of array with one keyword and 5  */
/*                modifiers. The program will detect and match the      */
/*                keyword and the modifiers.                            */
/************************************************************************/
#include <stdio.h>
#include <string.h>
#include "command.h"
/* Prototype for functions on Assignment 1 (assign1.c)*/
int words(char sentence[]);

int match(char str[], char sentence[], int n);

command::command(){
	init();
}

command::command(char data[]){
	init(data);
}


/*Initialiaze keyword and its moditifiers to its respective words*/
void command::init(){
	strcpy(keyword, "go");
	strcpy(modifiers[0], "north");
	strcpy(modifiers[1], "south");
	strcpy(modifiers[2], "east");
	strcpy(modifiers[3], "west");
	strcpy(modifiers[4], "start");
}

/*Function Used to scan and copy the keyword and modifiers to its container*/

void command::init(char data[]){
int i=0, k=0, j=1;
for(i=0;j!=0;i++) 
{
	if(data[i]!=';' && data[i]!='\0')
	{
		keyword[k]=data[i];
		k++;	
	}
	else{
		keyword[k] = '\0';
		j=0;
	}
}
int a=0, b=0; 
for(i;i<=strlen(data);i++) 
{
	if(data[i]!=';' && data[i]!='\0') 
	{
		modifiers[a][b] = data[i]; //store modifiers presented on the string.
		b++;
	}
	else
	{
		modifiers[a][b] = '\0';	//if no modifiers are found, place a Null space.
		a++;	//increment 'a' changing the container of the modifiers.
		b=0;
	}
}

}
/*Counts how many modifiers are being used*/
int command::modifier_count(){
int x=0, mod_count=0;
for(x=0;x<5;x++)
{
	if(modifiers[x][0]!='\0')
	{
		mod_count++;
	}
}
return mod_count;
}
/*Returns a number based on the keyword(1) added to the modifiers position(1-5)
if no keyword is provided, automatically returns a 0.*/
int command::valid_command(char phrase[]){
int count=0, x=0,final=0, n; 
	for(n=1; n <= words(phrase) && x==0; n++)
	{
		x = match(keyword, phrase, n); //look for keyword, if keyword is found x=1 else x=0.
	}
	if(x==1){ //if keyword is found, look for modifiers.
		for(n; n<=words(phrase) && count == 0;n++){
			if(match(modifiers[0],phrase,n)==1)
			{
				count=1;
			}
			if(match(modifiers[1],phrase,n)==1)
			{
				count=2;
			}
			if(match(modifiers[2],phrase,n)==1)
			{
				count=3;
			}
			if(match(modifiers[3],phrase,n)==1)
			{
				count=4;
			}
			if(match(modifiers[4],phrase,n)==1)
			{
				count=5;
			}
		}
	}
	final = x + count; //Add keyword value and the modifiers value.
	return final;
}
/*Store the keyword on an array.*/
void command::get_keyword(char s[])
{
	strcpy(s, keyword);
}
/*Stores the modifier located on the position given*/
void command::get_modifier(char s[], int pos)
{
	strcpy(s, modifiers[pos]);
}
/*Destroys element after the end of the scope of main.*/
command::~command(void){
}
/*-----------------------------------------------------------*/
/* |"This assignment represents my own work in accordance  | */
/* |with Seneca Academic Policy"                           | */
/* |                                                       | */
/* |Signature: Freddy Cheungh                              | */
/*-----------------------------------------------------------*/

