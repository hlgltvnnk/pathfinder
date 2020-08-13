#include "../inc/libmx.h"

void mx_bubble_sort_int(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        for (int h = 0; h < size - 1; h++) {
            if (arr[h] > arr[h+1]) {
                    int c = arr[h];
                    arr[h] = arr[h+1];
                    arr[h+1] = c;
                }
            else continue;
        }
    }
}
