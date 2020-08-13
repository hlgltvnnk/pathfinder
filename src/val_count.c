#include "../inc/pathfinder.h"


static int count(char **p) {
    int count = 0; 

    for(int i = 1; p[i]; i++) {
        for(int j = 0; p[i][j]; j++) {
            if(mx_isalpha(p[i][j]))
                count++;
            else if(!mx_isdigit(p[i][j + 1]))
                count++;
        }
    if(p[i + 1])
        count++;
    }
    return count;
}

static char **make_list(char **p) {
    char *new = mx_strnew(count(p));
    int pos = 0;
    char **res;

    for (int i = 1; p[i]; i++) {
        for (int j = 0; p[i][j]; j++) {
            if (mx_isalpha(p[i][j]))
                new[pos++] = p[i][j];
            if (!mx_isalpha(p[i][j]) && !mx_isdigit(p[i][j + 1])) 
                new[pos++] = ',';
        }
    }
    res = mx_strsplit(new, ',');
    mx_strdel(&new);
    return res;
}

static int inentif(char **p) {
    int count = 0;
    int flag;

    for (int i = 0; p[i]; i++) {
        flag = 0;
        for (int j = 0; j < i; j++) {
            if (mx_strcmp(p[i], p[j]) == 0) 
                flag++;
        }
        if (flag == 0) count++;
    }
    return count;
}

bool val_count(char **p, int n) {
    char **isl = make_list(p);
    int count = inentif(isl);

    mx_del_strarr(&isl);
    if(n == count) 
        return true;
    write(2, "error: invalid number of islands\n", 
        mx_strlen("error: invalid number of islands\n")); 
    return false;
}


