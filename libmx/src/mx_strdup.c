#include "../inc/libmx.h"

char *mx_strdup(const char *str){
    char *d = mx_strnew(mx_strlen(str) + 1);
    if (d == NULL)  
        return NULL;
    else {
        mx_strcpy(d, str);
    }
    return (char *) d;
}
