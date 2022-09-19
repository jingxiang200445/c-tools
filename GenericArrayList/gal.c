
// Created by 廖經翔 on 2022/9/19.


#include <printf.h>
#include "gal.h"
#include "stdarg.h"
gal * gal_new(unsigned int capacity, unsigned char size){
    gal * arr = (gal *)malloc(sizeof(gal));
    void* data_mem = malloc(capacity * sizeof(size)) ;
    arr->unit_size = size;
    arr->capacity = capacity;
    arr->length = 0;
    arr->extend_space = GAL_DEFAULT_EXTEND_SPACE;
    arr->data_mem = data_mem;
    return arr;
}

void gal_add(gal* gal, void* datum){
    printf("p added: %p\n", datum);
    unsigned char unit_size = gal->unit_size;
    if (gal->capacity==gal->length){

        void* new_data_mem = malloc(unit_size * (gal->capacity + gal-> extend_space));
        for (int i = 0; i < unit_size*gal->length; ++i) {
            ((char*)new_data_mem)[i] = ((char*)gal->data_mem)[i];
        }
        free(gal->data_mem);
        gal->capacity+= gal->extend_space;
        gal->data_mem = new_data_mem;
    }

    for (int i = 0; i < unit_size; ++i) {
        ((char*)gal->data_mem)[(gal->length*unit_size)+i] = ((char*)datum)[i];
    }
    ++ gal->length;
}
void gal_addAll(gal* gal, int len,... ){
    va_list va;
    void *p;

    va_start(va, len);
    for (int i = 0; i < len; ++i) {
        p = va_arg(va, void*);
        printf("p = %p\n", p);
        gal_add(gal,p);
    }

    va_end(va);
}
void gal_remove(gal* gal, unsigned int index){
    unsigned char unit_size = gal->unit_size;
    unsigned int literal_index = unit_size * index;
    --gal->length;
    for (; literal_index < unit_size*gal->length; ++literal_index) {
        ((char*)gal->data_mem)[literal_index] = ((char*)gal->data_mem)[literal_index+unit_size];
    }

}


void gal_free(gal* gal){
    free(gal->data_mem);
    free(gal);
    gal = NULL;
}

void gal_info(gal* gal){

    printf("*****GAL*****\n"
           "length   = %d\n"
           "capacity = %d\n"
           "unit     = %d\n"
           "byte used= %d\n"
           "*************\n", gal->length, gal->capacity, gal->unit_size, gal->unit_size* gal->length
           );
}
