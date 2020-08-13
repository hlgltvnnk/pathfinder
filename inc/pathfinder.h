#ifndef PATHFINDER_H

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "../libmx/inc/libmx.h"

typedef struct s_data {
    int n;
    int count;
    int in;
    int out;
} t_data;

int val_file(char *c[]);
int val_symb(char **bf);
bool val_count(char **p, int n);
bool val_line(char *c[]);
char **isl_arr( int n, char **arr);
int **matr_way(int n, char **arr, int count, char **island);
int *new_row(int globlen, int num);
int indexfind(int sorted[], int num, int **prev, char **arr);
void printsort(int **mas_res, int len, char **arr, char **isl);
char **line_set(char *arr);
int **matr_way(int n, char **arr, int count, char **island);
char *find_way(char *tmp, int **mtrx, t_data *val, int index_src);
void calculate_ways(int n, char **isl, int **dist);
#endif



