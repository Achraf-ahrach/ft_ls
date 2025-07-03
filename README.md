# ft_ls - A Complete `ls` Command Implementation

A comprehensive implementation of the Unix `ls` command with all mandatory features and extensive bonus functionality.

## Features

### Mandatory Options

- `-l` - Long format listing with detailed file information
- `-a` - Show all files, including hidden ones (starting with '.')
- `-r` - Reverse the order of the sort
- `-t` - Sort by modification time (most recent first)
- `-R` - Recursively list subdirectories

### Bonus Options

- `-u` - Use access time instead of modification time
- `-f` - Don't sort output
- `-g` - Like `-l` but don't show owner information
- `-d` - List directories themselves, not their contents
- `-G` - Enable colorized output
- `-1` - List one file per line
- `--color` - Long option for colorized output
- `--help` - Show usage information

### Advanced Features

- **Column formatting** - Automatic column layout based on terminal width
- **Extended attributes** - Detection and display of extended attributes (@)
- **ACL support** - Basic ACL detection and display (+)
- **Symbolic link handling** - Full symbolic link target display
- **Color coding** - Comprehensive color scheme for different file types
- **Optimized performance** - Efficient sorting and display algorithms
- **Error handling** - Robust error handling matching system `ls`

## Color Scheme

When using `-G` or `--color`, files are colored according to their type:

- **Blue** - Directories
- **Cyan** - Symbolic links
- **Green** - Executable files
- **Yellow** - Character/block devices
- **Magenta** - FIFO pipes
- **Bright Magenta** - Sockets
- **Default** - Regular files

## Building

### Prerequisites

- GCC or Clang compiler
- Make
- POSIX-compliant system (Linux, macOS, etc.)

### Compilation

```bash
# Clone the repository
git clone <repository-url>
cd ft_ls

# Build the project
make

# Run tests
make test

# Install system-wide (optional)
make install
```

### Project Structure

```
ft_ls/
├── Makefile
├── README.md
├── srcs/
│   ├── ft_ls.c         # Main function
│   ├── ft_ls.h         # Header file
│   ├── parse_args.c    # Argument parsing
│   ├── list_dir.c      # Directory listing
│   ├── display.c       # Display functions
│   ├── sort.c          # Sorting algorithms
│   ├── utils.c         # Utility functions
│   └── process.c       # Path processing
├── libft/              # Custom C library
└── ft_printf/          # Custom printf implementation
```

## Usage Examples

```bash
# Basic listing
./ft_ls

# Long format with hidden files
./ft_ls -la

# Recursive listing with colors
./ft_ls -RG

# Sort by time, newest first
./ft_ls -lt

# Sort by time, oldest first
./ft_ls -ltr

# List directories as files
./ft_ls -ld /usr /var /tmp

# Show access times
./ft_ls -lu

# No sorting (fastest for large directories)
./ft_ls -f

# Group information without owner
./ft_ls -g
```

## Technical Details

### Memory Management

- Dynamic memory allocation for file lists
- Proper cleanup of all allocated resources
- No memory leaks under normal operation

### Performance Optimizations

- Efficient sorting algorithms (quicksort for most cases)
- Minimal system calls per file
- Optimized column calculation for terminal output
- Cached user/group name lookups

### Error Handling

- Comprehensive error checking for all system calls
- Graceful handling of permission denied errors
- Proper error messages matching system `ls`
- Continue processing on individual file errors

### Standards Compliance

- POSIX-compliant system calls
- Compatible with GNU coreutils `ls` behavior
- Handles special files (devices, pipes, sockets)
- Proper handling of symbolic links

## Implementation Details

### File Information Structure

```c
typedef struct s_file {
    char *name;           // File name
    char *full_path;      // Full path to file
    struct stat st;       // File statistics
    char *link_target;    // Symbolic link target
    int has_xattr;        // Has extended attributes
    int has_acl;          // Has ACL
} t_file;
```

### Sorting Algorithm

The implementation uses quicksort for efficiency with custom comparison functions:

- Alphabetical sorting (default)
- Time-based sorting (modification or access time)
- Reverse sorting capability
- Stable sort for equal elements

### Column Layout Algorithm

For multi-column output:

1. Calculate maximum filename length
2. Determine optimal column count based on terminal width
3. Arrange files in column-major order
4. Apply proper spacing and alignment

## Testing

The project includes comprehensive tests covering:

- All mandatory options
- All bonus options
- Edge cases (empty directories, special files)
- Error conditions
- Large directory performance

Run tests with:

```bash
make test
```

## Bonus Features Implemented

### 1. Extended Attributes & ACL

- Detection of extended attributes using `listxattr()`
- Display of `@` symbol for files with extended attributes
- Foundation for ACL support (+ symbol)

### 2. Column Management

- Automatic terminal width detection
- Dynamic column calculation
- Optimal spacing for readability

### 3. Additional Options

- `-u` flag for access time sorting
- `-f` flag for unsorted output (performance)
- `-g` flag for group-only long format
- `-d` flag for directory-as-file listing

### 4. Color Support

- Comprehensive color scheme
- File type-based coloring
- Terminal capability detection

### 5. Performance Optimizations

- Efficient memory usage
- Minimal system calls
- Optimized for large directories

## Compatibility

This implementation is compatible with:

- Linux (Ubuntu, CentOS, Debian, etc.)
- macOS
- FreeBSD
- Other POSIX-compliant Unix systems

## Known Limitations

- ACL detection is basic (full ACL support requires additional libraries)
- Some advanced GNU `ls` options are not implemented
- Time zone handling may differ slightly from system `ls`

## Contributing

This project was developed as part of the 42 School curriculum. The implementation focuses on:

- Clean, readable code
- Proper error handling
- Memory management
- Performance optimization
- Standards compliance

## License

This project is part of the 42 School curriculum and is provided for educational purposes.
