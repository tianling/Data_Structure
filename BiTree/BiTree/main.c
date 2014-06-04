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
int NodeNum= 0;
char dataArray[MaxSize];
char *data = dataArray;


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
void dataArrayGet();
void BiTreeCreate(Bitree *T);
void preOrderTraverse(Bitree T);
void inOrderTraverse(Bitree T);
void postOrderTraverse(Bitree T);
status List();

status main(int argc, const char * argv[])
{
    
    Bitree Tree;
    int choose;
    
    dataArrayGet();
    
    //判断若头节点为空，则二叉树为空树
    if(*data == '#'){
        printf("空树！");
        exit(ERROR);
    }
    
    BiTreeCreate(&Tree);
    choose = List();
    
    while(choose != 0){
        
        switch (choose) {
            case 1:
                preOrderTraverse(Tree);
                break;
                
            case 2:
                inOrderTraverse(Tree);
                break;
                
            case 3:
                postOrderTraverse(Tree);
                break;
                
            case 0:
                exit(OK);
                
            default:
                break;
        }
        
        choose = List();

    }
    
    return OK;
}


/*
 **菜单函数
 */
status List(){
    int choose;
    
    printf("********菜单函数*******\n");
    printf("********1.前序遍历*****\n");
    printf("********2.中序遍历*****\n");
    printf("********3.后序遍历*****\n");
    printf("********0.退出*********\n");
    
    scanf("%d",&choose);
    return choose;
}



/*
 **获取待建树数据
 */
void dataArrayGet(){
    FILE *file;
    char temp;
    
    if((file = fopen("/Users/tianling/Documents/Data_Structure/BiTree/data.txt", "r")) == NULL){
        printf("文件打开失败!");
        exit(ERROR);
    }
    
    while(fscanf(file, "%c",&temp) != EOF){
        *data = temp;
        data++;
        NodeNum++;
    }
    
    fclose(file);
    data -= NodeNum;//指针移位至数组头地址
    
}


/*
 **建立二叉树
 */
void BiTreeCreate(Bitree *T){

    if(*data != '\0'){
        //若头结点值为空值，则二叉树为空树
        if(*data == '#'){
            *T = NULL;
            data++;
            
        }else{
            *T = (Bitree)malloc(sizeof(BitNode));
            
            if(!*T)
                exit(-1);
            
            (*T)->data = *data;
            data++;
            
            //递归建立左子树和右子树(**其实就是按照前序遍历的规则啦**)
            BiTreeCreate(&(*T)->lChild);
            BiTreeCreate(&(*T)->rChild);
        }
    }
    
}


/*
 **前序遍历二叉树
 */
void preOrderTraverse(Bitree T){
    if(T == NULL){
        printf(" ");
        return;
    }
    printf("%c",T->data);
    
    preOrderTraverse(T->lChild);
    preOrderTraverse(T->rChild);
}


/*
 **中序遍历二叉树
 */
void inOrderTraverse(Bitree T){
    if(T == NULL){
        printf(" ");
        return;
    }
    
    //分别中序遍历左子树和右子树
    inOrderTraverse(T->lChild);
    printf("%c",T->data);
    inOrderTraverse(T->rChild);
}


/*
 **后序遍历二叉树
 */
void postOrderTraverse(Bitree T){
    if(T == NULL){
        printf(" ");
        return;
    }
    
    //分别先后续遍历左子树再后续遍历右子树
    postOrderTraverse(T->lChild);
    postOrderTraverse(T->rChild);
    printf("%c",T->data);
    
}