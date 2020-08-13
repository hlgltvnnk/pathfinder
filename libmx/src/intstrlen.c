#include "../inc/libmx.h"

int intstrlen(int num){
    int i = 0; 
    for (; num > 0; i++)
        num /= 10;
    return i;
}
