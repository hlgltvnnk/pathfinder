#include "../inc/libmx.h"

char* mx_strndup(const char* s1, size_t n)
{
    if(s1 == NULL) 
        return NULL;
    char *c =  mx_strnew(n);
    if(c == NULL) 
        return NULL;
    mx_strncpy(c, s1, n);
    return c;
}





