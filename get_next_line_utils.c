/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:59:54 by tmontani          #+#    #+#             */
/*   Updated: 2023/12/08 16:25:00 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	size_t	len;
	char	*duplicate;

	len = ft_strlen(s) + 1;
	i = 0;
	duplicate = malloc(sizeof(char) * len);
	if (duplicate == NULL)
		return (NULL);
	else
		while (s[i] != '\0')
		{
			duplicate[i] = s[i];
			i++;
		}
		duplicate[i] = '\0';
	return (duplicate);
}

int	ft_strchr(const char *s, int c)
{
	
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
	}
	puts("here");
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dst = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	dst = ft_strcpy(dst, s1);
	while (dst[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

 char *ft_strdup_or_join(char *stash, char *buf)
 {
	char	*temp;

	if (!stash)
		stash = ft_strdup(buf);
	else
	{
		temp = ft_strjoin(stash, buf);
		stash = temp;
		free(temp);
	}
	return (stash);
 }