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

#define ERROR 1
#define OK 0
const int WORD_LENGTH = 250;//定义单个单词最大长度
typedef int status;


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
wordNode *wordSearch(char *word,int *num);
status wordCount(char *word,int *num);
void printCountList(int *num);
status quickSort(wordNode *headNode,wordNode *end);


status main(int argc,char *argv[])
{
    char temp[WORD_LENGTH];//定义用以临时存放单词的数组
    FILE *file;
    int count,articleWordNum = 0;//定义统计结点个数的变量
    int *num = &articleWordNum,choose;
    
    /*
     **读取文件
     */
    if((file = fopen("/Users/tianling/Documents/Data_Structure/word_frequency_statistic/word_frequency_statistic/article.txt", "r")) == NULL){
        //这里是绝对路径，基于XCode编译器查找方便的需求
        printf("文件读取失败!");
        exit(1);
    }
    
    while((fscanf(file,"%s",temp))!= EOF){
        
        count = wordCount(temp,num);
    }
    
    fclose(file);//关闭文件
    
    printCountList(num);
    
    printf("*********************请选择*********************");
    printf("************1. 输出词频最高的10个词***************");
    printf("************2. 退出*****************************");
    
    scanf("%d",&choose);
    if(choose == 1){
        quickSort(headNode,NULL);
        printCountList(num);

    }else
        exit(0);
    
    return 0;
    
    
}

/*
 **查找单词所在结点
 */
wordNode *wordSearch(char *word,int *num){
    wordNode *node;//声明一个新结点
    
    if(headNode == NULL){//若头结点为空
        node = (wordNode*)malloc(sizeof(wordNode));
        strcpy(node->word, word);//将第一个单词赋值给这个新结点
        node->time = 0;//初始化该单词的出现次数
        *num+=1;
        headNode = node;//将头结点指向这个新结点
        return node;
        
    }
    
    wordNode *nextNode = headNode;
    wordNode *preNode = NULL;
    
    while(nextNode != NULL && strcmp(nextNode->word, word) != 0){
        preNode = nextNode;
        nextNode = nextNode->next;
    }
    
    //若该单词不存在，则在链表中生成新结点
    if(nextNode == NULL){
        node = (wordNode*)malloc(sizeof(wordNode));
        strcpy(node->word, word);
        node->time = 0;
        node->next = headNode->next;
        headNode->next = node;
        *num+=1;
        
        return node;
    }else
        return nextNode;
    
}


/*
 **词频统计
 */
status wordCount(char *word,int *num){
    wordNode *tmpNode = NULL;
    tmpNode = wordSearch(word,num);
    
    if(tmpNode == NULL){
        return ERROR;
    }
    
    tmpNode->time++;
    
    return 0;
}


/*
 **打印所有词频
 */
void printCountList(int *num){
    if(headNode == NULL){
        printf("该文件无内容！");
        
    }else{
        wordNode *preNode = headNode;
        printf("总词量 %d \n",*num);
        
        while(preNode != NULL){
            printf("%s 出现次数 %d\n",preNode->word,preNode->time);
            preNode = preNode->next;
        }
    }
    
}


/*
 **对词频统计结果进行快速排序
 */
status quickSort(wordNode *headNode,wordNode *end){
    wordNode *right;
    wordNode **left_walk,**right_walk;
    wordNode *pivot,*old;
    int count,left_count,right_count;
    
    if(headNode == end)
        return ERROR;
    
    do{
        pivot = headNode;//定义头结点为排序基准点
        left_walk = &headNode;
        right_walk = &right;
        left_count = right_count = 0;
        
        for(old = headNode;old != end;old = old->next){
            if(old->time < pivot->time){//小于基准则加入到左边子链表中，继续比较
                ++left_count;
                *left_walk = old;//把该节点加入到左边链表中
                left_walk = &(old->next);
                
            }else{//大于等于基准则加入到右边字链表中，继续比较
                ++right_count;
                *right_walk = old;
                right_walk = &(old->next);
                
            }
        }
        //合并链表
        *right_walk = end;//结束右链表
        *left_walk = pivot;
        pivot->next = right;
        
        if(left_walk > right_walk){
            quickSort(pivot->next,end);
            end = pivot;
            count = left_count;
        }else{
            quickSort(headNode,pivot);
            headNode = pivot->next;
            count = right_count;
        }
        
        
    }while(count>1);
    
    return 0;
}
