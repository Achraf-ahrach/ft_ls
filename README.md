# ft_ls

A custom implementation of the Unix `ls` command written in C. This project recreates the functionality of the standard `ls` utility with support for various options and formatting modes.

## 🚀 Features

### Core Functionality

- **Directory listing** : List files and directories with various formatting options
- **File information** : Display detailed file metadata including permissions, ownership, size, and timestamps
- **Sorting** : Multiple sorting options (name, time, access time)
- **Filtering** : Show/hide hidden files and directories
- **Recursive listing** : Traverse directory structures recursively

### Supported Options

| Option | Description                                          |
| ------ | ---------------------------------------------------- |
| `-a` | Show hidden files (starting with `.`)              |
| `-d` | List directories themselves, not their contents      |
| `-f` | Don't sort entries                                   |
| `-g` | Like `-l`, but don't show owner                    |
| `-G` | Colorize output                                      |
| `-l` | Use long listing format                              |
| `-n` | Show numeric user and group IDs                      |
| `-p` | Add `/`after directory names                       |
| `-r` | Reverse sort order                                   |
| `-R` | List subdirectories recursively                      |
| `-t` | Sort by `modification time` (mtime)                |
| `-u` | Sort by `access time` (atime)                      |
| `-1` | List one file per line                               |
| `-c` | Use ctime for sorting `Last status change` (ctime) |
| `-h` | Display help                                         |

### Display Modes

#### Short Format (Default)

```
file1.txt  file2.txt  directory/
```

#### Long Format (`-l`)

```
-rw-r--r-- 1 user group 1024 Dec 25 10:30 file1.txt
drwxr-xr-x 2 user group 4096 Dec 25 10:25 directory
```

#### Columnar Format

Automatically adjusts to terminal width for optimal display.

#### Colored Output (`-G`)

- **Blue** : Directories
- **Cyan** : Symbolic links
- **Green** : Executable files
- **Yellow** : Character/block devices
- **Magenta** : Named pipes
- **Default** : Regular files

## 🛠️ Installation

### Prerequisites

- GCC compiler
- Make
- Unix-like system (Linux, macOS, etc.)

### Building

```bash
# Clone the repository
git clone https://github.com/yourusername/ft_ls.git
cd ft_ls

# Build the project
make

# Clean build files
make clean

# Full clean (removes executable)
make fclean

# Rebuild
make re
```

## 📖 Usage

### Basic Usage

```bash
# List current directory
./ft_ls

# List specific directory
./ft_ls /path/to/directory

# List multiple paths
./ft_ls file1.txt directory1/ directory2/
```

### Common Examples

```bash
# Long format with hidden files
./ft_ls -la

# Recursive listing with colors
./ft_ls -RG

# Sort by modification time (newest first)
./ft_ls -lt

# Reverse alphabetical order
./ft_ls -r

# Show only directories
./ft_ls -d */

# Numeric user/group IDs
./ft_ls -ln
```

## 🏗️ Architecture

### Project Structure

```
ft_ls/
├── Makefile
├── README.md
├── ft_printf/          # Custom printf implementation
├── libft/              # Custom C library
├── pdfs/               # Project documentation
└── srcs/               # Source code
    ├── display.c       # Output formatting functions
    ├── ft_ls.c         # Main program entry
    ├── ft_ls.h         # Header file with structures and prototypes
    ├── list_dir.c      # Directory listing logic
    ├── parse_args.c    # Command-line argument parsing
    ├── process.c       # File processing functions
    ├── sort.c          # Sorting algorithms
    └── utils.c         # Utility functions
```

### Key Data Structures

#### `t_options`

Stores command-line options and flags.

#### `t_file`

Represents a single file entry with metadata:

- Name and full path
- `stat` structure information
- Symbolic link target
- Extended attributes and ACL flags

#### `t_ls_data`

Main data container for file listings:

- Array of files
- Display options
- Terminal width
- Column width calculations

### Core Functions

- **`parse_args()`** : Command-line argument processing
- **`list_directory()`** : Directory traversal and file collection
- **`sort_files()`** : File sorting with multiple criteria
- **`display_long()`** : Long format output
- **`display_columns()`** : Columnar format output
- **`format_permissions()`** : Permission string formatting

## 🔧 Technical Details

### Memory Management

- Dynamic memory allocation for file arrays
- Proper cleanup of allocated resources
- Error handling for allocation failures

### Platform Compatibility

- Uses POSIX-compliant system calls
- Handles different filesystem types
- Terminal width detection for optimal display

### Performance Considerations

- Efficient sorting algorithms
- Minimal system calls per file
- Optimized string operations

## 🧪 Testing

### Test Cases

```bash
# Test basic functionality
./ft_ls
./ft_ls -l
./ft_ls -la

# Test with different paths
./ft_ls /usr/bin
./ft_ls /etc /var /tmp

# Test sorting options
./ft_ls -t
./ft_ls -rt
./ft_ls -u

# Test recursive listing
./ft_ls -R /small/directory
```

### Comparison with System `ls`

```bash
# Compare outputs
ls -la > system_output.txt
./ft_ls -la > ft_ls_output.txt
diff system_output.txt ft_ls_output.txt
```

## 📊 Features Comparison

| Feature                  | ft_ls | System ls |
| ------------------------ | ----- | --------- |
| Basic listing            | ✅    | ✅        |
| Long format              | ✅    | ✅        |
| Hidden files             | ✅    | ✅        |
| Sorting options          | ✅    | ✅        |
| Recursive listing        | ✅    | ✅        |
| Colored output           | ✅    | ✅        |
| Numeric IDs              | ✅    | ✅        |
| Extended attributes      | ✅    | ✅        |
| Terminal width detection | ✅    | ✅        |

## 🚧 Known Limitations

- ACL detection not fully implemented
- Some advanced `ls` options not supported
- Color scheme is simplified compared to GNU ls

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📝 License

This project is part of the 42 School curriculum and is intended for educational purposes.

## 🙏 Acknowledgments

- 42 School for the project specifications
- The GNU coreutils team for the original `ls` implementation reference
- POSIX standards for system call specifications

## 📞 Contact

- Email: achrafahrach44@example.com

---

_This project demonstrates proficiency in C programming, system calls, file system operations, and Unix command-line utilities._
