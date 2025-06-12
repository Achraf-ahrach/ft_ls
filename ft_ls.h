#ifndef FT_LS_H
#define FT_LS_H

#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>

typedef struct s_options {
    int l;
    int a;
    int r;
    int t;
    int big_r;
} t_options;

void parse_args(int argc, char **argv, t_options *opts, char ***paths, int *path_count);
void display_long(const char *full_path, const char *name);
void sort_entries(char **entries, int count, const char *dir, t_options opts);
void format_permissions(mode_t mode, char *str);
void list_directory(const char *path, t_options opts);
void process_paths(char **paths, int path_count, t_options opts);

#endif