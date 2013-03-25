/************************************************************************/
/*Assignment:     3                                                     */
/*Subject & code: OOP244B                                               */
/*Program:        robot.h                                               */
/*Due date:       April 06, 2012                                        */
/*Date submitted: April 13, 2012                                        */
/*Student name:   Freddy Cheungh                                        */
/*Student Id:     039-644-117                                           */
/*Instructor:     Danny Abesdris                                        */
/************************************************************************/

#include"command.h"

class robot{
        private:
                char* name;
                command* commands;
                char items[8][16];
                int treasure[3];
                int max_command;
                int number_command;

        public:
                robot(void);
                robot(int num_of_cmds, const char *nm);
                robot(const robot &);
                const char* get_name(void) const;
                command get_command(int pos) const;
                int get_command_count(void) const;
                void set_item(const char item[], int pos);
                const char* get_item(int pos) const;
                void set_treasure(int pos, int num);
                int get_treasure(int pos) const;
                int readfile(const char fname[]);
                void operator+=(command &);
                int operator==(char *);
                void operator=(const robot &);
                int execute(char *);
                ~robot(void);
};        
/*-----------------------------------------------------------*/
/* |"This assignment represents my own work in accordance  | */
/* |with Seneca Academic Policy"                           | */
/* |                                                       | */
/* |Signature: Freddy Cheungh                              | */
/*-----------------------------------------------------------*/

    
