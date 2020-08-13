#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len){
    if(src == NULL) 
        return NULL;
    int i = 0;
    for( ; i < len; i++){
        dst[i] = src[i];
    } 
    for(int u = i; u < len; u ++) 
        dst[u] = '\0';
    return dst;
}




