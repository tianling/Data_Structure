//
//  main.c
//  Linear_List work
//
//  Created by tianling on 14-1-28.
//  Copyright (c) 2014年 tianling. All rights reserved.
//  实现顺序线性表的并集
//

#include <stdio.h>
#define Ok 0
#define Error 1
#define MaxSize 100
int Lenth(char Len[]);
int Check(char Len[],int Lenth,char element);
int ListInsert(char Len[],int Lenth,char element);

/**
 **线性表合并
 **/
int LenUnion(char LenA[],char LenB[])
{
    int i,LenthA,LenthB,check;
    LenthA = Lenth(LenA);
    LenthB = Lenth(LenB);

    for(i = 0;i<LenthA;i++)
    {
        check = Check(LenB,LenthB,LenA[i]);
        if(check == 1)
            continue;
        else
        {
            ListInsert(LenB, LenthB,LenA[i]);
            LenthB++;
        }
            
        
    }
    return Ok;
    
}


/*
 **元素插入
 */
int ListInsert(char Len[],int Lenth,char element)
{
    if(Lenth<=MaxSize)
    {
       Len[Lenth] = element;
       return Ok;
    }
    else
        return Error;
}


/*
 **遍历查询元素是否存在（可以考虑使用其他方式）
 */
int Check(char Len[],int Lenth,char element)
{
    int i;
    for(i = 0;i<Lenth;i++)
    {
        if(Len[i] == element)
            return 1;
    }
    
    return 0;
    
}


/*
 **获取数组长度
 */
int Lenth(char Len[])
{
    int i = 0,sum = 0;
    
    for(i = 0;Len[i]!='\0'&& i<30;i++)
    {
        
        sum++;
    }
    return sum;
}


int main()
{
    char LenA[30] = {'a','c','d','z','k','h'};
    char LenB[30] = {'d','e','2','5','y','p'};
    int Union;
    
    Union = LenUnion(LenA,LenB);
    
    puts(LenB);
    
}

