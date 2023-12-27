/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:59:54 by tmontani          #+#    #+#             */
/*   Updated: 2023/12/27 17:31:15 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return(0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return(i);
}



