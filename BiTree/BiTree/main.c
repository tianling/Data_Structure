//
//  main.c
//  BiTree
//
//  Created by tianling on 14-6-2.
//  Copyright (c) 2014年 罗鑫宇. All rights reserved.
//  实现二叉树的存储，建立，查找,遍历等操作

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 255
#define ERROR 1
#define OK 0


/*
 **声明结点结构
 */
typedef struct BiNode{
    char data;//结点结构
    struct BiNode *lChild,*rChild;//左右孩子结点指针
}BitNode,*Bitree;

/*
 **函数声明
 */
void dataArrayGet(int *array);

int main(int argc, const char * argv[])
{
    int dataArray[MaxSize];
    
    dataArrayGet(dataArray);
}


/*
 **获取待建树数据
 */
void dataArrayGet(int *array){
    
}
