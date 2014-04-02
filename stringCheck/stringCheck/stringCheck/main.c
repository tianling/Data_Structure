//
//  main.c
//  stringCheck
//
//  Created by tianling on 14-4-2.
//  Copyright (c) 2014年 tianling. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define ERROR 999
#define OK 0

const int MAXSIZE=256;//define the maxsize of string

typedef int status;
typedef struct string{
    char stringArray[MAXSIZE];
    int length;
}String;

/*
 **function declare
 */
status strLength(char string[]);
status stringCheck(String *mainString,String *goalString,int pos);
void subString(char subArray[],String *string,int sub,int length);

status main(int argc, const char * argv[])
{
    String stringMain,goalString;//define the main string and the goal string
    int pos,check;
    
    printf("Please input the main string\n");
    scanf("%s",stringMain.stringArray);
    stringMain.length = strLength(stringMain.stringArray);
    printf("Please input the goal string\n");
    scanf("%s",goalString.stringArray);
    goalString.length = strLength(goalString.stringArray);

    pos = 0;//check place begin with the first char
    
    while(pos<= stringMain.length - goalString.length){
        check = stringCheck(&stringMain, &goalString, pos);
        if(check != ERROR){
            printf("the goal string is at %dth of mainstring\n",check+1);
            return 0;
        }
        
        else
            pos++;
    }
    
    printf("the goal string can't be found in mainstring\n");
    return ERROR;

}


/*
 **caculate the length of string
 */
status strLength(char string[]){
    int i = 0,length = 0;
    
    while(string[i] != '\0' && i<MAXSIZE){
        length++;
        i++;
    }
    return length;
}


/*
 **string check
 */
status stringCheck(String *mainString,String *goalString,int pos){
    int mainLength = mainString->length;
    int goalLength = goalString->length;
    int i = pos;
    
    char Sub[goalLength];
    if(pos>0){
        while(i <= mainLength-goalLength){
            subString(Sub, mainString, i, goalLength);
            
            if(strcmp(Sub, goalString->stringArray) != 0){
                i++;
            }else
                return i;
        }
    }
    
    return ERROR;
    
}


/*
 **string cut
 */
void subString(char subArray[],String *string,int sub,int length){
    int i = sub,k = 0;
    
    while(string->stringArray[i] != '\0' && k<length){
        subArray[k] = string->stringArray[i];
        ++k;
        ++i;
    }
    

}