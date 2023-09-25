/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:00:29 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/25 16:56:51 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pixel_data(t_pixel *pixel_data, t_map_data *map_data,
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
	fill_from_buffer(pixel_data, *map_data, ft_split(total_buffer, ' '));
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

	if (!ft_strchr(split_total_buffer[i], ','))
	{
		pixel_data[i].z = ft_atoi(split_total_buffer[i]);
		pixel_data[i].rgb.red = 0xFF;
		pixel_data[i].rgb.green = 0xFF;
		pixel_data[i].rgb.blue = 0xFF;
	}
	else
	{
		tiny_buffer = ft_split(split_total_buffer[i], ',');
		pixel_data[i].z = ft_atoi(tiny_buffer[0]);
		get_color(&tiny_buffer[1][2], &pixel_data[i]);
		ft_free_tabs((void **)tiny_buffer);
	}
	pixel_data[i].color = (pixel_data[i].rgb.red << 16
			| pixel_data[i].rgb.green << 8
			| pixel_data[i].rgb.blue);
}

void	get_color(char *hex, t_pixel *pixel_data)
{
	char	*lower_case_hex;
	int		hex_color;

	lower_case_hex = ft_str_tolower(hex);
	hex_color = ft_atoi_base(lower_case_hex, "0123456789abcdef");
	free(lower_case_hex);
	pixel_data->rgb.red = (hex_color >> 16) & 0xFF;
	pixel_data->rgb.green = (hex_color >> 8) & 0xFF;
	pixel_data->rgb.blue = (hex_color) & 0xFF;
}
