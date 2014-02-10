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
#define OK 0;
#define ERROR 1;


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
int NodeFind(int num,Link startNode);


int main()
{
    int choose,num,find,findData;
    int StartArray[5] = {5,7,8,9,2};
    Link startNode;
    
    startNode =  LinkListStart(StartArray);
    choose = tableList();
    switch(choose){
        case 1:
            LinkPrint(startNode);
            break;
        case 2:
            printf("请输入需要查找的结点编号");
            scanf("%d",&num);
            find = NodeFind(num, startNode);
            if(find!=1){
                findData = find;
                printf("%d",findData);
            }else
                printf("该节点不存在！");
            
    }
    main();
}


/*
 **菜单函数
 */
int tableList(){
    int choose;
    
    printf("**************Welcome,It's Design by tianling******************");
    printf("******************************1.输出链表************************");
    printf("******************************2.查找结点************************");
    
    scanf("%d",&choose);
    return choose;//返回选择的操作编号

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
    Node->next = NULL;//尾结点的next指针赋空值
    
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


/*
 **查找节点
 */
int NodeFind(int num,Link startNode){
    int check;
    Link *node;
    
    node = &startNode;//让node指向初始结点
    check = 1;//check作为计数参考变量
    
    while(node && check<num){
        node = node->next;
        check++;
    }
    
    if(!node || check>num){
        return ERROR;
    }
    else
        return node->data;
    
    
}