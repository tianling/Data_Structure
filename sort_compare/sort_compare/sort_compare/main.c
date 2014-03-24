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

typedef int status;

/*
 **函数声明
 */
void bubbleSort(dataArray *array);
void printArray(dataArray *array);
void selectSort(dataArray *array);
void insertSort(dataArray *array);
status tableList();

status main(int argc, const char * argv[])
{
    int i = 0,temp,choose;
    FILE *file;
    dataArray array;
    array.length = 0;
    clock_t start_time,end_time;
    double work_time;
    
    //从文本中读取排序样本
    if((file = fopen("/Users/tianling/Documents/Data_Structure/sort_compare/sort_compare/data.txt","r")) == NULL){
        printf("文件读取失败！");
        return 1;
    }
    
    while((fscanf(file,"%d",&temp)) != EOF ){
        array.dataArray[i] = temp;
        i++;
        array.length++;
    }
    printf("初始数据：\n");
    printArray(&array);
    
    choose = tableList();
    while (choose != 0) {
        switch(choose){
            case 1:
                start_time = clock();
                bubbleSort(&array);
                end_time = clock();
                
                work_time = (double)end_time - start_time;
                printArray(&array);
                printf("运行时间 %lf ms \n",work_time);
                break;
                
            case 2:
                start_time = clock();
                selectSort(&array);
                end_time = clock();
                
                work_time = (double)end_time - start_time;
                printArray(&array);
                printf("运行时间 %lf ms \n",work_time);
                break;
                
            case 3:
                start_time = clock();
                insertSort(&array);
                end_time = clock();
                
                work_time = (double)end_time - start_time;
                printArray(&array);
                printf("运行时间 %lf ms \n",work_time);
                break;
                
            default:
                exit(0);
                break;
                
        }
        
        choose = tableList();
    }

    
    return 0;
}


/*
 **冒泡法排序
 */
void bubbleSort(dataArray *array){
    int i,j,change;
    
    for(i = 0;i<array->length;i++){
        for(j = array->length-2;j>=i;j--){
            
            if(array->dataArray[j]>array->dataArray[j+1]){
                change = array->dataArray[j];
                array->dataArray[j] = array->dataArray[j+1];
                array->dataArray[j+1] = change;
            }
        }
    }
    
}


/*
 **简单选择排序
 */
void selectSort(dataArray *array){
    int i,j,min,change;
    
    for(i = 0;i<array->length;i++){
        min = i;//以首元素为第一个基准
        
        for(j = i+1;j<array->length;j++){
            if(array->dataArray[min] > array->dataArray[j]){
                //若有小于基准的值，则更换基准
                min = j;
            }
        }
        if(i != min){
            //若min与i不想等，则说明找到这趟排序的最小值，交换
            change = array->dataArray[min];
            array->dataArray[min] = array->dataArray[i];
            array->dataArray[i] = change;
        }
    }
}


/*
 **直接插入排序
 */
void insertSort(dataArray *array){
    int i,j,temp;//temp为哨兵元素
    
    for(i = 1;i<array->length;i++){
        
        if(array->dataArray[i]<array->dataArray[i-1]){
            temp = array->dataArray[i];
            
            for(j = i-1;array->dataArray[j]>temp;j--){
                array->dataArray[j+1] = array->dataArray[j];
            }
            
            array->dataArray[j+1] = temp;
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


/*
 **操作菜单
 */
status tableList(){
    int choose;
    
    printf("*******请选择排序类型*******\n");
    printf("*******1.冒泡法排序********\n");
    printf("*******2.简单选择排序*******\n");
    printf("*******3.直接插入排序*******\n");
    
    scanf("%d",&choose);
    return choose;
}