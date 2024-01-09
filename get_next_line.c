/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:17:04 by tmontani          #+#    #+#             */
/*   Updated: 2024/01/09 15:11:05 by tmontani         ###   ########.fr       */
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
   {
        free(keep);
        return (NULL);
   }
   i++;
   while(stash[i])
   {
        keep[i] = stash[i];
        i++;
   }
   keep[i] = '\0';
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
	line[i] = '\0';
	return(line);
}

char *ft_read(int fd, char *stash)
{
    char    *buf;
    int     bytes_read;

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
            free (stash);
            return (NULL);
        }
        stash = ft_strjoin(stash, buf);
    }
    free(buf);
    return (stash);
}

char *get_next_line(int fd)
{
    static char *stash;
    //char *line;//
    //char *keep;//

    stash = ft_read(fd, stash);
    //line = ft_extract_line(stash);//
    //keep = ft_keep_rest(stash);//
    return(stash);
}

int main (void)
{
    char *line;
    int fd;
    fd = open("fichier.txt", O_RDONLY);
    if (fd == -1)
    {
        puts("erreur de open");
        return (0);
    }
    line = get_next_line(fd);
    //free(line);//
    printf("line: %s", line);
    line = get_next_line(fd);
    //free (line);//
    return (0);
}
