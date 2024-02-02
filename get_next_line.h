/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmontani <tmontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:18:33 by tmontani          #+#    #+#             */
/*   Updated: 2024/01/30 14:03:21 by tmontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *stash);
char	*ft_extract_line(char *stash);
char	*ft_keep_rest(char *stash);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *str);
int		ft_strchr(char *str, char c);
char	*ft_strcpy(char *dest, const char *src);
void	*ft_free(char *buf, char *stash);
#endif
