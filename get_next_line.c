/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:59:18 by tmontani          #+#    #+#             */
/*   Updated: 2023/12/05 17:13:14 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_keep_rest(char *stash)
{
	int		i;
	char	*keep;

	i = 0;
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

char *ft_extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] != '\n' || stash[i] != '\0')
	{
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
	while (!ft_strrchr(stash, '\n' ) && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			free(stash);
			return ("erreur de lecture dans read");
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
	int			i;
	char		*line;

	i = 0;
	
	stash = ft_read(fd, stash);
	line = ft_extract_line(stash);
	if (!ft_strrchr(stash, '\n') && ft_strrchr(stash, '\0'))
		free(stash);
	else
		stash = ft_keep_rest(stash);

	return (line);
}

/*int	main (void)
{
	int fd;
	fd = open("fichier.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("erreur de open");
		return (0);
	}
	get_next_line(fd);
}*/