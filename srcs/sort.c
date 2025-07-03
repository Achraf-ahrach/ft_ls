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
    
    if (time_a != time_b) {
        return (time_b > time_a) ? 1 : -1;
    }
    
    // If times are equal, compare nanoseconds if available
    #ifdef __APPLE__
    // macOS has nanosecond precision in st_mtimespec
    if (fa->st.st_mtimespec.tv_nsec != fb->st.st_mtimespec.tv_nsec) {
        return (fb->st.st_mtimespec.tv_nsec > fa->st.st_mtimespec.tv_nsec) ? 1 : -1;
    }
    #elif defined(__linux__)
    // Linux has nanosecond precision in st_mtim
    if (fa->st.st_mtim.tv_nsec != fb->st.st_mtim.tv_nsec) {
        return (fb->st.st_mtim.tv_nsec > fa->st.st_mtim.tv_nsec) ? 1 : -1;
    }
    #endif
    
    // If times are exactly equal, sort by name
    return strcoll(fa->name, fb->name);
}

static int compare_access_time(const void *a, const void *b) {
    t_file *fa = (t_file *)a;
    t_file *fb = (t_file *)b;
    
    time_t time_a = fa->st.st_atime;
    time_t time_b = fb->st.st_atime;
    
    if (time_a != time_b) {
        return (time_b > time_a) ? 1 : -1;
    }
    
    // If times are equal, compare nanoseconds if available
    #ifdef __APPLE__
    if (fa->st.st_atimespec.tv_nsec != fb->st.st_atimespec.tv_nsec) {
        return (fb->st.st_atimespec.tv_nsec > fa->st.st_atimespec.tv_nsec) ? 1 : -1;
    }
    #elif defined(__linux__)
    if (fa->st.st_atim.tv_nsec != fb->st.st_atim.tv_nsec) {
        return (fb->st.st_atim.tv_nsec > fa->st.st_atim.tv_nsec) ? 1 : -1;
    }
    #endif
    
    return strcoll(fa->name, fb->name);
}

static void reverse_array(t_file *files, int count) {
    for (int i = 0; i < count / 2; i++) {
        t_file tmp = files[i];
        files[i] = files[count - i - 1];
        files[count - i - 1] = tmp;
    }
}

// sort.c - Add comparison function for ctime and update sort_files
static int compare_change_time(const void *a, const void *b) {
    t_file *fa = (t_file *)a;
    t_file *fb = (t_file *)b;
    
    time_t time_a = fa->st.st_ctime;
    time_t time_b = fb->st.st_ctime;
    
    if (time_a != time_b) {
        return (time_b > time_a) ? 1 : -1;
    }
    
    // If times are equal, compare nanoseconds if available
    #ifdef __APPLE__
    if (fa->st.st_ctimespec.tv_nsec != fb->st.st_ctimespec.tv_nsec) {
        return (fb->st.st_ctimespec.tv_nsec > fa->st.st_ctimespec.tv_nsec) ? 1 : -1;
    }
    #elif defined(__linux__)
    if (fa->st.st_ctim.tv_nsec != fb->st.st_ctim.tv_nsec) {
        return (fb->st.st_ctim.tv_nsec > fa->st.st_ctim.tv_nsec) ? 1 : -1;
    }
    #endif
    
    return strcoll(fa->name, fb->name);
}

void sort_files(t_ls_data *data) {
    if (data->count <= 1 || data->opts.f)
    return;
    
    if (data->opts.t) {
        if (data->opts.c) {
            qsort(data->files, data->count, sizeof(t_file), compare_change_time);
        } else if (data->opts.u) {
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