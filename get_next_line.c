/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:59:18 by tmontani          #+#    #+#             */
/*   Updated: 2023/12/04 20:17:18 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *stash;
    char    *buf;
    int     bytes_read; 
    int     i;

    i = 0;
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    bytes_read = read(fd, buf, 5);
    if(bytes_read == -1)
        return ("erreur de lecture dans read");
     buf[bytes_read] = '\0';
    printf("contenu de buf: %s", buf);
    while(buf[i] != '\0')
    {
        stash[i] = buf[i];
        i++;
    }
    stash[i] = '\0';
    printf(" contenu de stash: %s", stash);
    return ("salut");
}

int main (void)
{
    int fd;
    fd = open("fichier.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("erreur de open");
        return (0);
    }
    get_next_line(fd);
}