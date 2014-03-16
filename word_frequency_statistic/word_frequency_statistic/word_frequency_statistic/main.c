//
//  main.c
//  word_frequency_statistic
//
//  Created by tianling on 14-3-16.
//  Copyright (c) 2014年 tianling. All rights reserved.
//  实现英文文本的词频统计
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int WORD_LENGTH = 250;


/*
 **定义存储单词及其出现次数的结构体
 */
typedef struct Node{
    char word[WORD_LENGTH];
    int time;
    struct Node *next;
}wordNode;

wordNode *headNode = NULL;//定义链表头指针

int main()
{
    

}

