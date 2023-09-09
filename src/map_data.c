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
	map_data.x = count_size(line);
	map_data.y = 0;
	total_buffer = NULL;
	while (line)
	{
		(map_data.y)++;
		if (count_size(line) != map_data.x)
			exit(5);
		total_buffer = ft_strjoin(total_buffer, line);
		free(line);
		line = trim_line(get_next_line(input_fd));
	}
	if (close(input_fd) == -1)
		exit_error(CLOSE_ERROR, NULL, total_buffer, NULL);
	get_min_and_max(&map_data, total_buffer);
	return (map_data);
}

int	count_size(char *line)
{
	char	**tmp;
	int		size;

	tmp = ft_split(line, ' ');
	size = 0;
	while (tmp[size])
		size++;
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

void	get_min_and_max(t_map_data *map_data, char *total_buffer)
{
	int		i;
	char	**small_buffer;
	char	**tiny_buffer;

	i = 0;
	map_data->z_min = INT_MAX;
	map_data->z_max = INT_MIN;
	small_buffer = ft_split(total_buffer, ' ');
	while (small_buffer[i])
	{
		tiny_buffer = ft_split((char const *)small_buffer[i], ',');
		if (map_data->z_max < ft_atoi(*tiny_buffer))
			map_data->z_max = ft_atoi(*tiny_buffer);
		if (map_data->z_min > ft_atoi(*tiny_buffer))
			map_data->z_min = ft_atoi(*tiny_buffer);
		i++;
		ft_free_tabs((void **)tiny_buffer);
	}
	ft_free_tabs((void **)small_buffer);
	free(total_buffer);
}
