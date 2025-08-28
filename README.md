<div align="center">

  <!-- Project badge -->
  <a href=".">
    <img src="assets/README/get_next_linee.png">
  </a>

  <!-- Project name -->
  <h1>get_next_line</h1>

  <!-- Short description -->
  <p>An easier way to read from an fd in C.</p>

  <!-- Info badges -->
  <img src="https://img.shields.io/badge/Score-100%2F100-brightgreen?style=for-the-badge&labelColor=black" alt="Score">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&labelColor=black" alt="Language">
  <br>
  <img src="https://img.shields.io/github/last-commit/sdevsantiago/get_next_line?display_timestamp=committer&style=for-the-badge&labelColor=black" alt="Last commit">
  <br>
  <img src="https://github.com/sdevsantiago/get_next_line/actions/workflows/norminette.yml/badge.svg">
  <img src="https://github.com/sdevsantiago/get_next_line/actions/workflows/makefile.yml/badge.svg">

</div>

---

## ℹ️ About Project

> The purpose of this project is to code a function that allows the user to read full lines from files. This project teaches the usage of the read() function and static variables.

This library implements the `get_next_line` function. This is a C function designed to read a file descriptor line by line, returning each line as a newly allocated string. It handles files, standard input, and even pipes, making it a versatile utility for reading text data.

**Features:**
- **Reads one line at a time:** Each call returns the next line, including the newline character if present.
- **Handles multiple file descriptors (bonus):** Supports reading from several files simultaneously.
- **Efficient memory management:** Allocates only what is needed for each line and frees memory appropriately.
- **Works with any buffer size:** The buffer size can be set via the `BUFFER_SIZE` macro.

### Function Prototype

```c
char *get_next_line(int fd);
```

**Parameters:**
- `fd`: The file descriptor to read from.

**Return value:**
- A pointer to the next line read
- `NULL` if end-of-file or error.

For detailed info, refer to this project [subject](docs/en.subject.pdf).

## 🚀 Getting Started

### Prerequisites

- GCC compiler
- Make utility
- Unix-like system (Linux, macOS, WSL)

### Install prerequisites

- Debian/Ubuntu

  ```bash
  sudo apt install build-essential
  ```

## 🔧 Build

1. **Clone the repository:**
    ```bash
    git clone https://github.com/sdevsantiago/get_next_line.git
    cd Libft
    ```

2. **Compile the project:**
    ```bash
    make
    ```

3. **Clean build files:**
    ```bash
    make clean
    ```

#### Available Make Targets

| Command | Description |
|---------|-------------|
| `make` | Compiles both mandatory and bonus |
| `make all` | Same as `make` |
| `make mandatory` | Compiles mandatory part only (`get_next_line.a`) |
| `make bonus` | Compiles bonus part only (`get_next_line_bonus.a`) |
| `make clean` | Remove object files (*.o) |
| `make fclean` | Remove object files and binaries |
| `make re` | Clean and rebuild everything |

## 👨‍💻 Usage

### Basic Usage

1. **Include the header file in your C file:**
    ```c
    #include "get_next_line.c"

    // or

    #include "get_next_line_bonus.c"
    ```

2. **Compile your program with the library:**
    ```bash
    cc -Wall -Wextra -Werror your_file.c path/to/get_next_line/get_next_line.a -I path/to/get_next_line -o your_program

    # or

    cc -Wall -Wextra -Werror your_file.c path/to/get_next_line/get_next_line_bonus.a -I path/to/get_next_line -o your_program
    ```

### Example usage

**Single file descriptor:**
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int   fd;
    char  *line;

    fd = open("path/to/file", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
```

**Multiple file descritors:**
```c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int   fd[3]
    char  *line;

    fd[0] = open("path/to/file1", O_RDONLY);
    for (int i = 0; i < 5 && (line = get_next_line(fd[0])) != NULL; i++)
    {
        printf("%s", line);
        free(line);
    }

    fd[1] = open("path/to/file2", O_RDONLY);
    for (int j = 0; j < 5 && (line = get_next_line(fd[1])) != NULL; j++)
    {
        printf("%s", line);
        free(line);
    }

    fd[2] = open("path/to/file3", O_RDONLY);
    for (int k = 0; k < 5 && (line = get_next_line(fd[2])) != NULL; k++)
    {
        printf("%s", line);
        free(line);
    }

    while ((line = get_next_line(fd[0])) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd[0]);

    while ((line = get_next_line(fd[1])) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd[1]);

    while ((line = get_next_line(fd[2])) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd[2]);

    return (0);
}
```

## 📏 Norminette

The code strictly complies with 42's **Norminette v4**:

```bash
norminette *.c *.h
```

More info in the official [Norminette](https://github.com/42school/norminette) repository.

## 🙇‍♂️ Special thanks

- [lrcouto](https://github.com/lrcouto) and [ayogun](https://github.com/ayogun) for creating and publishing, respectively, the [42-project-badges](https://github.com/ayogun/42-project-badges) repository.
- [gcamerli](https://github.com/gcamerli) for creating the [42unlicense](https://github.com/gcamerli/42unlicense) repository.

## ⚖️ License

<div align="center">

<a href="./LICENSE">
<img src="https://img.shields.io/badge/License-42_Unlicense-red?style=for-the-badge&labelColor=black">
</a>

</div>

**This work is published under the terms of [42 Unlicense](LICENSE).** This means you are free to use, modify, and share this software.
