//
// Created by luoxinyu-xy on 2017/6/12.
//
#include "HashTable.h"

int main()
{
    printf("hello");
    HashTable H;

    InitHashTable(&H);

    return 0;
}

Status InitHashTable(HashTable *H)
{
    int i,j;
    m = HASHSIZE;
    H->count = m;
    H->elem = (int *)malloc(m* sizeof(int));
    for(i = 0;i < m;i++){
        H->elem[i] = NULLKEY;
    }

    if(m<2){
        return UNSUCCESS;

    }else{
        for(i = 2;i <= m;i++){
            for(j = 2;j < i;j++){
                if(i % j == 0){
                    break;
                }
            }

            if(j == i){
                HASHP = i;
            }
        }

    }

    return OK;
}

int Hash(int key)
{
    return key % HASHP;//除留取余法
}


