/////////////////////////////////////////////////////////////////////////////////
//
// Title:                maper.c
// Problem:   
//              
// Class:                 ENGR 476
// Date:                 03/14/2016
// Author:            Anish Kumaramagalam
//
/////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char*  addstr  (char* str1, char* str2);
void repstr (char* str1);

/*  global var  */
const int limit = 30;// WARNING! this program will only host limit number line in map
char data[limit][50];   // stores file locally
int distance=0, lestDist=0, lineNum;    // counts people who pass
char path[limit*4] = "A/", temp[2];
int pathLen = 2, in =0;
char nodeL='A', nodeL2, findNode='H', lestNode='A';

/*  main  */
int main()  {
    int i = 0;
    
    /* read file */
    char line [50]; // temp  
    char file_name[] = "map.txt"; // file name
    FILE* fp = fopen(file_name,"r"); // opens file read mode

    while (fgets(line, sizeof(line), fp)) {
        
        //printf("%d %s", i ,line); 
        strcpy(data[i], line);
        i++;
    }

    fclose(fp); // closing file

    while   (findNode != lestNode)  {
        
        for (int j = 0; j < i; ++j) {
            if (data[j][0] == nodeL && data[j][1] != nodeL2)    {
                if (in == 0)    {
                    lestNode = data[j][1];
                    lestDist = (int)data[j][3]-48;
                    lineNum = j;
                    in++;
                    //printf("%d %s %c %d\n", lineNum, data[lineNum],lestNode, lestDist);
                }
                if (lestDist > (int)data[j][3]-48)  {
                    lestNode = data[j][1];
                    lestDist = (int)data[j][3]-48;
                    lineNum = j;
                    printf("%d %s %c %d\n", lineNum, data[lineNum],lestNode, lestDist);
                }
                  
            }
        }
        for (int j = 0; j < i; ++j) {
            
        }
        in =0;
        nodeL2 = nodeL;
        nodeL = lestNode;
        temp[0] = nodeL;
        temp[1] = '/';
        repstr (addstr(path,temp)); 
        distance += lestDist;
        pathLen += 2;
        //printf("%d %s %c %d\n", lineNum, data[lineNum],lestNode, lestDist);
        printf("distance : %d\n path : %s\n", distance, path);
    }
    
    printf("\n");

    return 0;
}   // end main

void repstr (char* str1)    {
    memset(path, 0, sizeof path);
    strcpy(path, str1);
}

char*  addstr  (char* str1, char* str2)  {
    
    char * str3 = (char *) malloc(1 + strlen(str1)+ strlen(str2) );
    strcpy(str3, str1);
    strcat(str3, str2);
    
    return str3;
}

