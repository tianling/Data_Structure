//
// Created by luoxinyu-xy on 2017/6/12.
//
#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

#ifndef DATA_STRUCTURE_HASHMAP_H
#define DATA_STRUCTURE_HASHMAP_H

#endif //DATA_STRUCTURE_HASHMAP_H


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MaxSize 100

#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 //hash表长度
#define NULLKEY -32768

typedef int Status;

typedef struct{
    int *elem; //数据元素存储基址，动态分配数组
    int count; //当前数据元素个数
}HashTable;

int m = 0;




