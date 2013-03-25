#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include "disk.h"

using namespace std;

/* Defaul constructor */
disk::disk(){
	segm = new segment[20];	//Allocates memory for 20 segm
	strcpy(mode,"w");	//Sets mode to "w"
	seg_init=0;		//segment initiated
	max_seg=20;		//maximum amount of segments accepted
}
/* Constructor which accepts an integer, and a constant character */
disk::disk(int num_of_segments, const char* mod){
	segm = new segment[num_of_segments];	//Sets memory for segm based on the amount of segments sent from main
	if(mode[0]!='a' && mode[0]!='w'){	//if mode is not an 'a' or a 'w'
		strcpy(mode, "w");		//set mode to contain by default "w"
	}
	else{
		strcpy(mode,mod);		//else if it's 'w' or 'a', copy them to mod into my private variable mode
	}
	max_seg=num_of_segments;		//set maximum amount of segment to equal the number of segment sent from main
	seg_init=0;				//segment initialized will equal to 0
}
/* function which returns the mode stored by my private member variable "mode" */
const char* disk::get_mode()const{
	return mode;	//returns the mode
}
/* Will return a segment at the position indicated by the main */
segment disk::get_segment(int pos)const{
	if(pos >= 0 || pos <= seg_init){	//if the position is greater or equal to 0 "or" less or equal to to segment initialized 
		return segm[pos];		//returns the segm position
	}
	else{
		segment def; //create a new segment object or instance.
		return def;  //returns the default segment object
	}
}
/* Function which will return segments succesfully initialized */
int disk::get_segment_count()const{
	return seg_init;	//returns the number of segment initialized
}
/* Function that will return all segments */
const segment* disk::get_all_segments()const{
	return segm;	//returns all segment
}
/* Function that will write or append based on the mode. Will also count how many characters are in the segment */
int disk::access(const char fname[]){
	char fword[41];
	FILE *fp;
	int i,j,len,total=0,lc;
	fp = fopen(fname, mode);	//will open the file and act based on the mode (w to write and a to append)
	if(fp == NULL){			//if fp is unsuccessful
		cerr<< "ERROR: Could not open file " << fname	//print error message
		    <<" for writting/appending" << endl;
		exit(0);		//Exit the function
	}
	for(i=0;i<seg_init;i++){	//will loop while i is less than the segment initialized
		lc=0;
		for(j=0;j<10;j++){	//loop unti j is less than 10
			segm[i].get_word(fword,j);	//will call SEGMENT.CPP function. This will set that word to segment 
							//if it is available, else it will be an empty string.
			len=strlen(fword);		//calculate the length of each word returned by the get_word
			if(len){			//if len is available
				fprintf(fp, "%s%s", total && lc ? " " : "", fword);	//will write the string from fword, if total and lc is available, it will add an empty space else it will be an empty string.
				if(total&&lc){	//if total and lc is available
					total++;	//indent total
				}
				lc=1;		//set lc to 1
				total+=len;	//total adds lc
			}
		}
		if(total){		//if total is availabe
		fprintf(fp, "\n");	//prints a new line character
		total++;		//indent total
		}
	}
	return total;	//returns the total amount of characters
}
/* Copy Constructor: will create an exact same object also known as shallow copy */
disk::disk(const disk& rh){
	segm = new segment[max_seg];	//allocates dynamic memory for segm
	for(int i=0;i<max_seg;i++){	//Loop while 'i' is less than the max_seg
		segm[i] = rh.segm[i];	//sets each segm to equal each segm from the right hand side
	}
	strcpy(mode, rh.mode);		//string copy the value of the right hand side 'mode', into our shallow copy 
	seg_init = rh.seg_init;		//sets the shallow copy to equal the value of the seg_init in the right hand side
}
/* = Operator Overload */
void disk::operator=(const disk& from){
	segm = new segment[max_seg];	//Allocates dynamic memory for segm, setting it as big as the maximun amount permitted
	for(int i=0;i<max_seg;i++){	//Loops while 'i' is less than the maximum segment allowed
		segm[i]=from.segm[i];	//set's each segm to equal segm from the right hand side
	}
	strcpy(mode,from.mode);		//String copy the value of mode from the right hand side object to the current one(left side)
	seg_init = from.seg_init;	//Sets the right hand side object's segment initialized value to the left hand side one
}
/* += Operator Overload */
void disk::operator+=(const segment& seg){
	if(seg_init<max_seg){	//if segment initialiazed is less than the maximum segment allowed
		segm[seg_init] = segment(seg);	//segm initialized will equal to the segment on the right hand sided
		seg_init++;	//indent segment initialized. This will indicate that a segment is successfully added
	}
}
/* Destructor */
disk::~disk(){		
	if(segm!=NULL){		//If segm object is not null
		delete[] segm;	//Deallocate segm's memory
	}	
}
