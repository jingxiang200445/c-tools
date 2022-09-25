//
// Created by 廖經翔 on 2022/9/25.
//

#ifndef C_TOOLS_J_MULTI_KEY_DICTIONARY_H
#define C_TOOLS_J_MULTI_KEY_DICTIONARY_H
typedef struct {

    long **keys;
    void *values;
    unsigned int length;
    unsigned int capacity;
    unsigned char value_size, extend_space;

} j_multikey_Dictionary;

j_multikey_Dictionary * j_multikey_Dictionary_new(unsigned char value_size, unsigned int capacity);
void j_multikey_Dictionary_put(j_multikey_Dictionary* self, void* value,int key_len, ...);
void* j_multikey_Dictionary_get(j_multikey_Dictionary* self, long key);
void j_multikey_Dictionary_delete(j_multikey_Dictionary* self);
#endif //C_TOOLS_J_MULTI_KEY_DICTIONARY_H
