
// Created by 廖經翔 on 2022/9/19.


#include <printf.h>
#include "j_ArrayList.h"
#include "stdarg.h"
j_ArrayList * j_ArrayList_new(unsigned int capacity, unsigned char size){
    j_ArrayList * arr = (j_ArrayList *)malloc(sizeof(j_ArrayList));
    void* data_mem = malloc(capacity * sizeof(size)) ;
    arr->unit_size = size;
    arr->capacity = capacity;
    arr->length = 0;
    arr->extend_space = j_ArrayList_DEFAULT_EXTEND_SPACE;
    arr->data_mem = data_mem;
    return arr;
}

void j_ArrayList_add(j_ArrayList* arr, void* datum){
    printf("p added: %p\n", datum);
    unsigned char unit_size = arr->unit_size;
    if (arr->capacity==arr->length){
        arr->capacity+= arr->extend_space;

        void* new_data_mem = realloc(arr, arr->capacity);

        arr->data_mem = new_data_mem;
    }

    for (int i = 0; i < unit_size; ++i) {
        ((char*)arr->data_mem)[(arr->length*unit_size)+i] = ((char*)datum)[i];
    }
    ++ arr->length;
}
void j_ArrayList_addAll(j_ArrayList* j_ArrayList, int len, ... ){
    va_list va;
    void *p;

    va_start(va, len);
    for (int i = 0; i < len; ++i) {
        p = va_arg(va, void*);
        printf("p = %p\n", p);
        j_ArrayList_add(j_ArrayList,p);
    }

    va_end(va);
}
void j_ArrayList_remove(j_ArrayList* j_ArrayList, unsigned int index){
    unsigned char unit_size = j_ArrayList->unit_size;
    unsigned int literal_index = unit_size * index;
    --j_ArrayList->length;
    for (; literal_index < unit_size*j_ArrayList->length; ++literal_index) {
        ((char*)j_ArrayList->data_mem)[literal_index] = ((char*)j_ArrayList->data_mem)[literal_index+unit_size];
    }

}


void j_ArrayList_free(j_ArrayList* j_ArrayList){
    free(j_ArrayList->data_mem);
    free(j_ArrayList);
    j_ArrayList = NULL;
}

void j_ArrayList_info(j_ArrayList* j_ArrayList){

    printf("*****ArrayList*****\n"
           "length   = %d\n"
           "capacity = %d\n"
           "unit     = %d\n"
           "byte used= %d\n"
           "*******************\n", j_ArrayList->length, j_ArrayList->capacity, j_ArrayList->unit_size, j_ArrayList->unit_size* j_ArrayList->length
           );
}
