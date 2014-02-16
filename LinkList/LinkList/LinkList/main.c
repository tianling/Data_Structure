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
int NodeDelete(int num,Link startNode);
int NodeInsert(int num,Link startNode,Link insertNode);
int ListClear(Link startNode);


int main()
{
    int choose,num,find,findData,delete,data,Insert,clear;
    int StartArray[5] = {5,7,8,9,2};
    Link startNode,InsertNode;
    
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
            
            break;
            
        case 3:
            printf("请输入需要删除的结点编号");
            scanf("%d",&num);
            
            delete = NodeDelete(num, startNode);
            if(delete == 0){
                printf("删除成功！\n");
                //LinkPrint(startNode);
                
            }else{
                printf("删除失败，该节点不存在!");
            }
            
            break;
            
        case 4:
            printf("请输入插入数值");
            scanf("%d",&data);
            printf("请输入需要插入的结点编号");
            scanf("%d",&num);
            
            InsertNode = *(Link*)malloc(sizeof(Link));
            InsertNode.data = data;
            Insert = NodeInsert(num, startNode, InsertNode);
            if(Insert == 0)
                printf("插入成功！");
            else{
                printf("插入失败，该节点不存在！");
            }
            
            break;
            
        case 5:
            clear = ListClear(startNode);
            if(clear == 0)
                printf("删除成功!");
            break;
            
        case 6:
            exit(0);
           
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
    printf("******************************3.删除结点************************");
    printf("******************************4.插入结点************************");
    printf("******************************5.整表删除************************");
    printf("******************************6.退出****************************");
    
    scanf("%d",&choose);
    return choose;//返回选择的操作编号

}

/*
 **生成链表并且初始化赋值
 */
Link LinkListStart(int startData[]){
    int i;
    Link *startNode = (Link*)malloc(sizeof(Link)),*Node;

    startNode->next = NULL;//建立一个带头结点的单链表

    for(i=0;i<5;i++){
        Node = (Link*)malloc(sizeof(Link));//生成新结点
        Node->data = startData[i];//为结点赋值
        Node->next = startNode->next;
        startNode->next = Node;//插入到表头
    }
    
    return *startNode;
}


/*
 **打印链表
 */
void LinkPrint(Link startNode){
    Link *Node;
    
    Node = &startNode;
    Node = Node->next;
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
    node = node->next;
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


/*
 **删除结点
 */
int NodeDelete(int num,Link startNode){
    int check;
    Link *node,*childNode;
    
    node = &startNode;
    node = node->next;
    check = 1;
    
    while(node && check<num){
        node = node->next;
        check++;
    }
    
    if(!node || check>num)
        return ERROR;
    
    childNode = node->next;//获取该节点后继结点
    node->next = childNode->next;//将后继结点的后继赋值给该结点的后继
    node->data = childNode->data;//将后继结点的数据赋值给该节点的后继
    free(childNode);//释放结点，让系统回收内存
    LinkPrint(startNode);
    return OK;
    
}



/*
 **插入结点
 */
int NodeInsert(int num,Link startNode,Link insertNode){
    int check;
    Link *node,*childNode;
    
    node = &startNode;
    check = 1;
    
    while(node && check<num){
        node = node->next;
        check++;
    }
    
    if(!node || check>num){
        return ERROR;
    }
    
    childNode = node->next;
    insertNode.next = childNode;
    node->next = &insertNode;
    free(childNode);
    LinkPrint(startNode);
    return OK;
    
}



/*
 **链表整表删除
 */
int ListClear(Link startNode){
    Link *node,*childnode;
    
    node = &startNode;
    node = node->next;
    while(node){//没到表尾
        childnode = node->next;//获得下一个结点
        free(node);//释放结点内存空间
        node = childnode;//将下一个结点赋值
    }

    //LinkPrint(startNode);
    return OK;
}