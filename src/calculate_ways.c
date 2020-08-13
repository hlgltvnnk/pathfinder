#include "../inc/pathfinder.h"

static int **calc_dist(int arrlen, char **bufbuf, int **dist) {
    int **res = (int **)malloc(sizeof(int *) * (arrlen + 1));
    char **tmp;
    int row_len = 0;

    res[arrlen] = NULL;
    for (int i = 0; i < arrlen ; i++) {
        tmp = mx_strsplit(bufbuf[i], '*');
        row_len = 0;
        for (int j = 0; tmp[j + 1] != NULL; j++, row_len++);
        res[i] = new_row(row_len, 0);
        for (int j = 0; j < row_len; j++)
            res[i][j] = dist[mx_atoi(tmp[j])][mx_atoi(tmp[j + 1])];
        mx_del_strarr(&tmp);
    }
    return res;
}

static void way_matrix(int p, int **dist, t_data *D, char **isl) {
    char *tmp, *avail_ways;
    char **splited;
    int **len_mtrx;
    int len = 0;

    tmp = mx_delit_fre(mx_itoa(p), "*");
    avail_ways = find_way(tmp, dist, D, p);
    splited = mx_strsplit(avail_ways, '\n');
    for (int i = 0; splited[i] != NULL; i++, len++);
    len_mtrx = calc_dist(len, splited, dist);
    printsort(len_mtrx, len, splited, isl);
    mx_del_intarr(&len_mtrx, len + 1);
    mx_strdel(&avail_ways);
    mx_del_strarr(&splited);
}

void calculate_ways(int n, char **isl, int **dist) {
    t_data *D = (t_data *) malloc(sizeof(t_data) * 4);

    for (int p = 0; p < n - 1; p++) {
        for (int l = p + 1; l < n; l++) {
            D->out = l;
            D->n = n;
            way_matrix(p, dist, D, isl);
        }
    }
    mx_del_strarr(&isl);
    free(D);
    D = NULL;
}
// Олюньчик дуй спать

