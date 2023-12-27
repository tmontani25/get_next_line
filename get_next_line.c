/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:59:18 by tmontani          #+#    #+#             */
/*   Updated: 2023/12/27 17:26:19 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *stash, int fd)
{
	int	bytes_read;
	char *buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return(NULL);
	bytes_read = 0;
	while(!ft_strchr(stash, '\n') || !ft_strchr(stash, '\0'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		printf("%s", buf);
				stash = ft_strjoin(stash, buf);
	}
	return (stash);
}
char *get_next_line(int fd)
{
	char	stash[] = "hello";
	ft_read(stash, fd);
	return ("blalala");
}
int main (void)
{
	int	fd;

	fd = open("fichier.txt", O_RDONLY);
	if (!fd)
		return (1);
	else
		get_next_line(fd);
	
}