#include "ft_ls.h"

void display_long(const char *full_path, const char *name) {
    struct stat st;
    char perms[11];
    struct passwd *pw;
    struct group *gr;
    char time_str[20];

    if (lstat(full_path, &st) == -1) {
        perror(name);
        return;
    }

    format_permissions(st.st_mode, perms);
    pw = getpwuid(st.st_uid);
    gr = getgrgid(st.st_gid);
    strftime(time_str, sizeof(time_str), "%b %d %H:%M", localtime(&st.st_mtime));

    printf("%s %2hu %-8s %-8s %6lld %s %s\n",
           perms,
           (unsigned short)st.st_nlink,
           pw ? pw->pw_name : "unknown",
           gr ? gr->gr_name : "unknown",
           (long long)st.st_size,
           time_str,
           name);
}