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
void arrayBegin(dataArray *array);
void bubbleSort(dataArray *array);
void printArray(dataArray *array);
void selectSort(dataArray *array);
void insertSort(dataArray *array);
void shellSort(dataArray *array);
void heapSort(dataArray *array);
void heapAdjust(dataArray *array,int i,int length);
void mergeSort(dataArray *array,dataArray *temArray,int s,int t);
void merge(dataArray *array1,dataArray *array2,int i,int m,int n);
void quickSort(dataArray *array);
void Qsort(dataArray *array,int low,int high);
int Partition(dataArray *array,int low,int high);

status tableList();

status main(int argc, const char * argv[])
{
    int choose;
    dataArray array;
    clock_t start_time,end_time;
    double work_time;
    
    arrayBegin(&array);
    printf("初始数据：\n");
    printArray(&array);
    
    choose = tableList();
    while (choose != 0) {
        switch(choose){
            case 1:
                start_time = clock();//获取程序开始运算时间
                bubbleSort(&array);
                end_time = clock();//获取程序结束运算时间
                
                work_time = (double)end_time - start_time;//计算程序运算时间
                printArray(&array);
                printf("运行时间 %lf ms \n",work_time);
                /*重新构造目标样本*/
                arrayBegin(&array);
                break;
                
            case 2:
                start_time = clock();
                selectSort(&array);
                end_time = clock();
                
                work_time = (double)end_time - start_time;
                printArray(&array);
                printf("运行时间 %lf ms \n",work_time);
                arrayBegin(&array);
                break;
                
            case 3:
                start_time = clock();
                insertSort(&array);
                end_time = clock();
                
                work_time = (double)end_time - start_time;
                printArray(&array);
                printf("运行时间 %lf ms \n",work_time);
                arrayBegin(&array);
                break;
                
            case 4:
                start_time = clock();
                shellSort(&array);
                end_time = clock();
                
                work_time = (double)end_time - start_time;
                printArray(&array);
                printf("运行时间 %lf ms \n",work_time);
                arrayBegin(&array);
                break;
                
            case 5:
                start_time = clock();
                heapSort(&array);
                end_time = clock();
                
                work_time = (double)end_time - start_time;
                printArray(&array);
                printf("运行时间 %lf ms \n",work_time);
                arrayBegin(&array);
                break;
                
            case 6:
                start_time = clock();
                mergeSort(&array, &array, 0, 49);
                end_time = clock();
                
                work_time = (double)end_time - start_time;
                printArray(&array);
                printf("运行时间 %lf ms \n",work_time);
                arrayBegin(&array);
                break;
                
            case 7:
                start_time = clock();
                quickSort(&array);
                end_time = clock();
                
                work_time = (double)end_time - start_time;
                printArray(&array);
                printf("运行时间 %lf ms \n",work_time);
                arrayBegin(&array);
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
 **初始化目标序列
 */
void arrayBegin(dataArray *array){
    int i = 0,temp;
    FILE *file;
    
    //从文本中读取排序样本
    if((file = fopen("/Users/tianling/Documents/Data_Structure/sort_compare/sort_compare/data.txt","r")) == NULL){
        printf("文件读取失败！");
        return;
    }
    
    array->length = 0;//初始化目标样本长度
    
    while((fscanf(file,"%d",&temp)) != EOF ){
        array->dataArray[i] = temp;
        i++;
        array->length++;
    }
    
    fclose(file);//关闭文件
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
                array->dataArray[j+1] = array->dataArray[j];//记录后移
            }
            
            array->dataArray[j+1] = temp;//插入到正确位置
        }
    }
}


/*
 **希尔排序
 */
void shellSort(dataArray *array){
    int i,j,temp;
    int increment = array->length;
    
    do{
        increment = increment/3+1;//定义增量序列
        
        for(i = increment;i<array->length;i++){
            
            if(array->dataArray[i] < array->dataArray[i - increment]){
                temp = array->dataArray[i];//用temp暂存
                
                for(j = i-increment;j>=0 && temp < array->dataArray[j];j-=increment){
                    array->dataArray[j+increment] = array->dataArray[j];//记录后移，寻找插入位置
                    
                }
                array->dataArray[j+increment] = temp;//插入
                
            }
        }
        
        
    }while(increment > 1);
}


/*
 **堆排序
 */
void heapSort(dataArray *array){
    int i,temp;
    
    for(i = array->length/2;i>=0;i--){
        heapAdjust(array, i, array->length);//将目标处理成一个大頂堆
    }
    
    for(i = array->length-1;i>0;i--){
        temp = array->dataArray[0];//将堆顶记录和未经交换的子序列中的最后一个序列交换
        array->dataArray[0] = array->dataArray[i];
        array->dataArray[i] = temp;
        
        heapAdjust(array, 0, i-1);//将剩余序列重新调整为一个大頂堆
    }
}


/*
 **将目标处理成大顶堆
 */
void heapAdjust(dataArray *array,int i,int length){
    int temp,j;
    
    temp = array->dataArray[i];
    for(j = 2*i;j<length;j *= 2){//沿关键字较大的孩子结点向下筛选
        
        if(j<length && array->dataArray[j]<array->dataArray[j+1]){//j为关键字中较大记录的下标
            ++j;
        }
        if(temp >= array->dataArray[j])
            break;
        
        array->dataArray[i] = array->dataArray[j];
        i = j;
    }
    array->dataArray[i] = temp;
}


/*
 **归并排序
 */
void mergeSort(dataArray *array,dataArray *temArray,int s,int t){
    int m;
    dataArray TEMP[MAXSIZE+1];
    
    if(s == t){
        temArray->dataArray[s] = array->dataArray[s];
    }
    else{
        m = (s+t)/2;//将目标序列等分为两个序列
        mergeSort(array, TEMP, s, m);
        mergeSort(array, TEMP, m+1, t);
        
        merge(TEMP,temArray,s,m,t);
        
    }
    
    
}



/*
 **将有序子序列归并为有序结果序列
 */
void merge(dataArray *array1,dataArray *array2,int i,int m,int n){
    int j,k,l;
    
    for(j = m+1,k = i;i<=m && j<=n;k++){
        
        if(array1->dataArray[i]<array1->dataArray[j]){
            array2->dataArray[k] = array1->dataArray[i++];
        }else{
            array2->dataArray[k] = array1->dataArray[j++];
        }
    }
    
    if(i<=m){
        for(l = 0;l<=m-i;l++){
            array2->dataArray[k+l] = array1->dataArray[i+l];
        }
    }
    
    if(j<=n){
        for(l = 0;l<=n-j;l++){
            array2->dataArray[k+l] = array1->dataArray[j+l];
        }
    }
}


/*
 **快速排序
 */
void quickSort(dataArray *array){
    Qsort(array, 0, array->length-1);
}


/*
 **对目标样本中的子序列array(low...high)做快速排序
 */
void Qsort(dataArray *array,int low,int high){
    int pivot;
    
    if(low<high){
        pivot = Partition(array, low, high);//将dataArray[low...high]一分为二，并返回枢轴下标
        
        Qsort(array, low, pivot-1);//递归对低子表进行排序
        Qsort(array, pivot+1, high);//递归对高子表进行排序
   
    }
}


/*
 **交换顺序表dataArray中子表的记录，使枢轴记录到位，并返回其所在位置
 **目标使枢轴两边的元素均不大于（小于）它
 */
int Partition(dataArray *array,int low,int high){
    int pivotKey,temp;
    
    pivotKey = array->dataArray[low];//用子表的第一个记录作为枢轴记录
    
    while(low<high){//从两端交替向中间扫描
        
        while(low<high && array->dataArray[high]>=array->dataArray[pivotKey]){
            high--;
        }
        temp = array->dataArray[high];//将比枢轴小的记录交换到低端
        array->dataArray[high] = array->dataArray[low];
        array->dataArray[low] = temp;
        
        while(low<high && array->dataArray[low]<=array->dataArray[pivotKey]){
            low++;
        }
        temp = array->dataArray[high];//将比枢轴大的记录交换到高端
        array->dataArray[high] = array->dataArray[low];
        array->dataArray[low] = temp;
        
    }
    
    return low;//返回枢轴所在的位置
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
    printf("*******4.希尔排序***********\n");
    printf("*******5.堆排序*************\n");
    printf("*******6.归并排序***********\n");
    printf("*******7.快速排序***********\n");
    
    scanf("%d",&choose);
    return choose;
}