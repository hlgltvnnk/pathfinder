#include "../inc/pathfinder.h"

static char **file_to_arr(char *c[]) {
    char *s = mx_file_to_str(c[1]);
    char **bf = mx_strsplit(s, '\n');
    free(s);
    s = NULL;
    return bf;
}

static void find_ways(char **buf) {
    int count = 0;
    int num;
    char **island;
    int **way_matrix;

    //connection count
    for ( ;buf[count]; count++);
    //islands count
    num = mx_atoi(buf[0]);
    if (val_count(buf, num)) {
        island = isl_arr(num, buf);
        way_matrix = matr_way(num, buf, count, island);
        calculate_ways(num, island, way_matrix);
        mx_del_intarr(&way_matrix, num);
        mx_del_strarr(&buf);
    }
}

int main(int arg, char *c[]) {
    char **buf;

    if (arg == 1) {
        write(2, "usage: ./pathfinder [filename]\n", 
        mx_strlen("usage: ./pathfinder [filename]\n"));
        exit(1);
    }
    buf = file_to_arr(c);
    if(val_symb(buf) == 0 && val_file(c) == 0 && val_line(c))
        find_ways(buf);
    return 0;
}



