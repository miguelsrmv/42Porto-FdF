/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_resize_center.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:06:14 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/20 20:23:04 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_scale(t_map_data map_data, int *sizex, int *sizey)
{
	int	width_scale_limit;
	int	height_scale_limit;

	width_scale_limit = ((*sizex) / 2) / (map_data.real_width + 1);
	height_scale_limit = ((*sizey) / 2) / (map_data.real_height + 1);
	if (width_scale_limit > height_scale_limit)
		return (height_scale_limit);
	else
		return (width_scale_limit);
}

void	resize_projection(t_pixel *pixel_data, t_map_data *map_data,
			int distance)
{
	int	i;

	i = 0;
	map_data->final_max_x = INT_MIN;
	map_data->final_max_y = INT_MIN;
	map_data->final_min_x = INT_MAX;
	map_data->final_min_y = INT_MAX;
	while (i < map_data->x * map_data->y)
	{
		pixel_data[i].real_x = pixel_data[i].calc_x * distance;
		pixel_data[i].real_y = pixel_data[i].calc_y * distance;
		if (pixel_data[i].real_x < map_data->final_min_x)
			map_data->final_min_x = pixel_data[i].real_x;
		if (pixel_data[i].real_y < map_data->final_min_y)
			map_data->final_min_y = pixel_data[i].real_y;
		if (pixel_data[i].real_x > map_data->final_max_x)
			map_data->final_max_x = pixel_data[i].real_x;
		if (pixel_data[i].real_y > map_data->final_max_y)
			map_data->final_max_y = pixel_data[i].real_y;
		i++;
	}
	map_data->real_width = (map_data->final_max_x - map_data->final_min_x);
	map_data->real_height = (map_data->final_max_y - map_data->final_min_y);
}

void	center_projection(t_pixel *pixel_data, t_map_data map_data,
			int *sizex, int *sizey)
{
	int	i;
	int	add_x;
	int	add_y;

	add_x = ((((*sizex) / 2) - map_data.real_width) / 2)
		- map_data.final_min_x;
	add_y = ((((*sizey) / 2) - map_data.real_height) / 2)
		- map_data.final_min_y;
	i = 0;
	while (i < map_data.x * map_data.y)
	{
		pixel_data[i].real_x += add_x;
		pixel_data[i].real_y += add_y;
		i++;
	}
}
