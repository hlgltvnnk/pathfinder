#include "../inc/libmx.h"

void mx_del_strarr(char ***src1) {
    char **src = *src1;
    for (int i = 0; src[i]; i++) {
        free(src[i]);
        src[i] = NULL;
    }
    free(src);
    src = NULL;
}
