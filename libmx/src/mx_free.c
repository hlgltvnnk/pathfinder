#include "../inc/libmx.h"

void mx_free(char *p) {
    free(p);
    p = NULL;
}
