/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:51:29 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/09 22:16:44 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_data	get_map_data(char *input_map)
{
	int			input_fd;
	char		*line;
	char		*total_buffer;
	t_map_data	map_data;

	input_fd = open(input_map, O_RDONLY);
	if (input_fd == -1)
		exit_error(OPEN_ERROR, NULL, NULL, NULL);
	line = trim_line(get_next_line(input_fd));
	if (!line)
		exit_error(OPEN_ERROR, NULL, NULL, NULL);
	map_data.x = count_size(line);
	map_data.y = 0;
	total_buffer = ft_strdup("");
	create_total_buffer(line, input_fd, &map_data, &total_buffer);
	if (close(input_fd) == -1)
		exit_error(CLOSE_ERROR, NULL, total_buffer, NULL);
	free(total_buffer);
	return (map_data);
}

void	create_total_buffer(char *line, int input_fd, t_map_data *map_data,
			char **total_buffer)
{
	char		*tmp;

	while (line)
	{
		(map_data->y)++;
		if (count_size(line) != map_data->x)
			exit_error(INVALID_MAP, NULL, *total_buffer, line);
		tmp = *total_buffer;
		*total_buffer = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
		line = trim_line(get_next_line(input_fd));
	}
}

int	count_size(char *line)
{
	char	**tmp;
	int		size;

	tmp = ft_split(line, ' ');
	size = 0;
	while (tmp[size])
		size++;
	ft_free_tabs((void **)tmp);
	return (size);
}

char	*trim_line(char *line)
{
	char	*trim_line;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	trim_line = malloc(sizeof(char) * (i + 2));
	if (!trim_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		trim_line[i] = line[i];
		i++;
	}
	trim_line[i++] = ' ';
	trim_line[i++] = '\0';
	free(line);
	return (trim_line);
}
