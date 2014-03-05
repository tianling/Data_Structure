//
//  main.c
//  QueueWork
//
//  Created by tianling on 14-3-5.
//  Copyright (c) 2014年 tianling. All rights reserved.
//  实现队列的创建，出队，入队操作

#include <stdio.h>
#define ERROR 1
#define OK 0
#define MaxSize 5

typedef int status;

typedef struct{
    int data[MaxSize];
    int front;
    int rear;
}queue;

/*
 函数声明
 */
status tableList();
status QueueInit(queue *Q);
status QueueLength(queue Queue);
status QueueInsert(queue *Q,int data);
status QueueOut(queue *Q);

status main()
{
    int choose,data,work;
    queue Queue,*Q;
    
    Q = &Queue;
    choose = tableList();
    QueueInit(Q);
    
    while(choose == 1 || choose ==2){
        switch(choose){
            case 1:
                printf("请输入入队数据!");
                scanf("%d",&data);
                
                work = QueueInsert(Q, data);
                
                if(work == ERROR){
                    printf("队列满，无法入队!");
                    break;
                }
                else
                    printf("插入成功!");
                break;
                
            case 2:
                work = QueueOut(Q);
                if(work == ERROR){
                    printf("队列为空!");
                    break;
                }
                
                while((work != ERROR)){
                    work = QueueOut(Q);
                }
                
                break;
            
        }
        
        choose = tableList();
    }
    
    return 0;

}


/*
 **菜单函数
 */
status tableList(){
    int choose;
    
    printf("***************请选择操作***************");
    printf("*************1.入队********************");
    printf("*************2.出队********************");
    printf("*************3.退出********************");
    
    scanf("%d",&choose);
    return choose;
}


/*
 **队列初始化函数
 */
status QueueInit(queue *Q){
    Q->front = 0;//初始化一个空队列(当前(rear+1)%MaxSize != front)
    Q->rear = 0;
    
    return OK;
}


/*
 **队列长度计算
 */
status QueueLength(queue Queue){
    int Length;
    
    Length = (Queue.rear - Queue.front + MaxSize)%MaxSize;
    return  Length;
}


/*
 **入队操作
 */
status QueueInsert(queue *Q,int data){
    int chage;
    chage = (Q->rear + 1)%MaxSize;
    if(chage == Q->front)
        return ERROR;
    
    Q->data[Q->rear] = data;
    Q->rear = (Q->rear + 1)%MaxSize;
    return OK;
    
}


/*
 **出队操作
 */
status QueueOut(queue *Q){
    int data;
    
    if(Q->front == Q->rear)
        return ERROR;
    
    data = Q->data[Q->front];
    printf("%d \n",data);
    Q->front = (Q->front + 1)%MaxSize;
    return OK;
    
}


