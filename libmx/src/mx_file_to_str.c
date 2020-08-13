#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
	if (!file) return NULL;
	char buff[1];
	long arr = 0;
	int open_file = open(file, O_RDONLY);
	if (open_file < 0) {
		char *seconderror = "error: file ";
		char *povit = " does not exist\n";
		write(2, seconderror, mx_strlen(seconderror));
		write(2, file, mx_strlen(file));
		write(2, povit, mx_strlen(povit));
		exit(1);
	}
	int read_file = read(open_file, buff, sizeof(buff));
	if (read_file <= 0) {
		char **tmp = mx_strsplit(file, '/');
		int count = 0; 

		while(tmp[count + 1])
			count++;
		write(2, "error: file ", mx_strlen("error: file "));
		write(2, tmp[count], mx_strlen((const char *) tmp[count]));
		write(2, " is empty", mx_strlen(" is empty"));
		write(2, "\n", 1);
		mx_del_strarr(&tmp);
		exit(1);
	}
	while (read_file > 0) {
		arr++;
		read_file = read(open_file, buff, sizeof(buff));
	}
	close(open_file);
	char *p = mx_strnew(arr);
	int i = 0;
	open_file = open(file, O_RDONLY);
	read_file = read(open_file, buff, sizeof(buff));
	while (read_file > 0) {
		p[i] = buff[0];
		read_file = read(open_file, buff, sizeof(buff));
		i++;
	}
	close(open_file);
	return p;
}







