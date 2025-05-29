// ft_ls.c
#include "ft_ls.h"

int main(int argc, char **argv) {
    t_options opts = {0}; // struct to hold flags like -l, -a, etc.
    char **paths = NULL;
    int path_count = 0;

    parse_args(argc, argv, &opts, &paths, &path_count);

    printf("Options:\n"
           "l: %d\n"
           "a: %d\n"
           "r: %d\n"
           "t: %d\n"
           "big_r: %d\n",
           opts.l, opts.a, opts.r, opts.t, opts.big_r);
    printf("Paths:\n");
    for (int i = 0; i < path_count; i++) {
        printf("%s\n", paths[i]);
    }


    return 0;
}
