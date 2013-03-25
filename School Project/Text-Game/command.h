/************************************************************************/
/*Assignment:     2                                                     */
/*Subject & code: OOP244B                                               */
/*Program:        command.h                                             */
/*Due date:       February 27, 2012                                     */
/*Date submitted: February 28, 2012                                     */
/*Student name:   Freddy Cheungh                                        */
/*Student Id:     039-644-117                                           */
/*Instructor:     Danny Abesdris                                        */
/************************************************************************/
class command{
		char keyword[41];
		char modifiers[5][21];
	public:
		command(void);
		command(char data[]);
		void init(void);
		void init(char data[]);
		int modifier_count(void);
		int valid_command(char phrase[]);
		void get_keyword(char s[]);
		void get_modifier(char s[], int pos);
		~command(void);
};
/*-----------------------------------------------------------*/
/* |"This assignment represents my own work in accordance  | */
/* |with Seneca Academic Policy"                           | */
/* |                                                       | */
/* |Signature: Freddy Cheungh                              | */
/*-----------------------------------------------------------*/

