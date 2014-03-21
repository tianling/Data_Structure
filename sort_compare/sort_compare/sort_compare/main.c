//
//  main.c
//  sort_compare
//
//  Created by tianling on 14-3-21.
//  Copyright (c) 2014年 tianling. All rights reserved.
//  简单实现几种排序算法之间的效率比较

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


const int MAXSIZE = 250;//定义排序样本最大长度

/*
 **定义存放样本数据的结构体
 */
typedef struct data{
    int dataArray[MAXSIZE];//定义临时存放排序样本的数组
    int length;
}dataArray;


/*
 **函数声明
 */
void bubbleSort(dataArray *array);
void printArray(dataArray *array);

int main(int argc, const char * argv[])
{
    int i = 0,temp;
    FILE *file;
    dataArray array;
    array.length = 0;
    clock_t start_time,end_time;
    double work_time;
    
    if((file = fopen("/Users/tianling/Documents/Data_Structure/sort_compare/sort_compare/data.txt","r")) == NULL){
        printf("文件读取失败！");
        return 1;
    }
    
    while((fscanf(file,"%d",&temp)) != EOF ){
        array.dataArray[i] = temp;
        i++;
        array.length++;
    }
    
    printArray(&array);
    
    start_time = clock();
    bubbleSort(&array);
    end_time = clock();
    
    work_time = (double)end_time - start_time;
    printArray(&array);
    printf("运行时间 %lf ms",work_time);
    return 0;
}


/*
 **冒泡法排序
 */
void bubbleSort(dataArray *array){
    int i,j,change;
    
    for(i = 0;i<array->length;i++){
        for(j = array->length-2;j>=i;j--){
            
            if(array->dataArray[j]<array->dataArray[j+1]){
                change = array->dataArray[j];
                array->dataArray[j] = array->dataArray[j+1];
                array->dataArray[j+1] = change;
            }
        }
    }
    
}


/*
 **打印结果集
 */
void printArray(dataArray *array){
    int i;
    
    for(i = 0;i<array->length;i++){
        printf("%d ",array->dataArray[i]);
    }
    printf(" \n");
}