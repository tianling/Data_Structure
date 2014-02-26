//
//  main.c
//  StackWork
//
//  Created by tianling on 14-2-26.
//  Copyright (c) 2014年 tianling. All rights reserved.
//  实现栈的生成，压栈，出栈操作

#include <stdio.h>
#define MaxSize 10
#define ERROR 1
#define OK 0

typedef int status;

typedef struct{
    int data[MaxSize];
    int top;
}SqStack;

status push(SqStack *stack,int data);
status output(SqStack *stack);

int main()
{
    int stackWork,data;
    SqStack *stack;
    SqStack stackValue;
    stack = &stackValue;
    
    stack->top = 0;
    
    stackWork = output(stack);
    if(stackWork == ERROR){
        printf("当前栈空\n");
    }
    
    while (stack->top != MaxSize-1) {
        printf("输入压栈数据");
        scanf("%d",&data);
        stackWork = push(stack, data);
    }

    while(stack->top != 0){
        output(stack);
    }

}


/*
 **压栈操作
 */
status push(SqStack *stack,int data){
    if(stack->top == MaxSize-1){
        return ERROR;
    }
    stack->top++;
    stack->data[stack->top] = data;
    return OK;
}


/*
 **出栈操作
 */
status output(SqStack *stack){
    if(stack->top == 0){
        return ERROR;
    }
    
    int data;
    
    data = stack->data[stack->top];
    printf("%d",data);
    stack->top --;
    return OK;
}

