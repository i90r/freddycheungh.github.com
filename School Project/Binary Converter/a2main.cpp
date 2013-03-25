///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  File:        a2main.cpp VERSION 1.00                                     //
//  Written By:  Danny Abesdris                                              //
//  Date:        May 27, 2012                                                //
//  Main program to test assignment #2 for OOP244, Summer 2012.              //
//                                                                           //
//  You must not modify this file!                                           //
//                                                                           //
//  This program assumes that you have written the code for a class          //
//  called 'segment' and have stored the declaration for that class in a     //
//  file which must be called "segment.h"                                    //
//                                                                           //
//  Your program must be stored in a file called segment.cpp                 //
//  In your segment.cpp file, you must include the statement:                //
//  #include "segment.h"                                                     //
//                                                                           //
//  NOTE: You may compile and run this program on either the UNIX system     //
//        on ZENIT or in WINDOWS using the Visual Studio 2010 or             //
//        another C++ compiler                                               //
//                                                                           //
//                                                                           //
//  To compile your assignment:                                              //
//  On zenit   : c++ a2main.cpp  segment.cpp assign1.c -o a2main             //
//  On windows : cl a2main.cpp  segment.cpp assign1.c (Visual Studio)        //
//                                                                           //
//  This command will compile both files and link them together into an      //
//  executable (binary) file called "a2main"                                 //
//  To run your program, at the command prompt type:                         //
//  /home/students/jsmith>a2main                                             //
//                                                                           //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

#include "segment.h"

#define LOOP 10


int main( ) {
   const char core_data[ ][2000] = {
"0", /* should insert the null byte '\0' only */

"01010111 This sequence contains the letter 'W'       " /*  87 = 'W' */
"      r5 0 #! 1 1 gP 0 f66-:] 0 [ } 1 v4t^ 0 1 n>?:77" /* 101 = 'e' */
" junk ^*@&#^% 0110  more junk }{r;,<> 1100         2x" /* 108 = 'l' */
"                  0    1       1     0 0          011" /*  99 = 'c' */
"0  ^%jh  1 ]{) OVR 1 - 0 _! 9 + 1  118Y z(x pM1      " /* 111 = 'o' */
"This next group of 8 should be SKP skipped! 11111111 " /* skipped */
"*&^! 0  1  1  0 1     1 0     128673kjshd:L<    2938 " /* 109 = 'm' */
"      r5 0 #! 1 1 gP 0 f66-:] 0 [ } 1 v4t^ 0 1 n>?:77" /* 101 = 'e' */
"#!/bin/bash 00  1 00 00 0 g^b-ps 6@&^%               " /*  32 = ' ' */
"01010100 This sequence contains the letter 'T'       " /*  84 = 'T' */
"0  ^%jh  1 ]{) OVR 1 - 0 _! 9 + 1  118Y z(x pM1      " /* 111 = 'o' */
"#!/bin/bash 00  1 00 00 0 g^b-ps 6@&^%               " /*  32 = ' ' */
"---repeat--->0 1 0 0 1 1 1 1<------------RPT2--------" /*  79 = 'O' */
"0 1 0 1 0bbavac9872962  000&*************************" /*  80 = 'P' */
"a0b0c1dpe1f0g0h01ijklmnopqrstuvwxyz******************" /*  49 = '1' */
"00fg333                                110100>>>>>>>>" /*  52 = '4' */
"00fg333                                110100>>>>>>>>" /*  52 = '4' */
"                     0000                            ",/*  0 = '\0' */

"00011110 This char should not be inserted!           " /*  30 cntrl */
" 00011111 This char should not be inserted!          " /*  31 cntrl */
"  00100000                                           " /*  32 = ' ' */
"   00100001                                          " /*  33 = '!' */
"    00100010                                         " /*  34 = '"' */
"     00100011                                        " /*  35 = '#' */
"      00100100                                       " /*  36 = '$' */
"       00100101                                      " /*  37 = '%' */
"        00100110                                     " /*  38 = '&' */
"         00100111                                    " /*  39 = ''' */
"          00101000                                   " /*  40 = '(' */
"           00101001                                  " /*  41 = ')' */
"            00101010                                 " /*  42 = '*' */
"             00101011                                " /*  43 = '+' */
"              00101100                               " /*  44 = ',' */
"               00101101                              " /*  45 = '-' */
"                00101110                             " /*  46 = '.' */
"                 00101111                            " /*  47 = '/' */
"                  00110000                           " /*  48 = '0' */
"                   00110001                          " /*  49 = '1' */
"                    00110010                         " /*  50 = '2' */
"                     00110011                        " /*  51 = '3' */
"                      00110100                       " /*  52 = '4' */
"                       00110101                      " /*  53 = '5' */
"                        00110110                     " /*  54 = '6' */
"                         00110111                    " /*  55 = '7' */
"                          00111000                   " /*  56 = '8' */
"                           00111001                  " /*  57 = '9' */
"                            00111010                 " /*  58 = ':' */
"                             00111011                " /*  59 = ';' */
"                              00111100               " /*  60 = '<' */
"                               00111101              " /*  61 = '=' */
"                                00111110             " /*  62 = '>' */
"                                 00111111            " /*  63 = '?' */
"                                  01000000           " /*  64 = '@' */
"                                   00000000          ",/*   0 = '\0'*/

"                                    01000001         " /*  65 = 'A' */
"                                     01000010        " /*  66 = 'B' */
"                                      01000011       " /*  67 = 'C' */
"                                       01000100      " /*  68 = 'D' */
"                                        01000101     " /*  69 = 'E' */
"                                         01000110    " /*  70 = 'F' */
"                                          01000111   " /*  71 = 'G' */
"                                           01001000  " /*  72 = 'H' */
"                                            01001001 " /*  73 = 'I' */
"                                             01001010" /*  74 = 'J' */
"                                            01001011 " /*  75 = 'K' */
"                                           01001100  " /*  76 = 'L' */
"                                          01001101   " /*  77 = 'M' */
"                                         01001110    " /*  78 = 'N' */
"                                        01001111     " /*  79 = 'O' */
"                                       01010000      " /*  80 = 'P' */
"                                      01010001       " /*  81 = 'Q' */
"                                     01010010        " /*  82 = 'R' */
"                                    01010011         " /*  83 = 'S' */
"                                   01010100          " /*  84 = 'T' */
"                                  01010101           " /*  85 = 'U' */
"                                 01010110            " /*  86 = 'V' */
"                                01010111             " /*  87 = 'W' */
"                               01011000              " /*  88 = 'X' */
"                              01011001               " /*  89 = 'Y' */
"                             01011010                " /*  90 = 'Z' */
"                            01011011                 " /*  91 = '[' */
"                           01011100                  " /*  92 = '/' */
"                          01011101                   " /*  93 = ']' */
"                         01011110                    " /*  94 = '^' */
"                        01011111                     " /*  95 = '_' */
"                       01100000                      " /*  96 = '`' */
"                      00000000                       ",/*   0 = '\0'*/

"                     01100001                        " /*  97 = 'a' */
"                    01100010                         " /*  98 = 'b' */
"                   01100011                          " /*  99 = 'c' */
"                  01100100                           " /* 100 = 'd' */
"                 01100101                            " /* 101 = 'e' */
"                01100110                             " /* 102 = 'f' */
"               01100111                              " /* 103 = 'g' */
"              01101000                               " /* 104 = 'h' */
"             01101001                                " /* 105 = 'i' */
"            01101010                                 " /* 106 = 'j' */
"           01101011                                  " /* 107 = 'k' */
"          01101100                                   " /* 108 = 'l' */
"         01101101                                    " /* 109 = 'm' */
"        01101110                                     " /* 110 = 'n' */
"       01101111                                      " /* 111 = 'o' */
"      01110000                                       " /* 112 = 'p' */
"     01110001                                        " /* 113 = 'q' */
"    01110010                                         " /* 114 = 'r' */
"   01110011                                          " /* 115 = 's' */
"  01110100                                           " /* 116 = 't' */
" 01110101                                            " /* 117 = 'u' */
"01110110                                             " /* 118 = 'v' */
" 01110111                                            " /* 119 = 'w' */
"  01111000                                           " /* 120 = 'x' */
"   01111001                                          " /* 121 = 'y' */
"    01111010                                         " /* 122 = 'z' */
"     01111011                                        " /* 123 = '{' */
"      011111RPT10                                    " /* 124 = '|' */
"       01111101                                      " /* 125 = '}' */
"        00000000                                     ",/*   0 = '\0'*/

"                                      01000011       " /*  67 = 'C' */
"                                       01000100      " /*  68 = 'D' */
"               00101101                              " /*  45 = '-' */
"                                     01010010        " /*  82 = 'R' */
"                                        01001111     " /*  79 = 'O' */
"                                          01001101   " /*  77 = 'M' */
"        00000000                                     ",/*   0 = '\0'*/

"                                     01010010        " /*  82 = 'R' */
"                                    01000001         " /*  65 = 'A' */
"                                          01001101   " /*  77 = 'M' */
"        00000000                                     ",/*   0 = '\0'*/

"                                    01010011         " /*  83 = 'S' */
"                                      01000011       " /*  67 = 'C' */
"                                    01010011         " /*  83 = 'S' */
"                                            01001001 " /*  73 = 'I' */
"        00000000                                     ",/*   0 = '\0'*/

"                     00110011                        " /*  51 = '3' */
"                00101110                             " /*  46 = '.' */
"                       00110101                      " /*  53 = '5' */
"#!/bin/bash 00  1 00 00 0 g^b-ps 6@&^%               " /*  32 = ' ' */
"                                         01000110    " /*  70 = 'F' */
"          01101100                                   " /* 108 = 'l' */
"       01101111                                      " /* 111 = 'o' */
"      01110000    RPT2                               " /* 112 = 'p' */
"   01111001                                          " /* 121 = 'y' */
"        00000000                                     " /*   0 = '\0'*/

};

   char phrase[41];
   char correct[LOOP][41] = {
      "",
      "Welcome To OOP144",
      " !\"#$%&'()*+,-./0123456789:;<=>?@",
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`",
      "abcdefghijklmnopqrstuvwxyz{||||||||||}",
      "CD-ROM",
      "RAM",
      "SCSI",
      "3.5 Floppy",
      ""
   };

   char modified[LOOP][41] = {
      "",
      "Welcome To OOP244",
      " !\"#$%&'()*+,-./0123456789:;<=>?@",
      "aBCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`",
      "abcdefghijklmnopqrstuvwxyZ{||||||||||}",
      "CD_ROM",
      "ROM",
      "SCS",
      "3.5 Floppi",
      ""
   };

   char sorted[LOOP][41] = {
      "",
      "",
      " !\"#$%&'()*+,-./0123456789:;<=>?@",
      "3.5 Floppi",
      "CD_ROM",
      "ROM",
      "SCS",
      "Welcome To OOP244",
      "aBCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`",
      "abcdefghijklmnopqrstuvwxyZ{||||||||||}",
   };

   char matches[LOOP][21] = {
      "Abc", "OOP", "0123", "abc", "xyz", "CD-R", "RAM", "SS", "3.5", "<=>"
   }, gc;

   int mvalues[LOOP]  = { -1, 1, 2, 4, 4, 5, 6, -1, 8, 2 }, i;
   int cvalues[LOOP]  = { -1, 14, 999, 0, 25, 2, 1, 3, 9, 12000 };
   char chgs[LOOP] = { '\0', '2', '\0', 'a', 'Z', '_', 'O', '\0', 'i', '\0' };
   int sval[LOOP]     = { 0, 1, 0, 1, 1, 1, 1, 1, 1, 0 };
   int valid = 1, rc, pass=0;

   segment xf1;
   xf1.initialize(core_data, LOOP-1); // passing only 9 strings
   
   for(i=0; i<LOOP && valid; i++, pass++) {
      xf1.get_word(phrase, i);
      if(strcmp(phrase, correct[i])) {
         printf("\nFailed while testing the initialize( ) function...\n");
         printf("Failed on test... %d\n\n", pass+1);
         valid = 0;
      }
      else {
         printf("\nPassed test %d...\n\n", pass+1);
      }
      printf("Your string ----------> '%s'\n", phrase);
      printf("Actual string --------> '%s'\n", correct[i]);
      printf("Press the ENTER key to continue...");
      getchar( );
   }

   if(valid) {
      for(i=0; i<LOOP && valid; i++, pass++) {
         rc = xf1.match(matches[i]);
         if(rc != mvalues[i]) {
            printf("\nFailed while testing the match( ) function...\n");
            printf("Failed on test... %d\n\n", pass+1);
            valid = 0;
         }
         else {
            printf("\nPassed test %d...\n\n", pass+1);
         }
         printf("Your match( ) return value ----> %d\n", rc);
         printf("Actual match( ) return value --> %d\n", mvalues[i]);
         printf("Press the ENTER key to continue...");
         getchar( );
      }
   }
   if(valid) {
      for(i=0; i<LOOP && valid; i++, pass++) {
         rc = xf1.set_char(i, cvalues[i], chgs[i]);
         xf1.get_word(phrase, i);
         if(rc != sval[i] || strcmp(phrase, modified[i])) {
            printf("\nFailed while testing the set_char( ) function...\n");
            printf("Failed on test... %d\n\n", pass+1);
            valid = 0;
         }
         else {
            printf("\nPassed test %d...\n\n", pass+1);
         }
         printf("Your modified word ----------> '%s'\n", phrase);
         printf("Actual modified word --------> '%s'\n", modified[i]);
         printf("Press the ENTER key to continue...");
         getchar( );
      }
   }
   if(valid) {
      for(i=0; i<LOOP && valid; i++, pass++) {
         gc = xf1.get_char(i, cvalues[i]);
         if(gc != chgs[i]) {
            printf("\nFailed while testing the get_char( ) function...\n");
            printf("Failed on test... %d\n\n", pass+1);
            valid = 0;
         }
         else {
            printf("\nPassed test %d...\n\n", pass+1);
         }
         printf("Your character ----------> '%c'\n", gc);
         printf("Actual character --------> '%c'\n", chgs[i]);
         printf("Press the ENTER key to continue...");
         getchar( );
      }
   }
   if(valid) {
      xf1.sort( );
      for(i=0; i<LOOP && valid; i++, pass++) {
         xf1.get_word(phrase, i);
         if(strcmp(phrase, sorted[i])) {
            printf("\nFailed while testing the sort( ) function...\n");
            printf("Failed on test... %d\n\n", pass+1);
            valid = 0;
         }
         else {
            printf("\nPassed test %d...\n\n", pass+1);
         }
         printf("Your sorted string ----------> '%s'\n", phrase);
         printf("Actual sorted string --------> '%s'\n", sorted[i]);
         printf("Press the ENTER key to continue...");
         getchar( );
      }
   }

   if(valid) {
      printf("\nCongratualtions!!! You passed all tests.\n");
      printf("Your program is %.2lf%% complete!\n", 100.0*(pass)/50.0);
      printf("You may hand in your assignment.\n");
   }
   else {
      printf("\nYou passed %d/50 tests...\n", pass-1);
      printf("Your program is %.2lf%% complete!\n", 100.0*(pass-1)/50.0);
      printf("Your program still needs some work!\n");
      printf("Keep at it!\n\n");
   }
   return 0;
}
