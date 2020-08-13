#include "../inc/pathfinder.h"

static bool bad_chars(char **bf){
    for (int i = 1; bf[i]; i++) {
        for (int j = 0; bf[i][j]; j++) {
            if (mx_count_words(bf[i], '-') > 2 || mx_count_words(bf[i], ',') > 2 || 
            ((bf[i][j] == '-' || bf[i][j] == ',') && bf[i][j] == bf[i][j + 1])) {
                write(2, "error: line ", mx_strlen("error: line "));
                mx_printinterr(i + 1);
                write(2, " is not valid\n", mx_strlen(" is not valid\n"));
                return false; 
            }
        }
    }
    return true; 
}

static bool bad_arg(char **bf){ //знаки после - ,
    for (int i = 1; bf[i]; i++) {
        for (int j = 0; bf[i][j]; j++) {
            if ((bf[i][j] == '-' && !mx_isalpha(bf[i][j + 1])) || 
            (bf[i][j] == ',' && !mx_isdigit(bf[i][j + 1]))) {
                write(2, "error: line ", mx_strlen("error: line "));
                mx_printinterr(i + 1);
                write(2, " is not valid\n", mx_strlen(" is not valid\n"));
                return false; 
            }
        }
    }
    return true; 
}

static bool bad_num(char **bf){ //знаки после буквы
    int flag;

    for (int i = 1; bf[i]; i++) {
        for (int j = 0; bf[i][j]; j++) {
            flag = 0;
            if(bf[i][j + 1] == '-' || bf[i][j + 1] == ',') 
                flag = 1;
            if (mx_isalpha(bf[i][j]) && flag != 1 && !mx_isalpha(bf[i][j + 1])) {
                write(2, "error: line ", mx_strlen("error: line "));
                mx_printinterr(i + 1);
                write(2, " is not valid\n", mx_strlen(" is not valid\n"));
                return false; 
            }
        }
    }
    return true; 
}

int val_symb(char **bf) {
    for(int i = 0; bf[0][i]; i++) {
        if (bf[0][i] < 48 || bf[0][i] > 57) {
            write(2, "error: line 1 is not valid\n", 
            mx_strlen("error: line 1 is not valid\n"));
            return 1;
        }
    }
    if (!bad_chars(bf) || !bad_arg(bf) || !bad_num(bf)) {
    return 1; 
    }
    return 0;
}
