#include "ft_ls.h"

void process_paths(char **paths, int path_count, t_options opts) {
    for (int i = 0; i < path_count; i++) {
        if (path_count > 1)
            printf("%s:\n", paths[i]);
        list_directory(paths[i], opts);
        if (i < path_count - 1)
            printf("\n");
    }
}