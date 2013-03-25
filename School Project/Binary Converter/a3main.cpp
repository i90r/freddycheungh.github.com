///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  File:        a3main.cpp VERSION 1.00                                     //
//  Written By:  Danny Abesdris                                              //
//  Date:        June 3rd, 2012                                              //
//  Main program to test assignment #3 for OOP244, Summer 2012.              //
//                                                                           //
//  You must not modify this file!                                           //
//                                                                           //
//  This program assumes that you have written the code for a class          //
//  called 'disk' and have stored the declaration for that class in a        //
//  file which must be called "disk.h"                                       //
//                                                                           //
//  Your program must be stored in a file called disk.cpp                    //
//  In your disk.cpp file, you must include the statement:                   //
//  #include "disk.h"                                                        //
//                                                                           //
//  NOTE: You may compile and run this program on either the UNIX system     //
//        on ZENIT or in WINDOWS using Visual Studio 2010 or                 //
//        another C++ compiler                                               //
//                                                                           //
//                                                                           //
//  To compile your assignment:                                              //
//  On zenit   : c++ a3main.cpp disk.cpp segment.cpp assign1.c -o a3main     //
//  On windows : cl  a3main.cpp disk.cpp segment.cpp assign1.c               //
//                                                                           //
//  This command will compile both files and link them together into an      //
//  executable (binary) file called "a3main"                                 //
//  To run your program, at the command prompt type:                         //
//  /home/students/jsmith>a3main                                             //
//                                                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

#include "disk.h"

int main( ) {
   const char core_data[ ][1][2000] = {
      {  "00100011" /*  35 = '#' */
         "01101001" /* 105 = 'i' */
         "01101110" /* 110 = 'n' */
         "01100011" /*  99 = 'c' */
         "01101100" /* 108 = 'l' */
         "01110101" /* 117 = 'u' */
         "01100100" /* 100 = 'd' */
         "01100101" /* 101 = 'e' */
         "00100000" /*  32 = ' ' */
         "00111100" /*  60 = '<' */
         "01110011" /* 115 = 's' */
         "01110100" /* 116 = 't' */
         "01100100" /* 100 = 'd' */
         "01101001" /* 105 = 'i' */
         "01101111" /* 111 = 'o' */
         "00101110" /*  46 = '.' */
         "01101000" /* 104 = 'h' */
         "00111110" /*  62 = '>' */
         "00000000" /*  0 = '\0' */
      },

      {  "01101001" /* 105 = 'i' */
         "01101110" /* 110 = 'n' */
         "01110100" /* 116 = 't' */
         "00100000" /*  32 = ' ' */
         "01101101" /* 109 = 'm' */
         "01100001" /*  97 = 'a' */
         "01101001" /* 105 = 'i' */
         "01101110" /* 110 = 'n' */
         "00101000" /*  40 = '(' */
         "00100000" /*  32 = ' ' */
         "00101001" /*  41 = ')' */
         "00100000" /*  32 = ' ' */
         "01111011" /* 123 = '{' */
         "00000000" /*  0 = '\0' */
      },

      {  "00100000" /*  32 = ' ' */
         "00100000" /*  32 = ' ' */
         "00100000" /*  32 = ' ' */
         "01110000" /* 112 = 'p' */
         "01110010" /* 114 = 'r' */
         "01101001" /* 105 = 'i' */
         "01101110" /* 110 = 'n' */
         "01110100" /* 116 = 't' */
         "01100110" /* 102 = 'f' */
         "00101000" /*  40 = '(' */
         "00100010" /*  34 = '"' */
         "01001000" /*  72 = 'H' */
         "01100101" /* 101 = 'e' */
         "01101100 RPT2 x" /* 108 = 'l' */
         "01101111" /* 111 = 'o' */
         "00100000" /*  32 = ' ' */
         "01010111" /*  87 = 'W' */
         "01101111" /* 111 = 'o' */
         "01110010" /* 114 = 'r' */
         "01101100" /* 108 = 'l' */
         "01100100" /* 100 = 'd' */
         "00100001" /*  33 = '!' */
         "01011100" /*  92 = '\' */
         "01101110" /* 110 = 'n' */
         "00100010" /*  34 = '"' */
         "00101001" /*  41 = ')' */
         "00111011" /*  59 = ';' */
         "00000000" /*  0 = '\0' */
      },

      {  "00100000" /*  32 = ' ' */
         "00100000" /*  32 = ' ' */
         "00100000" /*  32 = ' ' */
         "01110010" /* 114 = 'r' */
         "01100101" /* 101 = 'e' */
         "01110100" /* 116 = 't' */
         "01110101" /* 117 = 'u' */
         "01110010" /* 114 = 'r' */
         "01101110" /* 110 = 'n' */
         "00100000" /*  32 = ' ' */
         "00110000" /*  48 = '0' */
         "00111011" /*  59 = ';' */
         "00000000" /*  0 = '\0' */
      },

      {  "01111101" /* 125 = '}' */
         "00000000" /*  0 = '\0' */
      }
   };

   char correct[ ][41] = {
      "#include <stdio.h>", "int main( ) {",
      "   printf(\"Hello World!\\n\");", "   return 0;", "}"
   };
   char phrase[41];

   int i, num, valid=1, pass=0, sc;
   disk d1(7, "w"), d2;
   segment sgs[5];

   for(i=0; i<5 && valid; i++, pass++) {
      sgs[i].initialize(core_data[i], 1);

      d1 += sgs[i]; // calling operator+=( )
                    // which in turn calls the copy constructor
                    // because of the return by value

      d1.get_segment(i).get_word(phrase, 0);
      sc = d1.get_segment_count( );
      if(strcmp(phrase, correct[i]) || sc != pass + 1) {
         cout << "\nFailed while testing the operator+=( )...\n";
         cout << "Failed on test... " << pass+1 << endl << endl;
         valid = 0;
      }
      else {
         cout << "\nPassed test... " << pass+1 << endl << endl;
      }
      cout << "segment[" << i << "]'s string -------> '" << phrase << "'" << endl;
      cout << "Actual string -------------> '" << correct[i] << "'" << endl;
      cout << "Your segment count -------->  " << sc << endl;
      cout << "Actual segment count ------>  " << pass + 1 << endl;
      cout << "Press the ENTER key to continue..." << endl;
      cin.get( );
   }
   if(valid) {
      d2 = d1; // calling operator=( )

      const segment *p1 = d1.get_all_segments( );
      const segment *p2 = d2.get_all_segments( );
      if(p1 == p2 ||
         d1.get_segment_count( ) != d2.get_segment_count( )) {
                     // p1 and p2 should have unique memory addresses
                     // if the operator=( ) was coded correctly!
         cout << "\nFailed while testing the operator=( )...\n";
         cout << "Failed on test... " << pass + 1 << endl << endl;
         valid = 0;
      }
      else {
         cout << "\nPassed test... " << pass+1 << endl << endl;
         cout << "First disk's segment count ----> " <<
              d1.get_segment_count( ) << endl;
         cout << "Second disk's segment count ---> " <<
              d2.get_segment_count( ) << endl;
         cout << "Press the ENTER key to continue..." << endl;
         cin.get( );
         pass++;
      }
   }
   if(valid) {
      num = d2.access("hello.c");
      if(num != 77) {
         cout << "\nFailed while testing the access( ) function...\n";
         cout << "Failed on test... " << pass + 1 << endl << endl;
         valid = 0;
      }
      else {
         cout << "\nPassed test... " << pass+1 << endl << endl;
         cout << "Number of characters written --> " << num << endl;
         cout << "Actual number of characters ---> " << 77 << endl;
         cout << "Press the ENTER key to continue..." << endl;
         cin.get( );
         pass++;
      }
   }
   if(valid) {
      cout << "\nCongratualtions!!! You passed all tests.\n";
      cout << "Your program is ";
      cout.setf(ios::fixed);
      cout.precision(2);
      cout << 100.0*(pass)/7.0 << "% complete...\n";
      cout << "You may hand in your assignment.\n";
   }
   else {
      cout << "\nYou passed " << pass-1 << "/7 tests...\n";
      cout << "Your program is ";
      cout << 100.0*(pass)/7.0 << "% complete...\n";
      cout << "Your program still needs some work!\n";
      cout << "Keep at it!\n\n";
   }
   return 0;
}
