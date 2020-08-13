#include "../inc/pathfinder.h"

char **line_set(char *arr) {
    char **buf1;
    char **buf2;
    char **res = (char **) malloc (sizeof(char *) * 3);

    for (int i = 0; i < 3; i++) 
        res[i] = NULL;
    buf1 = mx_strsplit(arr, '-');
    buf2 = mx_strsplit(buf1[1], ',');
    res[0] = mx_delit_fre(res[0], buf1[0]);
    res[1] = mx_delit_fre(res[1], buf2[0]);
    mx_del_strarr(&buf1);
    mx_del_strarr(&buf2);
    return res;
}
