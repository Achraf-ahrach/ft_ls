// includes/ft_ls.h
#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <string.h>
# include <stdio.h>     // for debugging, can be removed later
# include <errno.h>

// Option flags (-l, -a, -r, -t, -R)
typedef struct s_options {
    int l;
    int a;
    int r;
    int t;
    int big_r;
} t_options;

// Main function declarations
void parse_args(int argc, char **argv, t_options *opts, char ***paths, int *path_count);
void process_paths(char **paths, int path_count, t_options opts);

#endif

