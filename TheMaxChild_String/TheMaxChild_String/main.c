//
//  main.c
//  TheMaxChild_String
//
//  Created by tianling on 14-5-5.
//  Copyright (c) 2014年 罗鑫宇. All rights reserved.
//  实现求字符串最大不重复子串

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAXSIZE = 255;//定义字符串最大长度
#define ERROR 1;
#define OK 0;

typedef struct string{
    char string[MAXSIZE];//定义存储子序列字符串的成员
    int length;//定义改成员对应长度
    struct string *next;
}childString;//定义存储各子串的结构体

childString *headNode = NULL;//定义子串序列链表头指针

/*
 **函数声明
 */
void makeChildStringLinkList(char parentString[],int beginPosition);
int stringCheck(char value,childString *childString);
childString *SortedMerge(childString *pre,childString *next);
void FrontBackSplit(childString *source,childString **pre,childString **next);
void mergeSort(childString **headnode);

int main(int argc, const char * argv[])
{
    char parentString[MAXSIZE];//定义目标主串
    
    printf("Plsease input the parent string! \n");
    scanf("%s",parentString);//输入主串
    
    int beginPosition = 0;//定义不重复子串在主串中的起始位置
    
    makeChildStringLinkList(parentString, beginPosition);
    mergeSort(&headNode);
    
    if(headNode == NULL){
        printf("空字符串！");
        return -1;
    }else{
        printf("最大不重复序列：\n");
        printf("%s \n",headNode->string);
    }
    
    
}


/*
 **生成存储所有不重复子序列的链表
 */
void makeChildStringLinkList(char parentString[],int beginPosition){
    int i = beginPosition;
    childString *node;
    
    //若链表为空，则生成一个新结点，并将原始序列的第一个元素赋值给这个结点的string作为其第一个元素
    if(headNode == NULL){
        node = (childString*)malloc(sizeof(childString));
        node->length = 0;
        node->string[node->length] = parentString[i];
        node->length++;
        
        headNode = node;
        i++;
        

    }
    
    while(parentString[i] != '\0' && i<MAXSIZE){
        //check = stringCheck(parentString[i],headNode);
        if(stringCheck(parentString[i],headNode) != 0){
            //如果主序列中的这个元素在子序列中不存在，则将这个元素添加到子序列末尾
            headNode->string[headNode->length] = parentString[i];
            headNode->length++;
            i++;
            continue;
        }else{
            //如果主序列中的这个元素在子序列中存在，则终止当前子序列的写入，生成一个新结点
            node = (childString*)malloc(sizeof(childString));
            beginPosition++;//此时子串在主串中的起始位置后移一位
            node->length = 0;
            node->string[node->length] = parentString[beginPosition];
            node->length++;
            node->next = headNode;
            headNode = node;
            
        }
        
        makeChildStringLinkList(parentString, beginPosition+1);//递归调用该函数，直到所有非重复序列构造完成
        
    }
}

/*
 **检查原序列的对应元素是否在子序列中存在
 */
int stringCheck(char value,childString *childString){
    int i;
    for(i = 0;i<childString->length;i++){
        if(childString->string[i] == value)
            return 0;
    }
    
    return 1;
}

//对存储不重复序列的链表进行归并排序
void mergeSort(childString **headnode){
    childString *pre,*next,*head;
    head = *headnode;
    
    if(head == NULL || head->next == NULL){
        return;
    }
    FrontBackSplit(head,&pre,&next);
    
    mergeSort(&pre);
    mergeSort(&next);
    
    *headnode = SortedMerge(pre,next);


}


/*
 **将链表进行分组
 */
void FrontBackSplit(childString *source,childString **pre,childString **next){
    childString *fast;
    childString *slow;
    
    if(source == NULL || source->next == NULL){
        *pre = source;
        *next = NULL;
    }else{
        slow = source;
        fast = source->next;
        
        while(fast != NULL){
            fast = fast->next;
            
            if(fast != NULL){
                slow = slow->next;
                fast = fast->next;
            }
        }
        *pre = source;
        *next = slow->next;
        slow->next = NULL;
    }
}


/*
 **根据排序结果更换头结点
 */
childString *SortedMerge(childString *pre,childString *next){
    childString *result = NULL;
    
    if(pre == NULL)
        return next;
    else if(next == NULL)
        return pre;
    
    if(pre->length >= next->length){
        result = pre;
        result->next = SortedMerge(pre->next,next);
        
    }else{
        result = next;
        result->next = SortedMerge(pre,next->next);
    }
    return result;
}

