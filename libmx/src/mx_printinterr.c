#include "../inc/libmx.h"

static void mx_printcharerr(char c){
    write(2, &c, 1);
}

void mx_printinterr(int n){
    int i = 0;
    int flag = 0;
    int y;
    int b;
    if(n == 0) 
        mx_printcharerr('0');
    if(n < 0) {
        flag = 1;
        n *= -1;
    }   
    y = n;
    for( ; y > 0; y/=10)
        i++; 
    char d[i];
    b = i - 1;
    for( ; n > 0; n/=10) {
        d[b] = (n%10) + '0';
        b--;
    }
     for( int u = 0; u < i; u++){
        if (flag != 0){
            write(2, "-", 1);
            flag = 0;
        }
        mx_printcharerr(d[u]);
    }
}
