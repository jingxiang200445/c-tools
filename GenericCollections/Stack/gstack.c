//
// Created by 廖經翔 on 2022/9/19.
//

#include "gstack.h"
#include "gstack.h"
#include "stdlib.h"

static gnode* gnode_new(void* data){
    gnode *node = (gnode*)malloc(sizeof(gnode));

    node->data = data;
    node->prev = NULL;
    return node;

}

gstack* gstack_new(unsigned char size){
    gstack *stack = (gstack*)malloc(sizeof(gstack));
    stack->size = size;
    stack->top = NULL;
    stack->bottom = NULL;
    return stack;
}
void gstack_free(gstack* self){
}
bool gstack_isEmpty(gstack* self){
    return (self->top) ? false: true;
}
void* gstack_top(gstack* self){
    return self->top->data;
}
bool gstack_push(gstack* self, void* data){
    gnode *node = gnode_new(data);
    if(!self->top){
        self->top = node;
        self->bottom = node;
        return true;
    }

    node-> prev = self->top;
    self-> top = node;

    return true;

}
void* gstack_pop(gstack* self){
    if(!self->top)return NULL;

    void* popped = self->top->data;

    if(self->top == self->bottom){
        free(self->top);
        self->top = NULL;
        self->bottom = NULL;
    }else{
        gnode *curr = self->top;
        self->top = curr->prev;
        free(curr);
    }

    return popped;
}