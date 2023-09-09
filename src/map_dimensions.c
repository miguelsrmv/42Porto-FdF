/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dimensions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:51:29 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/09 20:10:31 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map_dimensions	get_map_dimensions(char *input_map)
{
	int					input_fd;
	char				*line;
	char				*total_buffer;
	t_map_dimensions	map_dimensions;

	input_fd = open(input_map, O_RDONLY);
	if (input_fd == -1)
		exit(OPEN_ERROR);
	line = trim_line(get_next_line(input_fd));
	map_dimensions.x = count_size(line);
	map_dimensions.y = 0;
	total_buffer = "";
	while (line)
	{
		(map_dimensions.y)++;
		if (count_size(line) != map_dimensions.x)
			exit(5);
		total_buffer = ft_strjoin(total_buffer, line);
		free(line);
		line = trim_line(get_next_line(input_fd));
	}
	if (close(input_fd) == -1)
		exit(CLOSE_ERROR);
	get_min_and_max(&map_dimensions, total_buffer);
	return (map_dimensions);
}

int	count_size(char *line)
{
	char **tmp;
	int	size;
	
	tmp = ft_split(line, ' ');
	size = 0;
	while (tmp[size])
		size++;
	return (size);
}

void	get_min_and_max(t_map_dimensions *map_dimensions, char *total_buffer)
{
	int		i;
	char	**small_buffer;
	char	**tiny_buffer;

	i = 0;
	map_dimensions->z_min = INT_MAX;
	map_dimensions->z_max = INT_MIN;
	small_buffer = ft_split(total_buffer, ' ');
	while (small_buffer[i])
	{
		tiny_buffer = ft_split((char const *)small_buffer[i], ',');
		if (map_dimensions->z_max < ft_atoi(*tiny_buffer))
			map_dimensions->z_max = ft_atoi(*tiny_buffer);
		if (map_dimensions->z_min > ft_atoi(*tiny_buffer))
			map_dimensions->z_min = ft_atoi(*tiny_buffer);
		i++;
		ft_free_tabs((void **)tiny_buffer);
	}
	ft_free_tabs((void **)small_buffer);
}

char *trim_line(char *line)
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
