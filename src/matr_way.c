#include "../inc/pathfinder.h"

static int get_len(char *arr) {
    int res;
    char **buf1 = mx_strsplit(arr, '-');
    char **buf2 = mx_strsplit(buf1[1], ',');
    
    res = mx_atoi(buf2[1]);
    mx_del_strarr(&buf1);
    mx_del_strarr(&buf2);
    return res;
}

static int get_ind(char **isl, char *buf) {
    int ind = 0;

    for( ; isl[ind]; ind++) {
        if (mx_strcmp(isl[ind], buf) == 0)
            break;
    }
    return ind;
}

static void sum_check(int **m) {
    long int sum = 0;

    for (int i = 0; m[i]; i++) {
        for (int j = 0; j <= i; j++)
            sum += m[i][j];
    }
    if(sum >= 2147483647){
        write(2, "too long num", 
        mx_strlen("too long num"));
        exit(1);
    }
}

int **matr_way(int n, char **arr, int count, char **island) {
    int **mtrx = (int **) malloc(sizeof(int *) * (n + 1));
    char **pair;
    int len;
    int a, b;

    for (int i = 0; i < n; i++)
        mtrx[i] = new_row(n, 0);
    for (int k = 1; k < count; k++) {
        pair = line_set(arr[k]);
        len = get_len(arr[k]);
        a = get_ind(island, pair[0]);
        b = get_ind(island, pair[1]);
        mtrx[a][b] = len;
        mtrx[b][a] = len;
        mx_del_strarr(&pair);
    }
    sum_check(mtrx);
    return mtrx;
}

