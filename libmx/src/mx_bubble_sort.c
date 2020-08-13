#include "../inc/libmx.h"

 int mx_bubble_sort(char **arr, int size){
     int p = 0;
    for( int i = size - 1; i > 0; i--){
        for(int h = 0; h < size - 1; h++){
            if (mx_strcmp(arr[h], arr[h+1]) > 0){
                    char *c = arr[h];
                    arr[h] = arr[h+1];
                    arr[h+1] = c;
                    p++;
                }
            else continue;
        }
    }
    return p;
 }






