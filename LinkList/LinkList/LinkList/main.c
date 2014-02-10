//
//  main.c
//  LinkList
//
//  Created by tianling on 14-2-10.
//  Copyright (c) 2014年 tianling. All rights reserved.
//  实现单链表的生成，初始化，插入，查找，删除

#include <stdio.h>
#include <stdlib.h>

#define StartSize 5;
/*
 **定义链表
 */
typedef struct Node {
    int data;
    struct Node *next;
}Link;

/*
 **函数声明
 */
int tableList();
Link LinkListStart(int startData[]);
void LinkPrint(Link startNode);


int main()
{
    int choose;
    int StartArray[5] = {5,7,8,9,2};
    Link startNode;
    
    startNode =  LinkListStart(StartArray);
    choose = tableList();
    switch(choose){
        case 1:
            LinkPrint(startNode);
            break;
            
    }
}


/*
 **菜单函数
 */
int tableList(){
    int choose;
    
    printf("**************Welcome,It's Design by tianling******************");
    printf("******************************1.输出链表************************");
    
    scanf("%d",&choose);
    return choose;

}

/*
 **链表初始化
 */
Link LinkListStart(int startData[]){
    int i;
    Link *startNode,*childNode;
    Link *Node = (Link*)malloc(sizeof(Link));
    startNode = Node;

    for(i=0;i<5;i++){
        Node->data = startData[i];
        childNode = (Link*)malloc(sizeof(Link));
        Node->next = childNode;
        Node = childNode;
    }
    Node->next = NULL;
    
    return *startNode;
}


/*
 **打印链表
 */
void LinkPrint(Link startNode){
    Link *Node;
    
    Node = &startNode;
    while(Node){
        printf("%d",Node->data);
        Node = Node->next;
    }
    
}