//
// Created by 廖經翔 on 2022/9/25.
//

#include "j_Dictionary.h"
#include <stdlib.h>
#include <string.h>
#define J_DICT_INIT_EXTEND_SPACE 5

j_Dictionary * j_Dictionary_new(unsigned char value_size, unsigned int capacity){

    j_Dictionary * dict = (j_Dictionary *)malloc(sizeof (j_Dictionary));
    dict->length = 0;

    dict->capacity = capacity;
    dict->value_size = value_size;
    dict->keys = malloc(capacity* sizeof(long));
    dict->values = malloc(capacity* sizeof(value_size));
    dict->extend_space = J_DICT_INIT_EXTEND_SPACE;
    return dict;
}
void j_Dictionary_put(j_Dictionary* self, long key, void* value){
    if (self->capacity==self->length){
        self->capacity+= self->extend_space;
        long * n_keys = (long *)realloc(self->keys, sizeof (long )* self->capacity);
        void * n_values = realloc(self->values, self->value_size* self->capacity);
        self->keys = n_keys;
        self->values = n_values;

    }
    self->keys[self->length] = key;
    memcpy(self->values+ (self->length*self->value_size), value, self->value_size);
    ++ self->length;
}
void* j_Dictionary_get(j_Dictionary* self, long key){
    for (int i = 0; i < self->length; ++i) {
        if (self->keys[i]==key)return self->values + self->value_size*i;

    }
}
void j_Dictionary_delete(j_Dictionary* self){
    free(self);
    self = NULL;
}