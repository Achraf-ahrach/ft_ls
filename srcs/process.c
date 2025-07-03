#include "ft_ls.h"

static int compare_paths(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

void process_paths(char **paths, int path_count, t_options opts) {
    char **files = NULL;
    char **dirs = NULL;
    int file_count = 0;
    int dir_count = 0;
    int i;

    // Allocate arrays for files and directories
    files = malloc(sizeof(char *) * path_count);
    dirs = malloc(sizeof(char *) * path_count);
    if (!files || !dirs) {
        perror("malloc");
        exit(1);
    }

    // Separate files and directories
    for (i = 0; i < path_count; i++) {
        struct stat st;
        if (lstat(paths[i], &st) == -1) {
            perror(paths[i]);
            continue;
        }
        
        if (S_ISDIR(st.st_mode) && !opts.d) {
            dirs[dir_count++] = paths[i];
        } else {
            files[file_count++] = paths[i];
        }
    }

    // Sort files and directories
    if (file_count > 0)
        qsort(files, file_count, sizeof(char *), compare_paths);
    if (dir_count > 0)
        qsort(dirs, dir_count, sizeof(char *), compare_paths);
    
    // Display files first
    if (file_count > 0) {
        t_ls_data data;
        init_ls_data(&data, opts);
        
        for (i = 0; i < file_count; i++) {
            char *name = ft_strrchr(files[i], '/');
            name = name ? name + 1 : files[i];
            add_file(&data, name, ft_strrchr(files[i], '/') ? 
            ft_substr(files[i], 0, ft_strrchr(files[i], '/') - files[i]) : ".");
        }
        
        if (!opts.f) {
            sort_files(&data);
        }
        if (opts.one) {
            display_short(&data);
            return free_ls_data(&data);
        }
        if (opts.l || opts.g || opts.n) {
            calculate_widths(&data);
            for (i = 0; i < data.count; i++) {
                display_long(&data.files[i], &data);
            }
        } else {
            for (i = 0; i < data.count; i++) {
                if (opts.big_g) {
                    print_colored_name(data.files[i].name, data.files[i].st.st_mode);
                } else {    
                    ft_printf("%s", data.files[i].name);
                }
                if (opts.p && S_ISDIR(data.files[i].st.st_mode)) {
                    ft_printf("/");
                }
                if (i < data.count - 1 || dir_count > 0)
                ft_printf("  ");
            }
            if (file_count > 0 && dir_count > 0)
            ft_printf("\n");
        }
        
        free_ls_data(&data);
    }
    
    // Display directories
    for (i = 0; i < dir_count; i++) {
        if (file_count > 0 || i > 0)
        ft_printf("\n");
        
        int show_path = (file_count + dir_count > 1) || opts.big_r;
        list_directory(dirs[i], opts, show_path);
    }

    free(files);
    free(dirs);
}