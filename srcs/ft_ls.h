#ifndef FT_LS_H
#define FT_LS_H

#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <fcntl.h>
#include <termios.h>
#include <locale.h>
#include <sys/xattr.h>
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BRIGHT_BLACK   "\033[90m"
#define BRIGHT_RED     "\033[91m"
#define BRIGHT_GREEN   "\033[92m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_BLUE    "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN    "\033[96m"
#define BRIGHT_WHITE   "\033[97m"

typedef struct s_options {
    int l;      // long format
    int a;      // show hidden files
    int r;      // reverse sort
    int t;      // sort by time
    int big_r;  // recursive
    int u;      // use access time
    int f;      // don't sort
    int g;      // like -l but no owner
    int d;      // list directories as files
    int big_g;  // enable colorization
    int one;    // one file per line
} t_options;

typedef struct s_file {
    char *name;
    char *full_path;
    struct stat st;
    char *link_target;
    int has_xattr;
    int has_acl;
} t_file;

typedef struct s_ls_data {
    t_file *files;
    int count;
    int capacity;
    t_options opts;
    int term_width;
    int max_links;
    int max_user;
    int max_group;
    int max_size;
    long long total_blocks;
} t_ls_data;

// Function prototypes
void parse_args(int argc, char **argv, t_options *opts, char ***paths, int *path_count);
void display_long(t_file *file, t_ls_data *data);
void display_short(t_ls_data *data);
void display_columns(t_ls_data *data);
void sort_files(t_ls_data *data);
void format_permissions(mode_t mode, char *str, int has_xattr, int has_acl);
void list_directory(const char *path, t_options opts, int show_path);
void process_paths(char **paths, int path_count, t_options opts);
void add_file(t_ls_data *data, const char *name, const char *dir_path);
void free_ls_data(t_ls_data *data);
void init_ls_data(t_ls_data *data, t_options opts);
int get_terminal_width(void);
const char *get_color_code(mode_t mode);
void print_colored_name(const char *name, mode_t mode);
void calculate_widths(t_ls_data *data);
char *format_time(time_t mtime);
int should_display(const char *name, t_options opts);
void print_total_blocks(long long total_blocks);
void handle_xattr_acl(const char *path, t_file *file);

#endif