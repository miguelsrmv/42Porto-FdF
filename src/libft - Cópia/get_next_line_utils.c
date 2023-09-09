/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:09:00 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/23 21:52:26 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

size_t	ft_gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s && (unsigned char)c != *s)
		s++;
	if ((unsigned char)c == *s)
		return ((char *)s);
	return (0);
}

char	*ft_gnl_strjoin(char *buffer, char *temp)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * 1);
		buffer[0] = '\0';
	}
	join = malloc(sizeof(char) * (ft_gnl_strlen(buffer)
				+ ft_gnl_strlen(temp) + 1));
	if (!join)
		return (NULL);
	while (buffer[++i])
		join[i] = buffer[i];
	while (temp[++j])
		join[j + i] = temp[j];
	join[i + j] = '\0';
	free(buffer);
	return (join);
}

char	*ft_gnl_strtrim_left(char *buffer)
{
	char	*substring;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!buffer[len])
		return (NULL);
	while (buffer[len] && buffer[len] != '\n')
		len++;
	substring = malloc(sizeof(char) * len + 2);
	if (!substring)
		return (NULL);
	while (i <= len)
	{
		substring[i] = buffer[i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_gnl_strtrim_right(char *buffer)
{
	char		*next_line;
	size_t		i;
	size_t		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next_line = malloc(sizeof(char) * (ft_gnl_strlen(buffer) - i));
	if (!buffer)
		return (NULL);
	j = -1;
	while (++i < ft_gnl_strlen(buffer))
		next_line[++j] = buffer[i];
	next_line[++j] = '\0';
	free(buffer);
	return (next_line);
}
