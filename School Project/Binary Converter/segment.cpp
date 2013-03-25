/****************************************/
/*Program Name:      segment.cpp        */
/*Student Name:      Freddy Cheungh     */
/*Student ID:        039-644-117        */
/*Teacher Name:      Mark Buchner       */
/*Last Modification: July 13, 2012      */
/****************************************/
#include<stdio.h>
#include<string.h>
#include"segment.h"
#include"assign1.c"
void segment::initialize(const char core[][2000], int num){
 	int i;
 	for(i=0;i<num && i<10;i++){ //transform the string of binary into string of characters
		bit_to_ascii(core[i],words[i]);
	}
	if(i<10){	//if not all 10 words are filled with word, remaining will be fill with empty strings
		do{
			strcpy(words[i],"");
			i++;
		}while(i<10);
	}
}

void segment::initialize(){ //Initialize every word array into empty string
	int j;
	for(j=0; j<10; j++){
		strcpy(words[j],"");
	}
}

int segment::match(const char word[]){ //Match the word sent by main with the one transformed
	int k=0, ret_val;
	if(strlen(word)>0){
		do{
			if(strstr(words[k], word)){ //compares and returns a pointer of the first letter of the string word.
				ret_val=k;
				k=10;
			}
			else
			 	ret_val=-1;
			k++;
		}while(k<10);
	}
	return ret_val; //returns a real value if match was found(position) or a false value if match was not found (-1)
}
void segment::sort(){	//used the bubble sort method.
	int m=0, n=0;
	char temp[50];
	while(m<10){    //Used to switch characters from one array to another.
		for(n=m+1; n<10; n++){
			if(strcmp(words[m], words[n])>0){
				strcpy(temp, words[m]);
				strcpy(words[m], words[n]);
				strcpy(words[n], temp);
			}
		}
	m++;
	}
}

void segment::get_word(char s[], int pos){ //Copies the position of the words array into s
	if(pos<10 && pos>=0){
		strcpy(s, words[pos]);
	}
	else //if position is out of range, set/copy an empty string into s
		strcpy(s,"");
}

int segment::set_word(const char s[], int pos){ //copies the word string sent by main, to the position of words given
	int ret_val;
	if(pos<10 && pos>=0){ //if position is in range, copy the word stored in s, to the position of my array words.
		strcpy(words[pos],s);
		ret_val=1;
	}
	else //if position out of range, set a return value to 0.
		ret_val=0;
	return ret_val;
}
int segment::set_char(int word_pos, int char_pos, char value){ 
//Set a character to one of the word position and character position given. In other words, changes one of the characters
//stored in my array
	int ret_val;
	if(word_pos <10 && word_pos>=0){ //as long as the position of the word doesn's exceed the limit
		if(char_pos<strlen(words[word_pos]) && char_pos>=0){ //also, if there is more than 0 or more characters
			words[word_pos][char_pos]=value;
			ret_val=1;
		}
		else 
			ret_val=0;
	}
	return ret_val;
}

char segment::get_char(int word_pos, int char_pos){ //retrieves a character by the position of the word and character given
	char ret_char;
	if(word_pos<10 && word_pos>=0){
		if(char_pos<strlen(words[word_pos]) && char_pos>=0){
			ret_char=words[word_pos][char_pos];
		}
		else 
			ret_char='\0'; //returns a null value if no character was selected.
	}
	return ret_char;
}

