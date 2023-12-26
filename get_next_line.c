/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:59:18 by tmontani          #+#    #+#             */
/*   Updated: 2023/12/08 19:04:04 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_keep_rest(char *stash)
{
	int		i;
	char	*keep;

	i = 0;
	if (!stash)
		return (NULL);
	keep = (char *)malloc(sizeof(char) * ft_strlen(stash) + 1);
	if (!keep)
		return (NULL);
	while (stash[i] != '\n')
	{
		i++;
	}
	i++;
	while (stash[i] != '\0')
	{
		keep[i] = stash[i];
		i++;
	}
	return (keep);
}

char *ft_extract_line(const char *stash)
{
	char	*line;
	int		i;
	int		j;


	i = 0;
	j = 0;
	while (stash[j]) 
	{
		puts("inside");
		j++;
	}
	puts("after");
	while (stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!line)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		puts("here");

		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return(line);
}

char *ft_read(int fd, char *stash)
 {
	char		*buf;
	int			bytes_read;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return(NULL);
	while (!ft_strchr(stash, '\n' ) && bytes_read != 0)
	{
		puts("dans la boucle de ft_read");
		bytes_read = read(fd, buf, BUFFER_SIZE);
		printf("bytes_read %d", bytes_read);
		if (bytes_read == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		stash = ft_strdup_or_join(stash, buf);
	}
		free(buf);
		return (stash);
 }
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	
	stash = ft_read(fd, stash);
	line = ft_extract_line(stash);
	if (!ft_strchr(stash, '\n') && ft_strchr(stash, '\0'))
		free(stash);
	else
		stash = ft_keep_rest(stash);

	return (line);
}

int	main (void)
{
	int fd;
	fd = open("fichier.txt", O_RDONLY);
	if (fd == -1)
	{
		puts("erreur de open");
		return (0);
	}
	get_next_line(fd);
}