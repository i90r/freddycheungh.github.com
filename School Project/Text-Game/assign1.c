/************************************************************************/
/*Assignment:     1                                                     */
/*Subject & code: OOP244B                                               */
/*Program:        assign1.c          					*/
/*Due date:       February 6, 2012					*/
/*Date submitted: February 7, 2012 					*/
/*Student name:   Freddy Cheungh 			 	        */
/*Student Id:     039-644-117		         		        */
/*Instructor:     Danny Abesdris                                        */
/*Purpose:        Process information for some experimental robot of 	*/
/*		  The Robotics Department at M.I.T. Provide the robots  */
/*		  the hability to count words and also match the 	*/
/*		  corresponded words.                                   */
/************************************************************************/
#include<stdio.h>
#include<ctype.h>
int words(char sentence[])     /*Function used to count the number of words in a sentece*/
{
int i=0, num_words=0;

    for(i;sentence[i];i++)     /*Transform Tabs and New lines into spaces*/
    {
        if(sentence[i] =='\t'|| sentence[i] == '\n') sentence[i] = ' ';
    }
        i=-1;
	do{
               i++;
			
		if(sentence[i] == ' ' || sentence[i] == '\0')
		{
 	               i++;
                }
			
                else if(sentence[i] != ' ' && sentence[i] != '\0')
                {
                        num_words++;
		        while(sentence[i] != ' ' && sentence[i] != '\0')
                        {
                                i++;
                        }
                }
        }while(sentence[i] != '\0');

return num_words;
}

int match(char str[], char sentence[], int n)  /*Function used to compare words between a sentecen and a string given*/
{
int x=0, j=0, i=0, match=0, num_words=0, str_length=0, y=0;
	
	for(j;str[j];j++)   /*Change all Tabs and New lines into spaces*/
   	{
       		if(str[j] =='\t' || str[j] == '\n') str[j] = ' ';
   	}	
 	   j=0;
   
	for(j;sentence[j];j++)
   	{
       		if(sentence[j] =='\t'|| sentence[j] == '\n') sentence[j] = ' ';
   	}
		
	do{
		if(sentence[i] == ' ' || sentence[i] == '\0')
			{
				i++;
			}
		else if(sentence[i] != ' ' && sentence[i] != '\0')
		{
			num_words++;
                        while(sentence[i] != ' ' && sentence[i] != '\0')

			{
				i++;
			}
		}
	}while(sentence[i] != '\0');

	if (num_words < n)
	{	
		return 0;
	}
	else if(n <= 0)
	{
		return 0;
	}
		i=0;     
		num_words=0;
	
	do{
	    	if(sentence[i] != ' ' && sentence[i] != '\0')
                {
                        num_words++;
			if(num_words != n)
                        {
                        	while(sentence[i] != ' ' && sentence[i] != '\0')
                                {
					i++;
              			}		
                        }
                }
                else 
		{
                        while(sentence[i] == ' ' || sentence[i] == '\0')
			{
			        i++;
                        }
                }
        }while(num_words != n);
	y=0;
	while (str[y])	 /*toupper used to upper case all characters in the string*/
	{
		str[y] = toupper(str[y]);
		y++;
	}	
	y=0;
	while (sentence[y])
        {
                sentence[y] = toupper(sentence[y]);
                y++;
        } 

	for(y=0; str[y]!='\0';y++) //Store the length of the word to be match.
	{
		str_length++; 
	}
	
	x=str_length; 
	
	if(str[x-1]!=' ') 
        {
            str[x]=' ';
            str[x+1]='\0';
        }
        else
        {
            x-=1;
        }

	j=0;
	while(str[j] != '\0') /*Store matching character between the arrays*/
	{
        	if(str[j] == sentence[i])
			match++;
        		j++;
			i++;

	}
	if(sentence[i-1] == '\0') 
	{
		match++;
	}
	
	if(sentence[i-1] == ' ')i-=1;
	if(match == (x+1))
	{
		return 1;
    	}
	else
	{
		return 0;
	}
}
/*-----------------------------------------------------------*/
/* |"This assignment represents my own work in accordance  | */
/* |with Seneca Academic Policy"			   | */
/* |							   | */
/* |Signature: Freddy Cheungh 				   | */
/*-----------------------------------------------------------*/
