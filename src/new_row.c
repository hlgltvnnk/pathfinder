#include "../inc/pathfinder.h"

int *new_row(int globlen, int num) {
    int *res = (int *)malloc(sizeof(int) * (globlen + 1));
    for (int i = 0; i < globlen; i++) 
        res[i] = num;
    res[globlen] = -1;
    return res;
}
