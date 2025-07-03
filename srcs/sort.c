#include "ft_ls.h"

static int compare_name(const void *a, const void *b) {
    t_file *fa = (t_file *)a;
    t_file *fb = (t_file *)b;
    return strcoll(fa->name, fb->name);
}

static int compare_time(const void *a, const void *b) {
    t_file *fa = (t_file *)a;
    t_file *fb = (t_file *)b;
    
    time_t time_a = fa->st.st_mtime;
    time_t time_b = fb->st.st_mtime;
    
    if (time_a == time_b)
        return strcoll(fa->name, fb->name);
    
    return (time_b > time_a) ? 1 : -1;
}

static int compare_access_time(const void *a, const void *b) {
    t_file *fa = (t_file *)a;
    t_file *fb = (t_file *)b;
    
    time_t time_a = fa->st.st_atime;
    time_t time_b = fb->st.st_atime;
    
    if (time_a == time_b)
        return strcoll(fa->name, fb->name);
    
    return (time_b > time_a) ? 1 : -1;
}

static void reverse_array(t_file *files, int count) {
    for (int i = 0; i < count / 2; i++) {
        t_file tmp = files[i];
        files[i] = files[count - i - 1];
        files[count - i - 1] = tmp;
    }
}

void sort_files(t_ls_data *data) {
    if (data->count <= 1 || data->opts.f)
    return;
    
    if (data->opts.t) {
        if (data->opts.u) {
            qsort(data->files, data->count, sizeof(t_file), compare_access_time);
        } else {
            qsort(data->files, data->count, sizeof(t_file), compare_time);
        }
    } else {
        qsort(data->files, data->count, sizeof(t_file), compare_name);
    }
    
    if (data->opts.r) {
        reverse_array(data->files, data->count);
    }
}