#include "ft_ls.h"

static int compare_alpha(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

static int compare_time(const void *a, const void *b, const char *dir) {
    struct stat st1, st2;
    char path1[PATH_MAX], path2[PATH_MAX];

    snprintf(path1, PATH_MAX, "%s/%s", dir, *(char **)a);
    snprintf(path2, PATH_MAX, "%s/%s", dir, *(char **)b);

    stat(path1, &st1);
    stat(path2, &st2);

    return (int)(st2.st_mtime - st1.st_mtime);
}

void sort_entries(char **entries, int count, const char *dir, t_options opts) {
    if (opts.t) {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (compare_time(&entries[j], &entries[j + 1], dir) > 0) {
                    char *tmp = entries[j];
                    entries[j] = entries[j + 1];
                    entries[j + 1] = tmp;
                }
            }
        }
    } else {
        qsort(entries, count, sizeof(char *), compare_alpha);
    }

    if (opts.r) {
        for (int i = 0; i < count / 2; i++) {
            char *tmp = entries[i];
            entries[i] = entries[count - i - 1];
            entries[count - i - 1] = tmp;
        }
    }
}