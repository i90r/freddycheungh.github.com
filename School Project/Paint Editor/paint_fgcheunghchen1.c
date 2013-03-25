#include<stdio.h>
main()  /*Declare values as integers and doubles*/
{ 
double c_wall_cost=0, c_wall_area=0, c_total_area=0, c_total_area_cost=0, c_Tot_cost=0, c_labour_cost=0;    /*C stands for Current*/  
double f_wall_cost=0, f_wall_area=0, f_total_area=0, f_total_area_cost=0, f_Tot_cost=100, f_labour_cost=100;   /*F stands for Final*/
double Quality1=0, Quality2=0, Quality3=0, i_quality1=0, i_quality2=0, i_quality3=0, f_quality1=0, f_quality2=0, f_quality3=0;   /*I stands for inicial*/
double premium_c=40, regular_c=30, basic_c=20, paint_cost=0, length=0, width=0; 
double ceiling_cost, f_ceiling=0, i_ceiling=0, ceiling_area=0;
int room=0, ceiling_paint=20, labour_set=100, quality=0, heigth=8, ceiling=0;
	
	printf("PAINTING COST ESTIMATOR\n");
do{  //Start of a Do - While
		// Start reseting values after the while loop of the do - while, this only happens if another room is to be painted
	i_quality1=0;   
	i_quality2=0;
	i_quality3=0;
	c_wall_cost=0;
	c_wall_area=0;
	c_total_area=0;
	c_total_area_cost=0;
	c_Tot_cost=0;
	c_labour_cost=0;    
	i_ceiling=0;  
	ceiling_area=0;	

	printf("Enter length of room in feet: ");
       	scanf("%lf", &length);
	while (length <= 0)  //loops if number entered is negative or 0
	{ 
		printf("Error! Length must be a positive value\n"); 
		printf("Enter length of room in feet: ");
		scanf("%lf", &length);
	}

	printf("Enter width of room in feet: ");
       	scanf("%lf", &width);
	while (width <= 0)  //loops if number entered is negative or 0
	{ 
		printf("Error! Width must be a positive value\n");
		printf("Enter width of room in feet: ");
		scanf("%lf", &width);
	}
	printf("Enter quality (1:premium, 2:regular, 3:basic): ");
 	scanf("%d", &quality);
	while (quality <=0 || quality >3)  //loops if number entered is not 1, 2 or 3
	{ 
		printf("Error! Quality must be between 1 and 3\n");
		printf("Enter quality (1:premium, 2:regular, 3:basic): ");
		scanf("%d", &quality);
	}
	if (quality == 1 || quality !=2 || quality !=3)
		Quality1 = premium_c;        
	if (quality == 2 || quality !=1 || quality !=3) 
		Quality2 = regular_c;        
	if (quality == 3 || quality !=2 || quality !=1)
		Quality3 = basic_c;       

	printf("Enter if ceiling to be painted (1-yes / 2-no): ");
       	scanf("%d", &ceiling);
	while (ceiling < 1 || ceiling > 2)  //loops if number entered is not 1 or 2
	{ 
		printf("Error! Enter 1 to paint ceiling, 2 for no\n");
		printf("Enter if ceiling to be painted (1-yes/ 2-no): ");
		scanf("%d", &ceiling);
	}

	if (ceiling == 1) 
		ceiling_area = length * width; //formula for calculating ceiling_area 

	if (ceiling == 2) 
		ceiling_area = 0;

	printf("Another room to be entered (1-yes / 2-no): ");
	scanf("%d", &room);
	while (room < 1 || room > 2)  //loops if number entered is not 1 or 2
	{ 
		printf("Error! Enter 1 for another room, 2 for no more\n");
		printf("Another room to be entered (1-yes / 2-no): ");
		scanf("%d", &room);
	}
	
	if (quality == 1)
		i_quality1 = ((2*(length*heigth)+2*(heigth*width))/400)*(Quality1*2); //formulas for calculating price for the qualities
	else if (quality == 2)      
		i_quality2 = ((2*(length*heigth)+2*(heigth*width))/400)*(Quality2*2); 
	else if (quality == 3)
		i_quality3 = ((2*(length*heigth)+2*(heigth*width))/400)*(Quality3*2); 
	if(ceiling == 1)
		ceiling_cost = ceiling_paint*(((length*width)*2)/400); //formula for calculating the cost of ceiling in case that ceiling needs to be painted
	else 
		ceiling_cost = 0;

	//formulas used to calculate the inicial results of area, labour and total cost

	c_wall_area = 2*(length*heigth) + 2*(heigth*width);
	c_total_area = 2*(length*heigth) + 2*(heigth*width) + ceiling_area;
	i_ceiling = i_quality3 + ceiling_cost;
	c_labour_cost =((c_total_area/200)*40);
	c_Tot_cost = c_labour_cost + i_quality1 + i_quality2 + i_quality3 + ceiling_cost;

	//formulas used to calculate the final values of area, labour and total cost that are going to be print

	f_total_area += c_total_area;
	f_quality1 += i_quality1; 
	f_quality2 += i_quality2;
	f_ceiling += i_ceiling;
	f_labour_cost += c_labour_cost;
	f_Tot_cost += c_Tot_cost;

}while (room == 1); //End of the Do - While. Loops back if customer wants to paint another room

	printf("RESULTS:\n");
	printf("Total Area: %.0lf sq ft\n", f_total_area);
	printf("Premium paint cost:      $%.2lf\n",f_quality1);
	printf("Regular paint cost:      $%.2lf\n",f_quality2);
	printf("Basic paint cost:        $%.2lf\n",f_ceiling);
	printf("Labour costs:            $%.2lf\n",f_labour_cost);
	printf("TOTAL COST:              $%.2lf\n",f_Tot_cost);
}
	//End of the program
