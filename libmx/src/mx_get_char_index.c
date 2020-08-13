#include "../inc/libmx.h"

int mx_get_char_index(const char* str, char c) {
    if (str == NULL) 
        return -2;
    int i = mx_strlen(str);
    int j = 0;
    for (; j <= i; j++) {
        if (str[j] == c) 
            return j;
        else continue;
    }
    return -1;
}




