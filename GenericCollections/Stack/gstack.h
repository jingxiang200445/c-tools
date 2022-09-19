//
// Created by 廖經翔 on 2022/9/19.
//

#ifndef C_TOOLS_GSTACK_H
#define C_TOOLS_GSTACK_H
#ifndef G_STACK_H
#define G_STACK_H
#include <stdbool.h>
typedef struct gnode
{
    void* data;
    struct gnode *prev;
} gnode;

typedef struct gstack
{
    unsigned char size;
    gnode *top, *bottom;


} gstack;

static gnode* gnode_new(void* data);

gstack* gstack_new(unsigned char size);
void gstack_free(gstack* self);
bool gstack_isEmpty(gstack* self);
void* gstack_top(gstack* self);
bool gstack_push(gstack* self, void* data);
void* gstack_pop(gstack* self);


#endif
#endif //C_TOOLS_GSTACK_H
