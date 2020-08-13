#include "../inc/pathfinder.h"

static bool bad_line(char *str, int i) {
    if(str[i] == '\n' && str[i + 1] == '\n')
        return true;
    if(!mx_isdigit(str[i]) && str[i + 1] == '\n')
        return true;
    return false;
}

static bool print_err(int line) {
    write(2, "error: line ", mx_strlen("error: line "));
    mx_printinterr(line);
    write(2, " is not valid\n", mx_strlen(" is not valid\n"));
    return false;
}

bool val_line(char *c[]) {
    char *str = mx_file_to_str(c[1]);
    int line;

    for(int i = 0; str[i]; i++) {
        if(bad_line(str, i)) {
            line = 0;
            for(int j = 0; j <= i + 1; j++) {
                if (str[j] == '\n') 
                    line++;
            }
            mx_strdel(&str);
            return print_err(line);
        }
    }
    mx_strdel(&str);
    return true;
}
