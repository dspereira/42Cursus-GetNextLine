# 42Cursus-GetNextLine

This project is part of the 42Lisboa curriculum and aims to implement the `get_next_line` function in C. The `get_next_line` function reads one line at a time from a specified file descriptor, which is passed as a parameter and returns a pointer to the line that is dynamically allocated in heap memory.

To enhance performance, this function utilizes an internal buffer. The size of the buffer is determined during the compilation phase by passing a flag. The buffer size can significantly impact performance by reducing the number of I/O operations.

To read the entire content of a file, you can repeatedly call the `get_next_line` function until it returns a NULL pointer. As the lines are stored in heap memory using the `malloc` system call, it is good practice to free the line after it is no longer needed.

Additionally, this project provides an improved version called `get_next_line_bonus`. This version allows reading from multiple file descriptors, with a maximum limit of 1024. It enables reading lines from different file descriptors without mixing their respective line information.

By implementing the `get_next_line` and `get_next_line_bonus` functions, this project offers a reliable and efficient solution for reading lines from file descriptors in C programs.

## Installation / Usage

This simple example works on linux and MacOs. It is recommended to utilize a Makefile to facilitate the compilation process for all the files.

Clone repo inside the folder of your project:
```shell
git clone https://github.com/dspereira/42Cursus-GetNextLine.git gnl
```
Usage:
```C
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "gnl/get_next_line/get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("path_to_your_file", O_RDONLY);
    if (fd < 0)
        return (0);
    while (line = get_next_line(fd))
    {
        printf(line);
        free(line);
    }
    close(fd);
    return (0);
}
```
Build:
```shell
gcc main.c gnl/get_next_line/get_next_line.c gnl/get_next_line/get_next_line_utils.c -D BUFFER_SIZE=42 -o example
```
Run:
```shell
./example
```

## License

This project is licensed under the [MIT License](https://github.com/dspereira/42Cursus-GetNextLine/blob/main/LICENSE).

## Contact

If you have any questions or comments about this project, please feel free to contact me at diogo.s.pereira@outlook.pt.
