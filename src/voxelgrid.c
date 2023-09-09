/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   voxelgrid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:51:29 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/09 12:14:44 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

t_map_data	parse_map(char *input_map)
{
	int			input_fd;
	t_map_data	map_data;

	input_fd = open(input_map, O_RDONLY);
	if (input_fd == -1)
		exit(OPEN_ERROR);
	map_data.x = 0;
	map_data.y = 0;
	map_data.z_min = INT_MAX;
	map_data.z_max = INT_MIN;
	read_from_file(input_fd, &map_data);
	if (close(input_fd) == -1)
		exit(CLOSE_ERROR);
	return (map_data)
}

void	read_from_file(int input_fd, t_map_data *map_data)
{
	char	*line;
	char		**tmp;

	line = get_next_line(input_fd);
	if (!line)
		exit(OPEN_ERROR);
	while (line)
	{
		tmp = ft_split(line, ' ');
		while (tmp[++(coordinates->x)])
		{
			if (coordinates->max_z < ft_atoi(tmp[coordinates->x]))
				coordinates->max_z = ft_atoi(tmp[coordinates->x]);
			if (coordinates->min_z > ft_atoi(tmp[coordinates->x]))
				coordinates->min_z = ft_atoi(tmp[coordinates->x]);
		}
		(coordinates->x)--;
		(coordinates->y)++;
		free(line);
		ft_free_tabs((void **)tmp);
		line = get_next_line(input_fd);
	}
	(coordinates->y)--;
	free(line);
}

/*
int	**create_voxel(char *input)
{
	int	input_fd;
	t_coordinates *coordinates;
	int **voxel;

	input_fd = open(input, O_RDONLY);
	if (input_fd == -1)
		return (NULL);
	coordinates = (t_coordinates *)malloc(sizeof(t_coordinates));
	if (!coordinates)
		return(NULL);
	get_size(coordinates, input_fd);
	if (close(input_fd) == -1)
		return(NULL);
	voxel = malloc_voxel(input, coordinates);
	input_fd = open(input, O_RDONLY);
	if (input_fd == -1)
		return (NULL);
	fill_in_voxel(voxel, input_fd);
	if (close(input_fd) == -1)
		return(NULL);
	return(voxel);
}



void	init_coordinates(t_coordinates *coordinates)
{
	coordinates->x = -1;
	coordinates->y = 1;
	coordinates->max_z = INT_MIN;
	coordinates->min_z = INT_MAX;
}

int	**malloc_voxel(char *input, t_coordinates *coordinates)
{
	int	**voxel;
	int	i;
	
	i = 0;
	(void)input;
	voxel = (int **)malloc((coordinates->x)*sizeof(int *));
	while (i++ < coordinates->y)
		*voxel = (int *)malloc((coordinates->y)*sizeof(int));
	return (voxel);
}
*/