#include "ft_ls.h"

void calculate_widths(t_ls_data *data) {
    struct passwd *pw;
    struct group *gr;

    for (int i = 0; i < data->count; i++) {
        t_file *file = &data->files[i];

        // Calculate max link count width
        int links = file->st.st_nlink;
        int link_width = 0;
        while (links > 0) {
            link_width++;
            links /= 10;
        }
        if (link_width > data->max_links)
            data->max_links = link_width;

        // Calculate max user width
        if (!data->opts.g) {
            pw = getpwuid(file->st.st_uid);
            int user_width = pw ? ft_strlen(pw->pw_name) : 8;
            if (user_width > data->max_user)
                data->max_user = user_width;
        }

        // Calculate max group width
        gr = getgrgid(file->st.st_gid);
        int group_width = gr ? ft_strlen(gr->gr_name) : 8;
        if (group_width > data->max_group)
            data->max_group = group_width;

        // Calculate max size width
        long long size = file->st.st_size;
        int size_width = 1;
        while (size >= 10) {
            size_width++;
            size /= 10;
        }
        if (size_width > data->max_size)
            data->max_size = size_width;
    }
}

char *format_time(time_t mtime) {
    static char time_str[20];
    time_t now = time(NULL);
    time_t six_months = 6 * 30 * 24 * 60 * 60;

    if (now - mtime > six_months || mtime > now) {
        // For old files, show: "Mon DD  YYYY" (note the two spaces before year)
        strftime(time_str, sizeof(time_str), "%b %e  %Y", localtime(&mtime));
    } else {
        // For recent files, show: "Mon DD HH:MM"
        strftime(time_str, sizeof(time_str), "%b %e %H:%M", localtime(&mtime));
    }

    return time_str;
}

void display_long(t_file *file, t_ls_data *data) {
    char perms[12];
    struct passwd *pw = NULL;
    struct group *gr;
    char *time_str;
    time_t display_time;

    format_permissions(file->st.st_mode, perms, file->has_xattr, file->has_acl);

    if (!data->opts.g) {
        pw = getpwuid(file->st.st_uid);
    }
    gr = getgrgid(file->st.st_gid);

    // Choose the correct time based on options
    if (data->opts.c) {
        display_time = file->st.st_ctime;  // Use change time
    } else if (data->opts.u) {
        display_time = file->st.st_atime;  // Use access time
    } else {
        display_time = file->st.st_mtime;  // Use modification time (default)
    }

    time_str = format_time(display_time);

    if (data->opts.g) {
        // -g option: like -l but no owner
        printf("%s %*hu %-*s %*lld %s ",
               perms,
               data->max_links, (unsigned short)file->st.st_nlink,
               data->max_group, gr ? gr->gr_name : "unknown",
               data->max_size, (long long)file->st.st_size,
               time_str);
    } else if (data->opts.n) {
        // -n option: numeric user and group IDs
        printf("%s %*hu %*d %*d %*lld %s ",
               perms,
               data->max_links, (unsigned short)file->st.st_nlink,
               data->max_user, file->st.st_uid,
               data->max_group, file->st.st_gid,
               data->max_size, (long long)file->st.st_size,
               time_str);
    }
    else {
        printf("%s %*hu %-*s %-*s %*lld %s ",
               perms,
               data->max_links, (unsigned short)file->st.st_nlink,
               data->max_user, pw ? pw->pw_name : "unknown",
               data->max_group, gr ? gr->gr_name : "unknown",
               data->max_size, (long long)file->st.st_size,
               time_str);
    }

    // Print filename with color if -G is specified
    if (data->opts.big_g) {
        print_colored_name(file->name, file->st.st_mode);
    } else {
        printf("%s", file->name);
    }

    if (file->link_target) {
        printf(" -> %s", file->link_target);
    }
    if (data->opts.p && S_ISDIR(file->st.st_mode)) {
        printf("/");
    }
    printf("\n");
}

void display_short(t_ls_data *data) {
    for (int i = 0; i < data->count; i++) {
        if (data->opts.big_g) {
            print_colored_name(data->files[i].name, data->files[i].st.st_mode);
        }
        else {
            printf("%s", data->files[i].name);
        }
        if (data->opts.p && S_ISDIR(data->files[i].st.st_mode)) {
            printf("/");
        }
        printf("\n");
    }
}

void display_columns(t_ls_data *data) {
    if (data->count == 0)
        return;

    int max_len = 0;
    for (int i = 0; i < data->count; i++) {
        int len = ft_strlen(data->files[i].name);
        if (len > max_len)
            max_len = len;
    }

    int cols = data->term_width / (max_len + 2);
    if (cols <= 0) cols = 1;

    int rows = (data->count + cols - 1) / cols;

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int idx = row + col * rows;
            if (idx >= data->count)
                break;

            if (data->opts.big_g) {
                print_colored_name(data->files[idx].name, data->files[idx].st.st_mode);
            } else {
                printf("%s", data->files[idx].name);
            }
            if (data->opts.p && S_ISDIR(data->files[idx].st.st_mode)) {
                printf("/");
            }

            if (col < cols - 1 && idx + rows < data->count) {
                int padding = max_len + 2 - ft_strlen(data->files[idx].name);
                for (int p = 0; p < padding; p++)
                    printf(" ");
            }
        }
        printf("\n");
    }
}

void print_total_blocks(long long total_blocks) {
    printf("total %lld\n", total_blocks);
}