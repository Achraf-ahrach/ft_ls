#include "ft_ls.h"

static int should_display(const char *name, t_options opts) {
    return opts.a || name[0] != '.';
}

void list_directory(const char *path, t_options opts) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat st;
    char **entries = NULL;
    int count = 0;

    if (!dir) {
        perror(path);
        return;
    }

    while ((entry = readdir(dir))) {
        if (should_display(entry->d_name, opts))
            count++;
    }
    closedir(dir);

    entries = malloc(sizeof(char *) * count);
    if (!entries) return;

    dir = opendir(path);
    count = 0;
    while ((entry = readdir(dir))) {
        if (should_display(entry->d_name, opts))
            entries[count++] = ft_strdup(entry->d_name);
    }
    closedir(dir);
    
    sort_entries(entries, count, path, opts);

    for (int i = 0; i < count; i++) {
        char full_path[PATH_MAX];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entries[i]);
        if (opts.l)
            display_long(full_path, entries[i]);
        else
        {
            ft_printf("%s", entries[i]);
            if (i < count - 1)
                ft_printf("\t");
        }

        free(entries[i]);
    }
    free(entries);

    if (opts.big_r) {
        dir = opendir(path);
        while ((entry = readdir(dir))) {
            if (should_display(entry->d_name, opts)) {
                char full_path[PATH_MAX];
                snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
                if (stat(full_path, &st) == 0 && S_ISDIR(st.st_mode)
                    && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                    printf("\n%s:\n", full_path);
                    list_directory(full_path, opts);
                }
            }
        }
        closedir(dir);
    }
}