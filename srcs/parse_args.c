#include "ft_ls.h"

static void print_usage(void) {
    ft_printf("Usage: ft_ls [OPTION]... [FILE]...\n");
    ft_printf("List information about the FILEs (the current directory by default).\n");
    ft_printf("\nOptions:\n");
    ft_printf("  -a                     do not ignore entries starting with .\n");
    ft_printf("  -d                     list directories themselves, not their contents\n");
    ft_printf("  -f                     do not sort\n");
    ft_printf("  -g                     like -l, but do not list owner\n");
    ft_printf("  -G                     colorize the output\n");
    ft_printf("  -l                     use a long listing format\n");
    ft_printf("  -r                     reverse order while sorting\n");
    ft_printf("  -R                     list subdirectories recursively\n");
    ft_printf("  -t                     sort by modification time\n");
    ft_printf("  -u                     sort by access time\n");
    ft_printf("  -1                     list one file per line\n");
    ft_printf("  -c                     use ctime instead of mtime for sorting\n");
    ft_printf("  -n                     Display numeric user and group IDs instead of names\n");
    ft_printf("  -p                     display a slash after each directory name\n");
    ft_printf("  -h                     display this help and exit\n");
}

void parse_args(int argc, char **argv, t_options *opts, char ***paths, int *path_count) {
    int i = 1;
    int j;

    *paths = malloc(sizeof(char *) * argc);
    if (!*paths) {
        perror("malloc");
        exit(1);
    }

    while (i < argc) {
        if (argv[i][0] == '-' && argv[i][1]) {
            j = 1;
            while (argv[i][j]) {
                if (argv[i][j] == 'l') opts->l = 1;
                else if (argv[i][j] == 'n') opts->n = 1;
                else if (argv[i][j] == 'a') opts->a = 1;
                else if (argv[i][j] == 'r') opts->r = 1;
                else if (argv[i][j] == 't') opts->t = 1;
                else if (argv[i][j] == 'R') opts->big_r = 1;
                else if (argv[i][j] == 'u') opts->u = 1;
                else if (argv[i][j] == 'f') {
                    opts->f = 1;
                    opts->a = 1;
                    }
                else if (argv[i][j] == 'g') opts->g = 1;
                else if (argv[i][j] == 'd') opts->d = 1;
                else if (argv[i][j] == 'G') opts->big_g = 1;
                else if (argv[i][j] == '1') opts->one = 1;
                else if (argv[i][j] == 'c') ;
                else if (argv[i][j] == 'p') opts->p = 1;
                else if (argv[i][j] == 'h') {
                    print_usage();
                    exit(0);
                }
                else {
                    ft_printf("ft_ls: invalid option -- %c\n", argv[i][j]);
                    print_usage();
                    exit(1);
                }
                j++;
            }
        } else {
            (*paths)[*path_count] = argv[i];
            (*path_count)++;
        }
        i++;
    }

    // -f implies no sorting and no reverse
    if (opts->f) {
        opts->t = 0;
        opts->r = 0;
    }
}
