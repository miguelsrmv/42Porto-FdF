/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:00:29 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/13 22:22:06 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pixel_data(t_pixel *pixel_data, t_map_data map_data,
			char *input_map)
{
	int		input_fd;
	char	*line;
	char	*tmp;
	char	*total_buffer;

	input_fd = open(input_map, O_RDONLY);
	if (input_fd == -1)
		exit_error(OPEN_ERROR, pixel_data, NULL, NULL);
	line = trim_line(get_next_line(input_fd));
	total_buffer = ft_strdup("");
	while (line)
	{
		tmp = total_buffer;
		total_buffer = ft_strjoin(total_buffer, line);
		free(tmp);
		free(line);
		line = trim_line(get_next_line(input_fd));
	}
	if (close(input_fd) == -1)
		exit_error(CLOSE_ERROR, pixel_data, total_buffer, NULL);
	fill_from_buffer(pixel_data, map_data, ft_split(total_buffer, ' '));
	calculate_isometric(pixel_data, map_data, ANGLE);
	free(total_buffer);
}

void	fill_from_buffer(t_pixel *pixel_data, t_map_data map_data,
			char **split_total_buffer)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (y < map_data.y)
	{
		while (x < map_data.x)
		{
			pixel_data[i].x = x;
			pixel_data[i].y = y;
			consider_hex_data(pixel_data, split_total_buffer, i);
			x++;
			i++;
		}
		x = 0;
		y++;
	}
	ft_free_tabs((void **)split_total_buffer);
}

void	consider_hex_data(t_pixel *pixel_data, char **split_total_buffer, int i)
{
	char	**tiny_buffer;
	char	*hex;

	if (!ft_strchr(split_total_buffer[i], ','))
	{
		pixel_data[i].z = ft_atoi(*split_total_buffer);
		pixel_data[i].color = 0xFFFFFF;
	}
	else
	{
		tiny_buffer = ft_split(split_total_buffer[i], ',');
		pixel_data[i].z = ft_atoi(tiny_buffer[0]);
		hex = corrected_hex(&tiny_buffer[1][2]);
		if (!hex)
		{
			ft_free_tabs((void **)tiny_buffer);
			ft_free_tabs((void **)split_total_buffer);
			exit_error(MALLOC_ERROR, pixel_data, NULL, NULL);
		}
		pixel_data[i].color = ft_atoi_base(hex, "0123456789ABCDEF");
		free(hex);
		ft_free_tabs((void **)tiny_buffer);
	}
}

char	*corrected_hex(char *number)
{
	char	*corrected_hex;
	int		i;

	corrected_hex = (char *)malloc(7 * sizeof(char));
	if (!corrected_hex)
		return (NULL);
	i = 0;
	while (i < 6)
	{
		corrected_hex[i] = '0';
		i++;
	}
	corrected_hex[6] = '\0';
	i = 0;
	while (number[i])
	{
		corrected_hex[i] = ft_toupper(number[i]);
		i++;
	}
	return (corrected_hex);
}
