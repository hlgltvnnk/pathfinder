#include "../inc/pathfinder.h"

static void print_data(char **ostrov, char **buf) {
    int j = 0;

    write(1, "Path: ", mx_strlen("Path: "));
    write(1, ostrov[mx_atoi(buf[0])], 
        mx_strlen(ostrov[mx_atoi(buf[0])]));
    write(1, " -> ", 4);
    for ( ; buf[j]; j++);
    write(1, ostrov[mx_atoi(buf[j - 1])],
         mx_strlen(ostrov[mx_atoi(buf[j - 1])]));
    write(1, "\n", 1);

    write(1, "Route: ", mx_strlen("Route: "));
    write(1, ostrov[mx_atoi(buf[0])], 
        mx_strlen(ostrov[mx_atoi(buf[0])]));
    for (j = 1; buf[j]; j++) {
        write(1, " -> ", 4);
        write(1, ostrov[mx_atoi(buf[j])], 
            mx_strlen(ostrov[mx_atoi(buf[j])]));
    }
    write(1, "\n", 1);
}

static void print_distance(int **mas_res, int index, int res[], int i) {
    write(1, "Distance: ", mx_strlen("Distance: "));
    mx_printint(mas_res[index][0]);
    for (int j = 1; mas_res[index][j] != -1; j++) {
        write(1, " + ", 3);
        mx_printint(mas_res[index][j]);
    }
    if (mas_res[index][0] != res[i]) {
        write(1, " = ", 3);
        mx_printint(res[i]);
    }
}

static int *sum_way(int globlen, int **mas_res) {
    int *res = new_row(globlen, 0);

    for (int i = 0; i < globlen; i++) {
        int sum = 0;
        for (int j = 0; mas_res[i][j] != -1; j++) 
            sum += mas_res[i][j];
        res[i] = sum;
    }
    return res;
}

void printsort(int **mas_res, int len, char **arr, char **isl) {
    int *res = sum_way(len, mas_res);
    int *copy_res = new_row(len, 0);
    int *mark;
    char **buf;

    for (int i = 0; i < len; i++)
        copy_res[i] = res[i];
    mx_bubble_sort_int(res, len);
    mark = new_row(len, 0);
    for (int i = 0; i < len; i++) {
        if (res[i] == res[0]) {
            int index = indexfind(copy_res, res[i], &mark, arr);
            write(1, "========================================\n", 41);
            buf= mx_strsplit(arr[index], '*');
            print_data(isl, buf);
            print_distance(mas_res, index, res, i);
            write(1, "\n========================================\n", 42);
            mx_del_strarr(&buf);
        }  
    }
    free(res);
    res = NULL;
}


