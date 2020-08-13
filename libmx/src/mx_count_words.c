#include "../inc/libmx.h"

int mx_count_words(const char *str, char c){
    if(str == NULL) return -1;
    int o = mx_strlen(str) - 1;
    int count = 0;
         for (int i = 0; str[i]; i++){
             if(str[i] != c && str[i + 1] == c) 
                count ++;
             else continue;
         }
    if(str[o] != c) 
        count ++;
    return count;
}




 

