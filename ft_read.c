#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main (void)
{
    int fd;
    int bytes_read;
    unsigned char buf[100];

    fd = open("fichier.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("erreur open");
        return (0);
    }

    bytes_read = read(fd, buf, 5);
    printf("%d", bytes_read);
    printf("%s", buf);
    return (0);
}