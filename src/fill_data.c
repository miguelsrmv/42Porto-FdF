/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:00:29 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/09 20:37:19 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pixel_data (t_pixel *pixel_data, t_map_dimensions map_dimensions, char *input_map)
{
	int		input_fd;
	char	*line;
	char	*total_buffer;
	char	**split_total_buffer;

	input_fd = open(input_map, O_RDONLY);
	if (input_fd == -1)
		exit(OPEN_ERROR);
	line = trim_line(get_next_line(input_fd));
	total_buffer = "";
	while (line)
	{
		total_buffer = ft_strjoin(total_buffer, line);
		free(line);
		line = trim_line(get_next_line(input_fd));
	}
	if (close(input_fd) == -1)
		exit(CLOSE_ERROR);
	split_total_buffer = ft_split(total_buffer, ' ');
	fill_from_buffer(pixel_data, map_dimensions, split_total_buffer);
	ft_free_tabs((void **)split_total_buffer);
	free(total_buffer);
}

void	fill_from_buffer(t_pixel *pixel_data, t_map_dimensions map_dimensions, char **split_total_buffer)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (y < map_dimensions.y)
	{
		while(x < map_dimensions.x)
		{
			pixel_data[i].x = x;
			pixel_data[i].y = y;
			consider_hex_data(pixel_data, split_total_buffer[i], i);
			x++;
			i++;	
		}
		x = 0;
		y++;	
	}
}

void	consider_hex_data(t_pixel *pixel_data, char *split_total_buffer, int i)
{
	char **tiny_buffer;
	char	*hex;

	if (!ft_strchr(split_total_buffer, ','))
	{
		pixel_data[i].z = ft_atoi(split_total_buffer);
		pixel_data[i].color = 0xFFFFFF;
	}
	else
	{
		tiny_buffer = ft_split(split_total_buffer, ',');
		pixel_data[i].z = ft_atoi(tiny_buffer[0]);
		hex = corrected_hex(&tiny_buffer[1][2]);
		pixel_data[i].color = ft_atoi_base(hex, "0123456789ABCDEF");
		free(hex);
		ft_free_tabs((void **)tiny_buffer);
	}
}

char	*corrected_hex(char *number)
{
	char *corrected_hex;
	int	i;

	corrected_hex = (char *)malloc(7 * sizeof(char));
	i = 0;
	while (i < 7)
	{
		corrected_hex[i] = '0';
		i++;
	}
	corrected_hex[7] = '\0';
	i = 0;
	while (number[i])
	{
		corrected_hex[i] = ft_toupper(number[i]);
		i++;
	}
	return(corrected_hex);
}
