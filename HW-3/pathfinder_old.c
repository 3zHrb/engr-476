/////////////////////////////////////////////////////////////////////////////////
//
// Title:                pathfinder.c
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

void repstr (char* str1);
char*  addstr  (char* str1, char* str2);
void starDate(int j);
void checkDate(int j);
int extract();

/*  global var  */
const int limit = 30;// WARNING! this program will only host limit number line in map
char data[limit][50];   // stores file locally
int distance=0, LlestDist=0, lestDist=0, lineNum;    // counts people who pass
char path[limit*4] = "A/", temp[2];
int pathLen = 2, in =0, cr =0;
char nodeL='A', nodeL2, findNode='H', lestNode='A';

/*  main  */
int main()  {

    int i = extract();

    /**/
    while   (findNode != lestNode)  {
        
        for (int j = 0; j < i; ++j) {
            if ((data[j][0] == nodeL &&
                data[j][4] != '*') ||
                data[j][4] == '/')    {
                checkDate(j);
                if(data[j][1] != nodeL2)    {
                    if (in == 0)    {
                        lestNode = data[j][1];
                        lestDist = (int)data[j][3]-48;
                        lineNum = j;
                        in++;
                        //printf("%d %s %c %d\n", lineNum, data[lineNum],lestNode, lestDist);
                    }
                    if (data[j][0] == nodeL)   {
                        if (lestDist > (int)data[j][3]-48 + LlestDist)  {
                            lestNode = data[j][1];
                            lestDist = (int)data[j][3]-48;
                            lineNum = j;
                            printf("fisrt %d %s %c %d\n", lineNum, data[lineNum],lestNode, lestDist);
                        }
                    }
                    
                }
            } 
        }
        for (int j = 0; j < i; ++j) {
            if ((data[j][0] == nodeL &&
                data[j][4] != '*') ||
                data[j][4] == '/')    {
                checkDate(j);
                if(data[j][1] != nodeL2)    {
                    if (in == 0)    {
                        lestNode = data[j][1];
                        lestDist = (int)data[j][3]-48;
                        lineNum = j;
                        in++;
                        //printf("%d %s %c %d\n", lineNum, data[lineNum],lestNode, lestDist);
                    }
                    if(data[j][0] == nodeL2 &&
                            data[j][1] != nodeL)   {
                        if (lestDist > (int)data[j][3]-48)  {
                            cr = 1;
                            lestNode = data[j][1];
                            lestDist = (int)data[j][3]-48;
                            lineNum = j;
                            printf("second %d %s %c %d\n", lineNum, data[lineNum],lestNode, lestDist);
                        }
                    }
                    
                }
            } 
        }
        in =0;

        if (data[lineNum][0] == nodeL2 && cr == 1) {
            printf("%c\n", nodeL);
            for (int j = 0; j < i; ++j) {
                if (data[j][0] == nodeL ||
                    data[j][1] == nodeL)   {
                    printf("%d %s \n", j, data[j]);
                    starDate(j);
                }
            }
            nodeL = lestNode;
            distance -= LlestDist;
            distance += lestDist;
            temp[0] = nodeL;
            path[pathLen-2] = nodeL;
            cr = 0;
        }   else    {

            for (int j = 0; j < i; ++j) {
                if (data[j][0] == nodeL2)   {
                    //starDate(j);
                }
            }
            
            nodeL2 = nodeL;
            nodeL = lestNode;
            temp[0] = nodeL;
            temp[1] = '/';
            repstr (addstr(path,temp)); 
            LlestDist = lestDist;
            distance += lestDist;
            pathLen += 2;
        }
        if (distance > 4)  {
            break;
        }
        //printf("%d %s %c %d\n", lineNum, data[lineNum],lestNode, lestDist);
        printf("distance : %d\n path : %s\n nodeL : %c nodeL2 : %c\n", distance, path,  nodeL, nodeL2);
    }
    printf("\n\n");/**/
    printf("%d %s %c %d %c %c\n", lineNum, data[lineNum],lestNode, lestDist, nodeL, nodeL2);

    for (int j = 0; j < i; ++j) {
        printf("%d %s\n", j, data[j]);
    }

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

void starDate(int j)  {
     data[j][4] = '*';
     data[j][5] = '\n';
}

void checkDate(int j)  {
     data[j][4] = '/';
     data[j][5] = '\n';
}

int extract()  {
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
    return i;
}
