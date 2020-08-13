#include "../inc/pathfinder.h"

static int **cpu(int **mtrx, t_data *val) {
    int **mtrx_copy = (int **)malloc(sizeof(int *) * (val->n + 1));

    mtrx_copy[val->n] = NULL;
    for (int i = 0; i < val->n; i++) {
        mtrx_copy[i] = (int *)malloc(sizeof(int) * (val->n + 1));
        for (int j = 0; j < val->n; j++) 
            mtrx_copy[i][j] = mtrx[i][j];
        mtrx_copy[i][val->n] = -1; 
    }
    return mtrx_copy;
}

static char *dirent_entry(t_data *val, char *tmp, int ind, int **mtrx) {
    char *res = NULL;
    char *pos = NULL;

    for (int j = 0; j < val->n; j++) {
        if (mtrx[ind][j] > 0 && j == val->out) {
            pos = mx_itoa(j);
            res = mx_strjoin(tmp, pos);
            res = mx_delit_fre(res, "\n");
            mx_strdel(&pos);
        }
    }
    return res;
}

static char *alter_way(int i, char *tmp, t_data *val, int **mtrx) {
    char *pos;
    char *way;
    char *altern_way;

    pos = mx_itoa(i);
    way = mx_strjoin(tmp, pos);
    way = mx_delit_fre(way, "*");
    altern_way = find_way(way, mtrx, val, i);
    mx_strdel(&pos);
    return altern_way;
}

char *find_way(char *tmp, int **mtrx, t_data *val, int ind_in) {
    int **mtrx_copy = cpu(mtrx, val);
    char *res = dirent_entry(val, tmp, ind_in, mtrx_copy);
    char *altern_way;

    for (int i = 0; i < val->n; i++) 
        mtrx_copy[i][ind_in] = -1;
    for (int i = 0; i < val->n; i++) {
        if (mtrx_copy[ind_in][i] > 0 && i != val->out) {
            mtrx_copy[ind_in][i] = -1;
            altern_way = alter_way(i, tmp, val, mtrx_copy);
            res = mx_delit_fre(res, altern_way);
            mx_strdel(&altern_way);
        }
    }
    mx_strdel(&tmp);
    mx_del_intarr(&mtrx_copy, val->n);
    return res;
}
