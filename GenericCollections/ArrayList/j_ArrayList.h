
// Created by 廖經翔 on 2022/9/19.


#ifndef GENERICARRAYLIST_GENERICARRAYLIST_H
#define GENERICARRAYLIST_GENERICARRAYLIST_H

#include <stdlib.h>

#define j_ArrayList_DEFAULT_EXTEND_SPACE 5
typedef struct {
    void* data_mem;
    unsigned char unit_size;
    unsigned int length;
    unsigned int capacity;
    unsigned int extend_space;
} j_ArrayList;

j_ArrayList * j_ArrayList_new(unsigned int capacity, unsigned char size);

void j_ArrayList_add(j_ArrayList* j_ArrayList, void* datum);
void j_ArrayList_addAll(j_ArrayList* j_ArrayList, int len, ... );
void j_ArrayList_remove(j_ArrayList* j_ArrayList, unsigned int index);

void j_ArrayList_free(j_ArrayList* j_ArrayList);

void j_ArrayList_info(j_ArrayList* j_ArrayList);

#endif //GENERICARRAYLIST_GENERICARRAYLIST_H
