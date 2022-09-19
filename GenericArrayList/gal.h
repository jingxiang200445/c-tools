//
// Created by 廖經翔 on 2022/9/19.
//

#ifndef GENERICARRAYLIST_GENERICARRAYLIST_H
#define GENERICARRAYLIST_GENERICARRAYLIST_H

#include <stdlib.h>

#define GAL_DEFAULT_EXTEND_SPACE 5
typedef struct gal{
    void* data_mem;
    unsigned char unit_size;
    unsigned int length;
    unsigned int capacity;
    unsigned int extend_space;
} gal;

gal * gal_new(unsigned int capacity, unsigned char size);

void gal_add(gal* gal, void* datum);
void gal_addAll(gal* gal, int len,... );
void gal_remove(gal* gal, unsigned int index);

void gal_free(gal* gal);

void gal_info(gal* gal);

#endif //GENERICARRAYLIST_GENERICARRAYLIST_H
