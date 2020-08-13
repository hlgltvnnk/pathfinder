#include "../inc/pathfinder.h"

int err_msg(char *str, char *err) {
    char **tmp = mx_strsplit(str, '/');
    int count = 0; 

    while(tmp[count + 1])
        count++;
    write(2, "error: file ", mx_strlen("error: file "));
    write(2, tmp[count], mx_strlen((const char *) tmp[count]));
    write(2, err, mx_strlen(err));
    write(2, "\n", 1);
    mx_del_strarr(&tmp);
    return 1;
}

int val_file(char *c[]) {
    char buff[1];
    int read_file;
    int open_file = open((const char *) c[1], O_RDONLY);

    if (open_file < 0)
        return err_msg(c[1], " does not exist");
    read_file = read(open_file, buff, sizeof(buff));
	if (read_file <= 0)
        return err_msg(c[1], " is empty");
    close(open_file);
    return 0;
}

