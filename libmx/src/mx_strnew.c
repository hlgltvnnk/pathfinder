#include "../inc/libmx.h"

char *mx_strnew(const int size){
    char *h;
    if(size < 0) 
        return NULL;
    h = (char *) malloc(size+1);
    if (h == NULL) 
        return NULL;
    else{
        for(int i = 0; i <= size; i++){
            h[i] = '\0';
        }
    }
    return (char *) h;
}


