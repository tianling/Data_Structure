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

typedef int status;
int NodeNum= 0,buildTime = 0;

/*
 **声明二叉树结点结构
 */
typedef struct BiNode{
    char data;//结点结构
    struct BiNode *lChild,*rChild;//左右孩子结点指针
}BitNode,*Bitree;

/*
 **函数声明
 */
void dataArrayGet(char *array);
void BiTreeCreate(char *array,Bitree *T);
void preOrderTraverse(Bitree T);
status List();

status main(int argc, const char * argv[])
{
    char dataArray[MaxSize];
    Bitree Tree;
    int choose;
    
    dataArrayGet(dataArray);
    BiTreeCreate(dataArray,&Tree);
    choose = List();
    
    switch (choose) {
        case 1:
            preOrderTraverse(Tree);
            break;
            
        default:
            break;
    }
    
    
}


/*
 **菜单函数
 */
status List(){
    int choose;
    
    printf("********菜单函数*******\n");
    printf("********1.前序遍历*****\n");
    
    scanf("%d",&choose);
    return choose;
}
/*
 **获取待建树数据
 */
void dataArrayGet(char *array){
    FILE *file;
    char temp;
    
    if((file = fopen("/Users/tianling/Documents/Data_Structure/BiTree/data.txt", "r")) == NULL){
        printf("文件打开失败!");
        exit(ERROR);
    }
    
    while(fscanf(file, "%c",&temp) != EOF){
        *array = temp;
        array+=1;
        NodeNum++;
    }
    
    fclose(file);
    
}


/*
 **建立二叉树
 */
void BiTreeCreate(char *array,Bitree *T){

    while(buildTime<NodeNum){
        //若头结点值为空值，则二叉树为空树
        if(*array == '#'){
            *T = NULL;
            array++;
            buildTime++;
            
        }else{
            *T = (Bitree)malloc(sizeof(BitNode));
            
            if(!*T)
                exit(-1);
            
            (*T)->data = *array;
            array++;
            buildTime++;
        
            //递归建立左子树和右子树(**其实就是按照前序遍历的规则啦**)
            BiTreeCreate(array,&(*T)->lChild);
            BiTreeCreate(array,&(*T)->rChild);
        }
    }
    
    
}


/*
 **前序遍历二叉树
 */
void preOrderTraverse(Bitree T){
    if(T == NULL){
        //printf("空树");
        return;
    }
    printf("%c",T->data);
    
    preOrderTraverse(T->lChild);
    preOrderTraverse(T->rChild);
}