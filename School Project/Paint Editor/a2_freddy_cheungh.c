#include<stdio.h>

/**********************************************************
*                                                         *
*  Program :  a2_freddy_cheungh.c                         *
*							  *	
*  Author  :  Freddy Cheungh                              *
*							  *
*  Date    :  Sun. Nov 20/2011                            *
*							  *			
*  Modified:  Sun. Nov 20/2011                            *
*							  *
*  Purpose :  Provide the customer the total cost for     *
*             painting the number of room he needs. It    *
*             also provides the total area of the rooms,  *
*             keeping track of the largest room and the   *
*             smallest one.                               *
*							  *	
**********************************************************/

/*Beginning of the program*/

void initialize_house_totals(           /*Function to initialize values*/
			     double* pgrand_total_area,
			     int* plargest_area, char* proomid_largest,
			     int* psmallest_area, char* proomid_smallest,
			     double* ptot_premium_cost,
			     double* ptot_regular_cost,
			     double* ptot_basic_cost,
			     double* ptot_labour_cost,
			     double* ptotal_area,
			     double* ppremium_cost,
		   	     double* pregular_cost,
			     double* pbasic_cost)
{
	*ptotal_area = 0;
	*pgrand_total_area =0;
	*plargest_area=0;
	*psmallest_area=999999;
	*ptot_premium_cost=0;
	*ptot_regular_cost=0;
	*ptot_basic_cost=0;
	*ptot_labour_cost=0;
	*ppremium_cost=0;
	*pregular_cost=0;
	*pbasic_cost =0;
	*proomid_largest;
	*proomid_smallest;
}

int get_num_rooms(void)			/*Function for getting how many rooms are needed to paint*/
{

int num_rooms, room_id=65;
do{
	printf("\n>>> How many rooms are there in the house? ");
	scanf("%d", &num_rooms);
		if(num_rooms <= 0)
		printf("Error! room must be bigger than 0\n");
			if(num_rooms >= 27)
			printf("Error! room must be less than 27\n");
}while(num_rooms < 0 || num_rooms >27);
	num_rooms += 65;
	printf(">>> you want to paint rooms ");
		do {
		printf("%c",room_id);
			if(room_id == (num_rooms-2))
			printf(" and ");
				else if (room_id == (num_rooms-1))
				printf(".\n");
					else 
					printf(",");
					room_id++;  //Adds one to room_id.
}while (num_rooms != room_id);

	return num_rooms;

}

int get_room_size(char room_id, int* plength, int* pwidth) /*Function to determine length and width of a room, and returns to main*/
{
int room_size;
do{	
	printf("Enter length and width of room %c (Followed by a comma) in feet: ", room_id);
	scanf("%d, %d", plength, pwidth);
		if (*plength <= 0)
		printf("###Error! Length must be a postive number\n");
			if (*pwidth <= 0)
			printf("###Error! Width must be a postive number\n");
}while (*plength <= 0 || *pwidth <= 0);
	return room_size;
}

char get_quality_paint() 				 /*Function for getting a quality letter, afterward it sends back to main*/
{
char quality;
do{       
	printf("Enter quality (p:premium, r:regular, b:basic): ");
        scanf(" %c", &quality);
    		if(quality != 'p' && quality != 'r' && quality != 'b')
        	printf("###Error! Quality must be p, r or b!\n");
        }while(quality != 'p' && quality != 'r' && quality != 'b');
      
	return quality;
}


void get_paint_ceiling_yn(char* panswer)                 /*Function to determine if ceiling is to be painted or not. Does not return because of void*/
{
char ceiling_yn; 
do{
	printf("Enter if ceiling is to be painted (y-yes / n-no); ");
	scanf(" %c", panswer);
		if (*panswer != 'y' && *panswer != 'n')
		printf("###Error! Enter y or n!\n");
}while(*panswer != 'y' && *panswer != 'n');
}

void calc_area(               				 /*Determines the size of the room to paint. If user enter 'y' for ceiling, it determines the ceiling area also.*/
		double dlength, double dwidth, char paint_ceiling_y_n,
		int* pwall_area_to_paint, int* pceiling_area_to_paint)
{
double ceiling_paint=20;

*pwall_area_to_paint = 2 * (8 * dlength) + 2 * (8 * dwidth);
        if (paint_ceiling_y_n == 'y')
	*pceiling_area_to_paint = dlength * dwidth;
	        else if (paint_ceiling_y_n == 'n')
                *pceiling_area_to_paint = 0;
}

void calculate_costs(					 /*calculate the cost of wall and ceiling to be painted, adding the quality selected by the user*/
		     int wall_area_to_paint, int ceiling_area_to_paint, char paint_quality, char roomid,
		     double* ppremium_cost,
		     double* pregular_cost,
	       	     double* pbasic_cost,
		     double* plabour_cost,
		     double* ptotal_area,
		     double* ptotal_cost)
{
double ceiling_p, wall;
wall=wall_area_to_paint;
							 /*Formulas for calculating total area, labour cost, ceiling cost and all the paint quality cost*/
ceiling_p = ((ceiling_area_to_paint * 2 * 20)/400);
	if (paint_quality == 'p')
{	
                *ppremium_cost += ((wall/400)*(40 * 2));
}
	if (paint_quality == 'r')
{
                *pregular_cost += ((wall/400)*(30 * 2));
}
	if (paint_quality == 'b')
{
                *pbasic_cost += ((wall/400)*(20 * 2));
}
	*ptotal_area += wall_area_to_paint + ceiling_area_to_paint; /*Formulas for calculating total area, labour cost, ceiling cost and all the paint quality cost*/
	*plabour_cost = (100+((*ptotal_area/200)*40));
	*pbasic_cost += ceiling_p;
	*ptotal_cost = *ppremium_cost + *pregular_cost + *pbasic_cost + *plabour_cost;
}

void accumulate_totals(				/*Stores old value, add them together*/
			int wall_area_to_paint, int ceiling_area_to_paint, int total_area,
			double premium_cost, double regular_cost, double basic_cost, double labour_cost, double total_cost,
			double* pgrand_total_area,
			double* ptot_premium_cost,
			double* ptot_regular_cost,
			double* ptot_basic_cost,
			double* ptot_labour_cost,
			double* pgrand_total_cost)

{
*pgrand_total_area = total_area;
*ptot_premium_cost = premium_cost;
*ptot_regular_cost = regular_cost;
*ptot_basic_cost = basic_cost;
*ptot_labour_cost = labour_cost;
*pgrand_total_cost = total_cost;
}

void update_room_largest_smallest_area(		/*Updates the value for the largest room and the smallest room, also keeps track with their ID*/
					char room_id,
					int wall_area_to_paint,
					int ceiling_area_to_paint,
					int* plargest_area,
					char* proomid_largest,
					int* psmallest_area,
					char* proomid_smallest)
{
int room_tot_area=0;

room_tot_area = wall_area_to_paint + ceiling_area_to_paint;

	if (*plargest_area <= room_tot_area)
	{
		*plargest_area = room_tot_area;
		*proomid_largest = room_id;
	}
		if (*psmallest_area >= room_tot_area)
		{
			*psmallest_area = room_tot_area;
			*proomid_smallest = room_id;
		}
}

void print_quote(		/*Function used for printing results*/
		int room_num,
		int grand_total_area,
		int largest_area,
		char roomid_largest,
		int smallest_area,
		char roomid_smallest,
		double tot_premium_cost,
		double tot_regular_cost,
		double tot_basic_cost,
		double tot_labour_cost,
		double grand_total_cost)

{
printf("*******************************************************************\n");
printf("*           QUOTE FOR PAINTING A HOUSE OF %d ROOMS                 *\n",( room_num-65));
printf("*                                                                 *\n");
printf("*Total Area: %d sq ft                                            *\n", grand_total_area);
printf("*  - the largest area to be painted:  %d sq ft (room %c)          *\n", largest_area, roomid_largest);
printf("*  - the smallest area to be painted: %d sq ft (room %c)          *\n", smallest_area, roomid_smallest);
printf("*                                                                 *\n");
printf("*Premium paint cost:    $%6.2lf                                   *\n", tot_premium_cost);
printf("*                                                                 *\n");
printf("*Regular paint cost:    $%6.2lf                                   *\n", tot_regular_cost);
printf("*                                                                 *\n");
printf("*Basic paint cost:      $%6.2lf                                   *\n", tot_basic_cost);
printf("*                                                                 *\n");
printf("*Labour costs:          $%6.2lf                                   *\n", tot_labour_cost);
printf("*                                                                 *\n");
printf("*TOTAL COST:            $%6.2lf                                   *\n", grand_total_cost);
printf("*******************************************************************\n");
}

void get_another_house_yn(char* panother_house_yn)
{
char another_house_yn;
	printf(">>>>>> Do you want to have another house painted (y-yes / n-no)? ");
	scanf(" %c", panother_house_yn);
        	if (*panother_house_yn == 'n')
		printf(">>>>>> HAVE A NICE DAY!\n");
}
//Start of Main
main()
{/*declation of int, char, double*/
char paint_ceiling_yn, house, quality,  answer, roomid_largest, roomid_smallest;
int i, size, length, room_id,  ceiling_a, width, wall, ceiling, paint_q, largest_area, smallest_area;
double dlength, dwidth, premium_cost=0, regular_cost=0, basic_cost=0, labour_cost=0, tot_area=0, tot_cost=0, grand_tot_area=0, tot_premium_cost=0, tot_regular_cost=0, tot_basic_cost=0, tot_labour_cost=0, grand_total_cost=0;

	printf("\n#### PAINTING COST ESTIMATOR ####\n");

do{  //do-while
	initialize_house_totals( //initialize old values to 0
				&grand_tot_area,
				&largest_area, &roomid_largest,
				&smallest_area, &roomid_smallest,
				&tot_premium_cost,
				&tot_regular_cost,
				&tot_basic_cost,
				&tot_labour_cost,
				&tot_area,
				&premium_cost,
				&regular_cost,
				&basic_cost);

	room_id = get_num_rooms(); //first function. It ask for how many rooms the customer needs to paint
	
		for (i=65;i!=room_id;i++) //for loop, indicating it needs to loop all the time needed to fulfill the room entered from the previous function
		{
			size = get_room_size(i, &length, &width);
		
			quality = get_quality_paint(); //gets the quality of the room to be painted
		
			get_paint_ceiling_yn(&answer); //ask if ceiling is also painted
		
			calc_area(length, width, answer, &wall, &ceiling);  // calculates area of wall and ceiling
		
			calculate_costs(wall, ceiling, quality, i, &premium_cost, &regular_cost, &basic_cost, &labour_cost, &tot_area, &tot_cost); // calculate the cost of paint for wall and ceiling
			
			accumulate_totals( //hold on values adding old values
					  wall, 
					  ceiling, 
					  tot_area, 
					  premium_cost, 
					  regular_cost, 
					  basic_cost, 
					  labour_cost, 
					  tot_cost, 
					  &grand_tot_area, 
					  &tot_premium_cost,
					  &tot_regular_cost, 
					  &tot_basic_cost, 
					  &tot_labour_cost, 
					  &grand_total_cost);
		
			update_room_largest_smallest_area(  //keeps track of the smallest room value and the bigest room value
						       	  i,
							  wall,
							  ceiling,
							  &largest_area,
							  &roomid_largest,
							  &smallest_area,
							  &roomid_smallest);
		} //end of the for loop

		print_quote(		//print the results
			    room_id,
			    grand_tot_area, 
			    largest_area, 
			    roomid_largest, 
			    smallest_area, 
		       	    roomid_smallest, 
			    tot_premium_cost, 
			    tot_regular_cost, 
			    tot_basic_cost, 
			    tot_labour_cost, 
			    grand_total_cost);

		get_another_house_yn(&house); //ask if another house is needed to paint

}while(house == 'y'); //if another house is needed repeats the loop.
}
