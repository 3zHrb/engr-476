/////////////////////////////////////////////////////////////////////////////////
//
// Title:                kay.c
// Problem:   This program takes raw input read start and end flags of data
//              which is entered by users.
// Class:                 ENGR 476
// Date:                 02/18/2016
// Author:            Anish Kumaramagalam
//
/////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int main()  {
    
    char ch; // char
    char HDLCflag[] = "01111110"; // key
    char chacker[8]; // input key container
    char data[256]; // data container
    int i = 0, c = 0, d = 0;
    memset(data, 0, 256);
    
    //
    printf("Press Any Key to Continue and it will be read automaticly\n");
    printf("for this expirment to work only enter 0's and 1's and 'e' exit \nThank You\n");
    
    system ("/bin/stty raw"); // this sets the key inputs to raw
    while (1) {
        
        ch = getchar();
        printf("%c",ch);// prints what you are typing
        
        // receving char when in container
        if (c == 1) {
            data[d] = ch;
            d++;
        }
        
        //move over key checker string char
        for (i = 7; i >= 0; i--) {
            if (i == 0) {
                chacker[i] = ch;
                break;
            }   else    {
                chacker[i] = chacker[i-1];
            }
        }
        
        //checks for flags
        if (chacker[0] == HDLCflag[0] &&
            chacker[1] == HDLCflag[1] &&
            chacker[2] == HDLCflag[2] &&
            chacker[3] == HDLCflag[3] &&
            chacker[4] == HDLCflag[4] &&
            chacker[5] == HDLCflag[5] &&
            chacker[6] == HDLCflag[6] &&
            chacker[7] == HDLCflag[7]) {
            
            
            if (c == 1) {
                c--;
                system ("/bin/stty cooked"); // this sets the key inputs to processed
                printf("\n(End flag has been detected) HDLC FLAG\n");
                data[d-8] = '\0';
                printf("\ndata : %s\n",data);
                printf("\n(continuing to receive)\n");
                system ("/bin/stty raw"); // this sets the key inputs to processed
            }else   {
                system ("/bin/stty cooked"); // this sets the key inputs to processed
                printf("\n(continuing to receive)  HDLC FLAG\n");
                system ("/bin/stty raw"); // this sets the key inputs to processed
                c++;
            }
            
        }
        
        // exits on 'e' only when not receving
        if (ch == 'e' &&
            c == 0)  {
            system ("/bin/stty cooked"); // this sets the key inputs to processed
            printf("\n");
            system ("/bin/stty raw"); // this sets the key inputs to processed
            break;
        }
        
    }
    system ("/bin/stty cooked"); // this sets the key inputs to processed
    return 0;
}   // end main

