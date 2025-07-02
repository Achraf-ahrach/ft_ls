#include "ft_ls.h"

void parse_args(int argc, char **argv, t_options *opts, char ***paths, int *path_count) {
    int i = 1;
    int j;

    *paths = malloc(sizeof(char *) * argc);
    if (!*paths)
        exit(1);

    while (i < argc) {
        if (argv[i][0] == '-' && argv[i][1]) {
            j = 1;
            while (argv[i][j]) {
                if (argv[i][j] == 'l') opts->l = 1;
                else if (argv[i][j] == 'a') opts->a = 1;
                else if (argv[i][j] == 'r') opts->r = 1;
                else if (argv[i][j] == 't') opts->t = 1;
                else if (argv[i][j] == 'R') opts->big_r = 1;
                else {
                    ft_printf("ft_ls: invalid option -- %c\n", argv[i][j]);
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
}
