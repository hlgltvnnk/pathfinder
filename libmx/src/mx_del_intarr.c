#include "../inc/libmx.h"

void mx_del_intarr(int ***src1, int n) {
    int **src = *src1;
    for (int i = 0; i < n; i++) {
        free(src[i]);
        src[i] = NULL;
    }
    free(src);
    src = NULL;
}
