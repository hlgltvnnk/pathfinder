#include "../inc/pathfinder.h"

static int ident(char **isl, char **buf, int loc) {
    int flag = 0;

    for(int i = 0; buf[i]; i++) {
        flag = 0;
        for(int j = 0; isl[j]; j++) {
            if(mx_strcmp(isl[j], buf[i]) == 0) 
                flag = 1;
        }
        if(flag == 0) {
            isl[loc] = mx_strjoin(isl[loc], buf[i]);
            loc++; 
        }
    }
    return loc;
}

char **isl_arr( int n, char **bufarr) {
    char **isl = (char **) malloc(sizeof(char *) * (n + 1)); // вывод в масив осторовов
    char **tmp;
    int loc = 1;
    char **buf;
    
    for (int i = 0; i <= n; i++) 
        isl[i] = NULL;
    tmp = line_set(bufarr[1]);
    isl[0] = mx_strjoin(isl[0], tmp[0]);
    for (int i = 1; bufarr[i]; i++) {
        buf = line_set(bufarr[i]);
        loc = ident(isl, buf, loc);
        mx_del_strarr(&buf);
    }
    mx_del_strarr(&tmp);
    return isl;
}


