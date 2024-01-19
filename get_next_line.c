/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:17:04 by tmontani          #+#    #+#             */
/*   Updated: 2024/01/19 15:45:21 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_keep_rest(char *stash)
{
    char    *keep;
    int     i;
    int     j;

    i = 0;
    j = 0;
     while(stash[i] != '\n')
        i++;
    while (stash[j])
        j++;
   keep = (char *)malloc(sizeof(char) * (j - i + 1));
   if (!keep)
        return (NULL);
   i++;
   j = 0;
   while(stash[i])
   {
        keep[j] = stash[i];
        i++;
        j++;
   }
   keep[j] = '\0';
   return (keep);
}
char *ft_extract_line(char *stash)
{
	char	*line;
	int		i;
	int		j;


	i = 0;
	j = 0;
	while (stash[j]) 
		j++;
	while (stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!line)
		return (NULL);
    i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\n';
    line[i + 1] ='\0';
	return(line);
}

char *ft_read(int fd, char *stash)
{
    char    *buf;
    int     bytes_read;
    char *temp;

    bytes_read = 1;
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!buf)
        return (NULL);
    if (!stash)
        stash = ft_strdup("");  
    while (!ft_strchr(stash, '\n') && bytes_read != 0)
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free (buf);
            buf = NULL;
            if (stash)
                free (stash);
            return (NULL);
        }
        buf[bytes_read] = '\0';
        puts("1");
        temp = ft_strjoin(stash, buf);
        puts("2");
        stash = temp;
        free(temp);
    }
    puts(stash);
    free(buf);
    return (stash);
}

char *get_next_line(int fd)
{
    static char *stash;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
    puts(stash);
    stash = ft_read(fd, stash);
    line = ft_extract_line(stash);
    puts("4");
     if (!ft_strchr(stash, '\n'))
    {
        free(stash);
        puts("5");
    }
    else
    {
        puts("avant keep");
        stash = ft_keep_rest(stash);
        puts("apres keep");
    }
    puts("after");
    return(line);
}

int main(void)
{
    int fd;
    char *line;
    char path[] = "fichier.txt";

    fd = open(path, O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
}
