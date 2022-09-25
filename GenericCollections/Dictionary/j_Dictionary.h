//
// Created by 廖經翔 on 2022/9/25.
//

#ifndef C_TOOLS_J_DICTIONARY_H
#define C_TOOLS_J_DICTIONARY_H

typedef struct {

    long *keys;
    void *values;
    unsigned int length;
    unsigned int capacity;
    unsigned char value_size, extend_space;

} j_Dictionary;

j_Dictionary * j_Dictionary_new(unsigned char value_size, unsigned int capacity);
void j_Dictionary_put(j_Dictionary* self, long key, void* value);
void* j_Dictionary_get(j_Dictionary* self, long key);
void j_Dictionary_delete(j_Dictionary* self);
#endif //C_TOOLS_J_DICTIONARY_H
