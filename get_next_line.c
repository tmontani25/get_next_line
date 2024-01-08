/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:59:18 by tmontani          #+#    #+#             */
/*   Updated: 2024/01/08 18:09:09 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(int fd, char *stash)
{
	char	*buf;
	int		bytes_read;

	bytes_read = 1;
	buf = (char *)malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if(!buf)
		return (NULL);
		puts("avant la boucle");
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		puts("dans la boucle");
		bytes_read = read(fd, buf, BUFFER_SIZE);
		printf("nombre de bytes lu: %d \n", bytes_read);
		printf("contenu de buf: %s", buf);
	}
	return ("salut");
}

char *get_next_line(int fd)
{
	char *stash;

	stash = "salut";
	ft_read(fd, stash);
	return("salut");
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