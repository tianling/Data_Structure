//
//  main.c
//  Febi_and_arithmeticByStack
//
//  Created by tianling on 14-3-6.
//  Copyright (c) 2014年 tianling. All rights reserved.
//  基于栈实现斐波那契数列和整数四则运算

#include <stdio.h>
#include <string.h>
#define ERROR 1
#define OK 0
#define MaxSize 40 //定义斐波那契数列长度
#define StackSize 30 //定义栈长度

typedef int status;
typedef char statbs;
/*
 **定义用以处理中缀表达式转换及表达式运算使用的栈
 */
typedef struct{
    char data[StackSize];
    int top;
}sqStack;

/*
 **定义用以储存表达式数组及其长度的结构体
 */
typedef struct{
    char expression[StackSize];
    int length;
}Expression;

/*
 **函数声明
 */
status Feb(int i);
status tableList();
Expression middle_expression(char expression[]);
status push(sqStack *sqStack,char data);


status main()
{
    int FebNum,choose;
    char expressionData[StackSize];

    choose = tableList();//输出操作菜单
    
    switch(choose){
        case 1:
            for(FebNum = 0;FebNum<40;FebNum++){
                printf("%d \n",Feb(FebNum));
            }
            
            break;
            
        case 2:
            printf("请输入待求表达式");
            scanf("%s",expressionData);
            middle_expression(expressionData);

            
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


/*
 **菜单函数
 */
status tableList(){
    int choose;
    
    printf("******************请选择操作类型******************");
    printf("****************1.打印斐波那契数列*****************");
    printf("****************2.四则运算************************");
    printf("****************3.退出****************************");
    scanf("%d",&choose);
    
    return choose;
    
}


/*
 **将中缀表达式转化成后缀表达式
 */
Expression middle_expression(char expression[]){
    Expression back_expression;
    int i = 0,k = 0;
    sqStack trasStrack;
    
    trasStrack.top = 0;
    back_expression.length = 0;
    while(expression[i] != '\0'){
        
        if(expression[i]>=0 && expression[i]<=9){
            back_expression.expression[k] = expression[i];
            back_expression.length++;
            k++;
        }
        
        i++;
    }
    
    return back_expression;
}

/*
 **压栈操作
 */
status push(sqStack *sqStack,char data){
    if(sqStack->top == MaxSize-1){
        return ERROR;
    }
    sqStack->top++;
    sqStack->data[sqStack->top] = data;
    return OK;
}