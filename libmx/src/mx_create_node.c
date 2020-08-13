#include "../inc/libmx.h"

t_list  *mx_create_node(void *data){
    t_list *t = malloc(1);
    t->data = data;
    t->next = NULL;
    return t;
}

