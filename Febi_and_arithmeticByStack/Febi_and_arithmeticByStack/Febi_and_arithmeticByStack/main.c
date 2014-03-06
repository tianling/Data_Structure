//
//  main.c
//  Febi_and_arithmeticByStack
//
//  Created by tianling on 14-3-6.
//  Copyright (c) 2014年 tianling. All rights reserved.
//  基于栈实现斐波那契数列和四则运算

#include <stdio.h>
#define ERROR 1
#define OK 0
#define MaxSize 40

typedef int status;

status Feb(int i);


status main()
{
    int FebNum;
    
    for(FebNum = 0;FebNum<40;FebNum++){
        printf("%d \n",Feb(FebNum));
    }
    
    return 0;

}


/*
 *递归返回斐波那契数列元素
 */
status Feb(int i){
    if(i<2)//判断当前元素是否小于2
        return i == 0?0:1;//小于2则返回1或者0
    return Feb(i - 1) + Feb(i - 2);//不小于2则返回前两个元素之和
}