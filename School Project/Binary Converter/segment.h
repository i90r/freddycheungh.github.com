/****************************************/
/*Program Name:      segment.h          */
/*Student Name:      Freddy Cheungh     */
/*Student ID:        039-644-117        */
/*Teacher Name:      Mark Buchner       */
/*Last Modification: July 13, 2012      */
/****************************************/
class segment{
		char words[10][40];
	public:
		void initialize(const char[][2000], int num);
		void initialize();
		int match(const char word[]);
		void sort();
		void get_word(char s[], int pos);
		int set_word(const char s[], int pos);
		int set_char(int word_pos, int char_pos, char value);
		char get_char(int word_pos, int char_pos);
};	
