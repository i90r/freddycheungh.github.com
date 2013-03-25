#include<stdio.h>

/**********************************************************
*                                                         *
*  Program :  a3_freddy_cheungh.c                         *
*                                                         *     
*  Author  :  Freddy Cheungh                              *
*                                                         *
*  Date    :  Sun. Dic 5/2011                             *
*                                                         *                     
*  Modified:  Sun. Dic 6/2011                             *
*                                                         *
*  Purpose :  Provide the user data about quote rooms,    *
*             average area of all the room quoted, a      *
*             total revenue if every user choose premium  *
*             as the paint type, and last, it prints out  *
*             all quotes in reverse order.                *
*                                                         *     
**********************************************************/

void clear_input(void)				/*This function clears out bad data input*/
{
       char junk;
       do{
              scanf("%c", &junk);   
	}while(junk !=  '\n');
}


void display_menu_get_option(int* poption)     /*Function in which ask the user the option he wants*/
{
printf("\n*****************************************************\n");
printf("*                                                   *\n");
printf("*       STUDENT PAINTERS SALES ANALYSIS MENU        *\n");
printf("*                                                   *\n");
printf("*  1. Display a particular quote.                   *\n");
printf("*  2. Display the average area to paint in a room   *\n");
printf("*     (include walls and ceiling (if selected)).    *\n");
printf("*  3. The total revenue if all customers had been   *\n");
printf("*     convinced to use premium paint for all walls. *\n");
printf("*  4. Print the file in reverse order most recent   *\n");
printf("*     quote first with highest letter down to 'A'.  *\n");
printf("*  9. Exit                                          *\n");
printf("*                                                   *\n");
printf("*****************************************************");

	do{
		printf("\n\nEnter Selection: ");
		scanf("%d", poption);
		clear_input();
			if(*poption != 1 && *poption != 2 && *poption != 3 && *poption!= 4 && *poption != 9)
			{
				printf("\n=====>ERROR: Option must be 1, 2, 3, 4 or 9 !!!");
			}
	}while(*poption != 1 && *poption != 2 && *poption != 3 && *poption!= 4 && *poption != 9);
}


void display_lines_of_quote(int quote[],char roomletter[], int length[], int width[],   /*Function which provides the user data for the quote he enters*/
char paint[], char ceiling[], double cost[], double setup_cost[],
int lines_in_file)
{
int i=0, user_quote=0, x=0;
do{
	printf("\nEnter the quote number (zero for main menu): ");
	scanf("%d", &user_quote);
	clear_input();
	x=0;
	i=0;
		do{
			if ( user_quote == quote[i] )
			{
				x++;
				if (x==1)
				{
					printf("\nQuote  Room  Length  Width  Paint  Ceiling     Cost   Setup\n");
					printf("=====  ====  ======  =====  =====  =======  =======   =====\n");
				}				
	printf("%5d%5c%7d%8d%6c%8c%11.2lf%9.2lf\n", quote[i], roomletter[i], length[i], width[i], paint[i], ceiling[i], cost[i], setup_cost[i]);
			}

			i++;
		}while(i<14);
	if(x==0 && user_quote != 0)
		printf("\nNo information on file for this quote!!!\n");
}while(user_quote!=0);
}

void display_average_room_area_to_paint(int quote[],char roomletter[], int length[], int width[], char paint[], char ceiling[], double cost[], double setup_cost[], int lines_in_file)				/*Provides the average of room area that is to be painted*/
{
double tot_ceil=0,ceil=0,avg=0, tot_area=0, area=0;
int i;
	for(i=0;i<14;i++){
		if(ceiling[i] == 'y')
		{
			ceil=length[i]*width[i];
		}
		area = (length[i] * 8) * 2 + (width [i] * 8) * 2 + ceil;
	tot_area += area;

			}	
		avg = tot_area / i;

printf("\n>>>>>>The average room requires %.2lf square feet to be painted.\n", avg);

}

void display_revenue_if_all_premium(int quote[],char roomletter[], int length[], int width[], char paint[], char ceiling[], double cost[], double setup_cost[], int lines_in_file)
{			/*Prompts the total revenue if the Premium quality is selected for every room*/
int i;
double grand_store=0 ,store_setup =0,tot_cost=0, tot_ceil=0,premium=0, ceil=0, wall=0, tot_wall=0, ceil_cost=0;
for(i=0;i<14;i++)
	{
		if(ceiling[i] == 'y')
		{
			ceil = (double)length[i] * (double)width[i];
			tot_ceil+=ceil;
		}

		wall=((double)length[i]*8)*2 + ((double)width[i]*8)*2;
		tot_wall+=wall;
		store_setup+=setup_cost[i];
	}

		tot_cost = tot_wall*0.1*2 + tot_ceil*0.05*2;

		grand_store = tot_cost + store_setup + ((tot_wall+tot_ceil)/200*40);

	printf("\n>>>>>>If all customers had selected the premium paint,\n");
	printf(">>>>>>the total revenue would have been $ %.2lf\n", grand_store);
}

void display_quotes_in_reverse_order(int quote[],char roomletter[], int length[], int width[], char paint[], char ceiling[], double cost[], double setup_cost[], int lines_in_file)
{			/*Print out the reverse order of the quotes*/
int i;

	printf("\nQuote  Room  Length  Width  Paint  Ceiling     Cost   Setup\n");
	printf("=====  ====  ======  =====  =====  =======  =======   =====\n");
		for(i=13;i>=0;i--)
		{
			printf("%5d%5c%7d%8d%6c%8c%11.2lf%9.2lf\n", quote[i], roomletter[i], length[i], width[i], paint[i], ceiling[i], cost[i], setup_cost[i]);
		}

}

main()			/*Beggining of main*/
{
FILE* fp;
int i=0, y, option, quote[200], length[200], width[200], lines_in_file;
double cost[200], setup_cost[200];
char roomletter[200], paint[200], ceiling[200];

        fp=fopen("/home/don.frey/quotes/quotes.data","r");		//Load file called quotes.data, and reads it.
                if(fp == NULL)						//If no file or permission deny print the error below
                {
                        printf("Error: could not open file!!! \n");	//Error if file couldn't be open.
                }
                else{    						
                    do{  						//Beggining of the Do-While. In order to store every value correctly
                              y=fgetc(fp);				//Gets the first character
                                        if(y!=EOF)			//If the variable 'y' is not End of File
					{

                                        fscanf(fp,"%d,%c,%d,%d,%c,%c,%lf,%lf\n", &quote[i], &roomletter[i], &length[i], &width[i], &paint[i], &ceiling[i], &cost[i], &setup_cost[i]);									   //Scan and put every corresponded data to every array

                                        quote[i]+=500;			//Add 500 to quotes, due that fgetc takes out 500 from it
                                        i++;				//Add 1 to 'i'. Doing this, it will keep track of everyline. 'i' also stands for number of line.
                                        }
                        }while(y!=EOF);					//Load everything until it hits the end of the file
                }

	do{
		display_menu_get_option(&option); 
		i--;					//takes out 1 from 'i'. In this stance 'i' has the value of 14.
		lines_in_file = i;			
		lines_in_file++;

		if (option == 1)
		{	 
			display_lines_of_quote(quote, roomletter, length, width, paint, ceiling, cost, setup_cost,lines_in_file);
		}
			if (option == 2)
			{
				display_average_room_area_to_paint(quote, roomletter, length, width, paint, ceiling, cost, setup_cost, lines_in_file);
			}
				if (option == 3)
				{	
					display_revenue_if_all_premium(quote, roomletter, length, width, paint, ceiling, cost, setup_cost, lines_in_file);
				}
					if (option == 4)
					{
						display_quotes_in_reverse_order(quote,roomletter, length, width, paint, ceiling, cost, setup_cost, lines_in_file);
					}
		}while(option!=9);    // if user enters 9, program ends.
}




