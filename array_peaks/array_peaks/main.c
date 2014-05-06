//
//  main.c
//  array_peaks
//
//  Created by tianling on 14-5-4.
//  Copyright (c) 2014年 罗鑫宇. All rights reserved.
//  实现求目标序列中的极大值（peaks）

#include <stdio.h>
const int MAXSIZE = 100;

typedef struct array{
    int arrayData[MAXSIZE];
    int length;
}targetArray;//定义存储目标序列的结构体

typedef struct pre{
    int arraydata[MAXSIZE];//处理后的数组
    int keyData[MAXSIZE];//对应的键（处理之前的键值对关系）
    int length;//占用的长度
}preWork;//定义预处理之后的结构体

typedef struct goal{
    int keys[MAXSIZE];//键结果集
    int values[MAXSIZE];//值结果集
    int length;
}goalValue;//定义结果集结果体

/*函数声明*/
preWork arrPretreatment(targetArray *targetArray);
goalValue getPeaksValue(preWork *singleArray);

int main(int argc, const char * argv[])
{
    int length,i;
 
    printf("Please Input the length of the target array!");
    scanf("%d",&length);
    if(length >= MAXSIZE){
        printf("the array is too long!");
        return -1;
    }
    
    targetArray array;//初始化目标序列
    array.length = length;
    
    printf("Please input the values!");
    for(i = 0;i<length;i++){
        scanf("%d",&array.arrayData[i]);
    }
    
    preWork finiarray;//定义存储于处理之后序列的结构体
    finiarray = arrPretreatment(&array);
    
    goalValue goal;//定义结果序列
    goal =  getPeaksValue(&finiarray);
    
    for(i = 0;i<goal.length;i++){
        printf("key: %d",goal.keys[i]);
        printf("value: %d\n",goal.values[i]);
    }

}


/*
 **通过预处理去除目标序列中部分重复元素
 */
preWork arrPretreatment(targetArray *targetArray){
    preWork singleArray;
    singleArray.length = 0;
    int i;
    
    for (i = 0;i<targetArray->length;i++){
        if(singleArray.length == 0){
            singleArray.arraydata[singleArray.length] = targetArray->arrayData[i];
            singleArray.keyData[singleArray.length] = i;
            singleArray.length++;
            
            
        }else{
            if(targetArray->arrayData[i] == singleArray.arraydata[singleArray.length-1]){
                //除去连续相同的元素
                continue;
            }else{
                singleArray.arraydata[singleArray.length] = targetArray->arrayData[i];
                singleArray.keyData[singleArray.length] = i;//保存值的同时保存键
                singleArray.length++;

            }
            
        }
    }
    
    return singleArray;
    
}


/*
 **获取极大值
 */
goalValue getPeaksValue(preWork *singleArray){
    goalValue goal;
    int i;
    
    goal.length = 0;
    for(i = 1;i<singleArray->length-1;i++){
        
        if(singleArray->arraydata[i]>singleArray->arraydata[i-1] && singleArray->arraydata[i]>singleArray->arraydata[i+1]){//对前后元素进行比较
            
            goal.values[goal.length] = singleArray->arraydata[i];//保存值
            goal.keys[goal.length] = singleArray->keyData[i];//保存键（未处理前的键）
            goal.length++;
        }
    }
    
    return goal;
}

