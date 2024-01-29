/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:17:04 by tmontani          #+#    #+#             */
/*   Updated: 2024/01/29 16:43:04 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*void checkrest(char *stash)
{
    puts("rest: ");
    puts(stash);
}*/

char    *ft_keep_rest(char *stash)
{
    char    *keep;
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (stash[i] && stash[i] != '\n')
		i++;
    if (!ft_strchr(stash, '\n'))
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
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
       // printf("stash: %s\n", stash);
        i++;
        j++;
   }
   keep[j] = '\0';
   free(stash);
   return (keep);
}

char *ft_extract_line(char *stash)
{
	char	*line;
	int		i;


	i = 0;
    if (!stash[i])
        return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
        return (NULL);
    i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
    if (stash[i] && stash[i] == '\n')
	    line[i++] = '\n';
    line[i] ='\0';
	return(line);
}

char *ft_read(int fd, char *stash)
{
    char    *buf;
    int     bytes_read;
    char    *temp;

    bytes_read = 1;
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!buf)
        return (NULL);
    if (!stash)
    {

        stash = ft_strdup("");  
    }
    while (bytes_read != 0)
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free (buf);
            free (stash);
            return (NULL);
        }
        buf[bytes_read] = '\0';
        temp = stash;
        stash = ft_strjoin(temp, buf);
        free(temp);
        temp = NULL;
        if (ft_strchr(stash, '\n'))
            break;
    }
    free(buf);
    return (stash);
}

char *get_next_line(int fd)
{
    static char *stash = NULL;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
    stash = ft_read(fd, stash);
    if (!stash)
    {
        free(stash);
        return(NULL);
    }
    line = ft_extract_line(stash);
    stash = ft_keep_rest(stash);
    //checkrest(stash);
    //printf("adress stash: %p\n", stash);
    if (!line)
        return (NULL);
    return(line);
}
/*int main(void)
{
    int fd;
    int i;
    char *line;
    char path[] = "fichier.txt";

    i = 0;
    fd = open(path, O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("line %d :%s\n", i++, line);
        free(line);
    }
    close(fd);
}*/