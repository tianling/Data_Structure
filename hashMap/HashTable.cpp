//
// Created by luoxinyu-xy on 2017/6/12.
//
#include "HashTable.h"

int main()
{
    HashTable H;

    InitHashTable(&H);
    int list[HASHSIZE] = {3,5,7,12,45,78,84,65,2,1,55,40,42};

    for(int i = 0;i < HASHSIZE;i++){
        InsertHash(&H,list[i]);
    }

    int searchKey = 5;
    int addr;
    Status search = SearchHash(&H,searchKey,&addr);

    if(search){
        printf("寻找%d,位置:%d\n",searchKey,addr);
    }else{
        printf("搜索失败 \n");
    }

    for(int i = 0;i < HASHSIZE;i++){
        SearchHash(&H,list[i],&addr);
        printf("key: %d,position: %d\n",list[i],addr);
    }


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


void InsertHash(HashTable *H ,int key)
{
    int addr = Hash(key);
    while (H->elem[addr] != NULLKEY){
        addr = (addr + 1) % HASHP; //开放定址法处理冲突
    }

    H->elem[addr] = key;
}


Status SearchHash(HashTable *h,int key,int *addr)
{
    *addr = Hash(key);
    if(h->elem[*addr] == NULLKEY){
        return UNSUCCESS;
    }

    while(h->elem[*addr] != key){
        *addr = (*addr + 1) % HASHP;
        if(h->elem[*addr] == NULLKEY || *addr == Hash(key)){
            return UNSUCCESS;
        }
    }

    return SUCCESS;

}





