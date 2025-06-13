#include "ft_ls.h"

int main(int argc, char **argv) {
    t_options opts = {0};
    char **paths = NULL;
    int path_count = 0;

    parse_args(argc, argv, &opts, &paths, &path_count);

    if (path_count == 0) {
        char *default_path[] = { "." };
        process_paths(default_path, 1, opts);
    } else {
        process_paths(paths, path_count, opts);
    }

    if (paths) free(paths);
    return 0;
}
