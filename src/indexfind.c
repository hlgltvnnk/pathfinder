#include "../inc/pathfinder.h"

static int comp(int a, int b, char **arr){ //kakoy bolshe
    int res = 0;
    char **one = mx_strsplit(arr[a], '*');
    char **two = mx_strsplit(arr[b], '*');

    for (int i = 0; one[i] && two[i]; i++) {
        if (mx_strcmp(one[i], two[i]) > 0) {
            res = 1;
            break;
        }
        if (mx_strcmp(one[i], two[i]) < 0) {
            res = 2;
            break;
        }
    }
    mx_del_strarr(&one);
    mx_del_strarr(&two);
    return res;
}

static int indsort(int *new, char **arr) {
    int res = 0;
    int tmp;

    for(int i = 0; new[i] != -1; i++) {
        for(int j = 0; new[j] != -1; j++) {
            if (new[i] != -2 && new[j] != -2 && i != j) {
                tmp = comp(new[i], new[j], arr);
                if (tmp == 1)
                    new[i] = -2;
                if (tmp == 2)
                    new[j] = -2; 
            }
        }
    }
    for (int k = 0; new[k] != -1; k++) {
        if( new[k] != -2) {
            res = new[k];
            break;
        }
    }
    return res;
}

static int *create_range(int count, int num, int *mark, int *sorted) {
    int loc = 0; 
    int *range = new_row(count, -2);

    for (int i = 0; sorted[i] != -1; i++) {
        if (sorted[i] == num && mark[i] == 0) {
            range[loc] = i;
            loc++;
        }   
    }
    return range;
}

int indexfind(int sorted[], int num, int **prev, char **arr) {
    int *mark = *prev;
    int count = 0;
    int *range;
    int index;

    for( int i = 0; sorted[i] != -1; i++) {
        if(sorted[i] == num) 
            count++;
    }
    range = create_range(count, num, mark, sorted);
    index = indsort(range, arr);
    mark[index] = -2;
    free(range);
    range = NULL;
    return index;
}


