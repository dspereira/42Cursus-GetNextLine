#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


int main (void)
{
    char *str;

    int fd = open("./test_file.txt", O_RDWR);
    if (fd < 0)
    {
        printf("\nerro na abertura do ficheiro");
        return (0);
    }
    str = get_next_line(fd);
    free(str);    
    close(fd);
    return 0;
}