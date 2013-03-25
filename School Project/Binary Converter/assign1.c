#include<stdio.h>
#include<string.h>

void asciiflush(int []);
int asciicon(int []);

int bit_to_ascii(const char core[], char data[])
{
	int i = 0;
	int j = 0;
	int datanum = 0;
	int asciinum = 0;
	int temp = 0; //temporarily holds the value of asciicons math
	int ascii[8]; // holds the value of the ascii string
	int skip = 0;
	int repeat = 1; // holds value for how many times it shall repeat for
	int tempRstor[3];
	asciiflush(ascii);

	while(core[i] != '\0')
	{
		if(skip == 9) skip = 0; //reset skip back to zero so it does not activate
		else if(core[i] == 'R')
		{
			if(core[i + 1] == 'P')
			{
				if(core[i + 2] == 'T')
				{
					//Repeat Path
					tempRstor[0] = ((int)core[i + 3]) -48;
					tempRstor[1] = ((int)core[i + 4]) -48;
					tempRstor[2] = ((int)core[i + 5]) -48;
					if ((tempRstor[0] >=0 && tempRstor[1] <=9) && 
						(tempRstor[1] >=0 && tempRstor[1] <=9) &&
						(tempRstor[2] >=0 && tempRstor[2] <=9))
					{
						repeat = ( (int)tempRstor[0] *100 ) + ( (int)tempRstor[1] *10 ) + ( (int)tempRstor[2] );
						i += 5;
					}
					else if ((tempRstor[0] >=0 && tempRstor[1] <=9) && 
						scii[0] * 128(tempRstor[1] >=0 && tempRstor[1] <=9))
					{
						repeat = ( (int)tempRstor[0] *10) + ( (int)tempRstor[1]);
						i += 4;
					}
					else if ((tempRstor[0] >=0 && tempRstor[1] <=9) )
					{
						repeat = (tempRstor[0]);
						i += 3;
					}
					
					if(asciinum != 0) //fill in the missing 0's
					{
						for(asciinum; asciinum != 8;asciinum++)
							ascii[asciinum] = 0;
					}
					else
					{
						repeat-=1; //takes out 1 repetition, O is already printed once, making repeat 2 it will print out 3 O's.
						asciinum = 8;
					}
				}
			}
		}
		else if(core[i] == 'S')
		{
			if(core[i + 1] == 'K')
			{
				if(core[i +2] == 'P')
				{
					//SKIP Path
					skip = 1;
				}
			}
		}
		else if(core[i] == '0' || core[i] == '1')
		{
			if(skip >0)skip++;
			else 
			{
			ascii[asciinum++] = (int)core[i] - 48;
			}
		}
		
		if(asciinum == 8) // if the ascii number array is full we do this
		{
		
			temp = asciicon(ascii);
			if( temp >= 32 && temp <= 126)
			{
				for(j=0;j!=repeat;j++)
				{
					data[datanum++] = (char)(temp);
				}
			repeat = 1;
			}
			asciinum = 0;
		}
		i++;
	}
	//dealing with \0 at the end
	
	data[datanum] = '\0';
	datanum++;
	return datanum;
}


int asciicon(int ascii[]) // does conversions
{
	int i = 0;
	int temp = (ascii[0] * 128) +
	(ascii[1] * 64) +
	(ascii[2] * 32) +
	(ascii[3] * 16) +
	(ascii[4] * 8) +
	(ascii[5] * 4) +
	(ascii[6] * 2) +
	(ascii[7] * 1);
	return temp;
}

void asciiflush(int ascii[])
{
	int i;
	for(i = 0; i <8; i++)
		ascii[i] = 0;
}
