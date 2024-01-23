/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:18:02 by tmontani          #+#    #+#             */
/*   Updated: 2024/01/23 14:48:48 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t  ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return (i);
}

int ft_strchr(char *str, char c)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while(str[i])
    {
        if(str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

char    *ft_strdup(char *s)
{
    char *duplicate;
    int i;

    i = 0;
    duplicate = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
    if(!duplicate)
        return(NULL);
    while(s[i] != '\0')
    {
        duplicate[i] = s[i];
        i++;
    }
    duplicate[i] = '\0';
    return (duplicate);
}

char    *ft_strjoin(char *s1, char *s2)
{
	char	*dst;
    int     i;
    int     j;

    j = 0;
    i = 0;
	dst = (char *)malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (s1[i])
    {
        dst[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        dst[i + j] = s2[j];
        j++;
    }
    dst[i + j] = '\0';
	return (dst);

}


/*int main (void)
{
    char *str;

    str = ft_strjoin("salut", "cava");
    //printf("copie: %s", str);
    free(str);
}*/
