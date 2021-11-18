#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

void get_line_files(int fd1, int fd2, int fd3)
{
    char *str;
    str = get_next_line(fd1);
    printf("%s", str);
    free(str);
    str = get_next_line(fd2);
    printf("%s", str);
    free(str);
    str = get_next_line(fd3);
    printf("%s", str);
    free(str);
}

int main (void)
{
    char *str;

    int fd1 = open("./file1", O_RDWR);
    if (fd1 < 0)
    {
        printf("\nerro na abertura do ficheiro 1");
        return (0);
    }
    int fd2 = open("./file2", O_RDWR);
    if (fd2 < 0)
    {
        printf("\nerro na abertura do ficheiro 2");
        return (0);
    }
    int fd3 = open("./file3", O_RDWR);
    if (fd3 < 0)
    {
        printf("\nerro na abertura do ficheiro 1");
        return (0);
    }
    get_line_files(fd1, fd2, fd3);
    get_line_files(fd1, fd2, fd3);
    get_line_files(fd1, fd2, fd3);
    get_line_files(fd1, fd2, fd3);
    get_line_files(fd1, fd2, fd3);
    get_line_files(fd1, fd2, fd3);
    get_line_files(fd1, fd2, fd3);
  
    close(fd1);
    close(fd2);
    close(fd3);
    return (0);
}