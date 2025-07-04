#include "ft_ls.h"

int should_display(const char *name, t_options opts) {
    if (opts.a)
        return 1;
    return name[0] != '.';
}

void init_ls_data(t_ls_data *data, t_options opts) {
    data->files = NULL;
    data->count = 0;
    data->capacity = 0;
    data->opts = opts;
    data->term_width = get_terminal_width();
    data->max_links = 0;
    data->max_user = 0;
    data->max_group = 0;
    data->max_size = 0;
    data->total_blocks = 0;
}

void add_file(t_ls_data *data, const char *name, const char *dir_path) {
    if (data->count >= data->capacity) {
        data->capacity = data->capacity ? data->capacity * 2 : 10;
        data->files = realloc(data->files, sizeof(t_file) * data->capacity);
        if (!data->files) {
            perror("realloc");
            exit(1);
        }
    }

    t_file *file = &data->files[data->count];
    file->name = ft_strdup(name);
    
    if (dir_path && strcmp(dir_path, ".") != 0) {
        file->full_path = malloc(ft_strlen(dir_path) + ft_strlen(name) + 2);
        sprintf(file->full_path, "%s/%s", dir_path, name);
    } else {
        file->full_path = ft_strdup(name);
    }

    if (lstat(file->full_path, &file->st) == -1) {
        perror(file->name);
        free(file->name);
        free(file->full_path);
        return;
    }

    file->link_target = NULL;
    if (S_ISLNK(file->st.st_mode)) {
        file->link_target = malloc(PATH_MAX);
        ssize_t len = readlink(file->full_path, file->link_target, PATH_MAX - 1);
        if (len != -1) {
            file->link_target[len] = '\0';
        } else {
            free(file->link_target);
            file->link_target = NULL;
        }
    }

    handle_xattr_acl(file->full_path, file);
    data->total_blocks += file->st.st_blocks;
    data->count++;
}

void handle_xattr_acl(const char *path, t_file *file) {
    file->has_xattr = 0;
    file->has_acl = 0;

    // Check for extended attributes
    // ssize_t size = llistxattr(path, NULL, 0); // This is the Linux-specific function
    ssize_t size = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
    if (size > 0) {
        file->has_xattr = 1;
    }

    // Note: ACL checking would require additional libraries
    // For this implementation, we'll skip ACL detection
}

void free_ls_data(t_ls_data *data) {
    for (int i = 0; i < data->count; i++) {
        free(data->files[i].name);
        free(data->files[i].full_path);
        if (data->files[i].link_target)
            free(data->files[i].link_target);
    }
    if (data->files)
        free(data->files);
}

void list_directory(const char *path, t_options opts, int show_path) {
    DIR *dir;
    struct dirent *entry;
    t_ls_data data;

    dir = opendir(path);
    if (!dir) {
        perror(path);
        return;
    }

    if (show_path) {
        ft_printf("%s:\n", path);
    }

    init_ls_data(&data, opts);

    while ((entry = readdir(dir))) {
        if (should_display(entry->d_name, opts)) {
            add_file(&data, entry->d_name, path);
        }
    }
    closedir(dir);

    if (!opts.f) {
        sort_files(&data);
    }

    if (opts.l || opts.g || opts.n) {
        calculate_widths(&data);
        print_total_blocks(data.total_blocks);
        for (int i = 0; i < data.count; i++) {
            display_long(&data.files[i], &data);
        }
    } else if (opts.one || isatty(STDOUT_FILENO) == 0) {
        display_short(&data);
    }
    else {
        display_columns(&data);
    }

    // Handle recursive option
    if (opts.big_r) {
        for (int i = 0; i < data.count; i++) {
            if (S_ISDIR(data.files[i].st.st_mode) && 
                strcmp(data.files[i].name, ".") != 0 && 
                strcmp(data.files[i].name, "..") != 0) {
                ft_printf("\n");
                list_directory(data.files[i].full_path, opts, 1);
            }
        }
    }

    free_ls_data(&data);
}