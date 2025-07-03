#include "ft_ls.h"

void format_permissions(mode_t mode, char *str, int has_xattr, int has_acl) {
    // File type
    str[0] = S_ISDIR(mode) ? 'd' :
             S_ISLNK(mode) ? 'l' :
             S_ISCHR(mode) ? 'c' :
             S_ISBLK(mode) ? 'b' :
             S_ISFIFO(mode) ? 'p' :
             S_ISSOCK(mode) ? 's' : '-';
    
    // Owner permissions
    str[1] = (mode & S_IRUSR) ? 'r' : '-';
    str[2] = (mode & S_IWUSR) ? 'w' : '-';
    str[3] = (mode & S_IXUSR) ? 
             ((mode & S_ISUID) ? 's' : 'x') : 
             ((mode & S_ISUID) ? 'S' : '-');
    
    // Group permissions
    str[4] = (mode & S_IRGRP) ? 'r' : '-';
    str[5] = (mode & S_IWGRP) ? 'w' : '-';
    str[6] = (mode & S_IXGRP) ? 
             ((mode & S_ISGID) ? 's' : 'x') : 
             ((mode & S_ISGID) ? 'S' : '-');
    
    // Other permissions
    str[7] = (mode & S_IROTH) ? 'r' : '-';
    str[8] = (mode & S_IWOTH) ? 'w' : '-';
    str[9] = (mode & S_IXOTH) ? 
             ((mode & S_ISVTX) ? 't' : 'x') : 
             ((mode & S_ISVTX) ? 'T' : '-');
    
    // Extended attributes and ACL indicators
    if (has_xattr)
        str[10] = '@';
    else if (has_acl)
        str[10] = '+';
    else
        str[10] = '\0';
    
    str[11] = '\0';
}

int get_terminal_width(void) {
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == 0) {
        return w.ws_col;
    }
    return 80; // Default width
}

const char *get_color_code(mode_t mode) {
    if (S_ISDIR(mode))
        return BLUE;
    else if (S_ISLNK(mode))
        return CYAN;
    else if (S_ISCHR(mode) || S_ISBLK(mode))
        return YELLOW;
    else if (S_ISFIFO(mode))
        return MAGENTA;
    else if (S_ISSOCK(mode))
        return BRIGHT_MAGENTA;
    else if (mode & S_IXUSR)
        return GREEN;
    else if (S_ISREG(mode))
        return RESET;
    else
        return RESET;
}

void print_colored_name(const char *name, mode_t mode) {
    const char *color = get_color_code(mode);
    printf("%s%s%s", color, name, RESET);
}