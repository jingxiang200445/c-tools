//
// Created by 廖經翔 on 2022/9/25.
//

#include "j_multikey_Dictionary.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define J_MULTIKEY_DICT_INIT_EXTEND_SPACE 5


j_multikey_Dictionary * j_multikey_Dictionary_new(unsigned char value_size, unsigned int capacity){

    j_multikey_Dictionary * dict = (j_multikey_Dictionary *)malloc(sizeof (j_multikey_Dictionary));
    dict->length = 0;

    dict->capacity = capacity;
    dict->value_size = value_size;
    dict->keys = (long **)malloc(capacity* sizeof(long*));
    dict->values = malloc(capacity* sizeof(value_size));
    dict->extend_space = J_MULTIKEY_DICT_INIT_EXTEND_SPACE;
    return dict;
}
void j_multikey_Dictionary_put(j_multikey_Dictionary* self, void* value,int key_len, ...){

    if (self->capacity==self->length){
        self->capacity+= self->extend_space;
        void * n_keys = realloc(self->keys, sizeof (long*)* self->capacity);
        void * n_values = realloc(self->values, self->value_size* self->capacity);
        self->keys = n_keys;
        self->values = n_values;

    }

    long *keys = (long *)malloc(key_len * sizeof(long ));
    va_list vaList;
    va_start(vaList, key_len);
    for (int i = 0; i < key_len; ++i) {
        keys[i] = (long)va_arg(vaList, long);
    }

    va_end(vaList);
    self->keys[self->length] = keys;
    memcpy(self->values+ (self->length*self->value_size), value, self->value_size);
    ++ self->length;
}
void* j_multikey_Dictionary_get(j_multikey_Dictionary* self, long key){
    for (int i = 0; i < self->length; ++i) {
        long * keys = self->keys[i];
        for (int j = 0; keys[j]!=NULL ; ++j) {

            if (keys[j]==key)return self->values + self->value_size*i;

        }

    }
    return NULL;
}
void j_multikey_Dictionary_delete(j_multikey_Dictionary* self){
    for (int i = 0; i < self->length; ++i) {
        free(self->keys[i]);
    }
    free(self->keys);
    free(self->values);
    free(self);
    self = NULL;
}