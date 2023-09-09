/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:09:07 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/08/23 21:44:33 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

char	*ft_gnl_get_text(int fd, char *buffer)
{
	char		*temp_buffer;
	ssize_t		read_len;

	temp_buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!temp_buffer)
		return (NULL);
	read_len = 1;
	while (!ft_gnl_strchr(buffer, '\n') && read_len != 0)
	{
		read_len = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_len == -1)
		{
			free(temp_buffer);
			free(buffer);
			return (NULL);
		}
		temp_buffer[read_len] = '\0';
		buffer = ft_gnl_strjoin(buffer, temp_buffer);
	}
	free(temp_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	buffer[fd] = ft_gnl_get_text(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_gnl_strtrim_left(buffer[fd]);
	buffer[fd] = ft_gnl_strtrim_right(buffer[fd]);
	return (line);
}
