/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:17:04 by tmontani          #+#    #+#             */
/*   Updated: 2024/01/22 12:14:14 by tmontani         ###   ########.fr       */
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
    printf("DEBBUG10\n");
    while (stash[i] && stash[i] != '\n')
		i++;
    printf("DEBBUG11\n");
    if (!stash[i])
    {
        printf("DEBBUG12\n");
        return (NULL);
    }
    printf("DEBBUG13\n");
    while(stash[i] != '\n')
        i++;
    printf("DEBBUG14\n");
    while (stash[j])
        j++;
    printf("DEBBU15\n");
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


	i = 0;
    if (!stash[i])
        return (NULL);
    printf("DEBBUG01\n");
	while (stash[i] && stash[i] != '\n')
		i++;
    printf("DEBBUG02\n");
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
    {
        printf("DEBBUG03\n");
        return (NULL);
    }
    printf("DEBBUG04\n");
    i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
    printf("DEBBUG05\n");
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
    if (stash == NULL || stash[0] == '\0')
    {
        printf("strdup\n");
        stash = ft_strdup("");  
    }
    while (bytes_read != 0)
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
        
        temp = ft_strjoin(stash, buf);
        stash = temp;
        if (ft_strchr(stash, '\n'))
            break;
        free(temp);
    }
    free(buf);
    printf("stash apres read: %s\n", stash);
    return (stash);
}

char *get_next_line(int fd)
{
    static char *stash = NULL;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
    printf("avant gnl: %s\n", stash);
    stash = ft_read(fd, stash);
    line = ft_extract_line(stash);
    //if (!ft_strchr(stash, '\n'))
    //{
    //    puts("free");
    //    free(stash);
    //    stash = NULL;
    //}
    //else
    //{
    //    puts("avant keep");
    stash = ft_keep_rest(stash);
    if (!stash)
        free(stash);
    //    puts("apres keep");
    //}
    //puts("after");
    if (!line)
    {
        puts("NULL");
        return (NULL);
    }
    printf("stash: %s\n", stash);
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
