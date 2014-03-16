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

const int WORD_LENGTH = 250;//定义单个单词最大长度


/*
 **定义存储单词及其出现次数的结构体
 */
typedef struct Node{
    char word[WORD_LENGTH];
    int time;
    struct Node *next;
}wordNode;

wordNode *headNode = NULL;//定义链表头指针

/*
 **函数声明
 */

int main(int argc,char *argv[])
{
    //printf("当前路径%s",argv[0]);
    char temp[WORD_LENGTH];//定义用以临时存放单词的数组
    FILE *file;
    
    /*
     **读取文件
     */
    if((file = fopen("/Users/tianling/Documents/Data_Structure/word_frequency_statistic/word_frequency_statistic/article.txt", "r")) == NULL){
        printf("文件读取失败!");
        exit(1);
    }
    
    while((fscanf(file,"%s",temp))!= EOF){
        printf("%s ",temp);
        
    }
    
    return 0;
    
    

}

