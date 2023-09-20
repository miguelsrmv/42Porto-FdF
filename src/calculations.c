/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:21:56 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/20 19:26:43 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_projection(t_pixel *pixel_data, t_map_data *map_data,
			double angle)
{
	int	i;

	i = 0;
	angle = degree_to_rad(angle);
	while (i < map_data->x * map_data->y)
	{
		pixel_data[i].calc_x = ((pixel_data[i].x - pixel_data[i].y) * cos(angle));
		pixel_data[i].calc_y = ((pixel_data[i].x + pixel_data[i].y) * sin(angle)
			- pixel_data[i].z);
		i++;
	}
	adjust_map_real_width(pixel_data, map_data);
	adjust_map_real_height(pixel_data, map_data);
}

void	resize_projection(t_pixel *pixel_data, t_map_data *map_data, int distance)
{
	int i;

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
	print_buffered_data(pixel_data, *map_data);
}

void	center_projection(t_pixel *pixel_data, t_map_data map_data,
			int *sizex, int *sizey)
{
	int	i;
	int	add_x;
	int add_y;

	add_x = ((((*sizex) / 2) - map_data.real_width) / 2) - map_data.final_min_x;
	add_y = ((((*sizey) / 2) - map_data.real_height) / 2) - map_data.final_min_y;
	i = 0;
	while (i < map_data.x * map_data.y)
	{
		pixel_data[i].real_x += add_x;
		pixel_data[i].real_y += add_y;
		i++;
	}
	print_buffered_data(pixel_data, map_data);
}

void	adjust_map_real_width(t_pixel *pixel_data, t_map_data *map_data)
{
	int	i;
	double	min_x;
	double	max_x;

	i = 0;
	min_x = INT_MAX;
	max_x = INT_MIN;
	while (i < map_data->x * map_data->y)
	{
		if (pixel_data[i].calc_x < min_x)
			min_x = pixel_data[i].calc_x;
		if (pixel_data[i].calc_x > max_x)
			max_x = pixel_data[i].calc_x;
		i++;
	}
	map_data->real_width = (max_x - min_x);
	if (min_x < 0)
	{
		i = 0;
		while (i < map_data->x * map_data->y)
		{
			pixel_data[i].calc_x += ((min_x - 1) * -1);
			i++;
		}
	}
}

void	adjust_map_real_height(t_pixel *pixel_data, t_map_data *map_data)
{
	int	i;
	double	min_y;
	double	max_y;

	i = 0;
	min_y = INT_MAX;
	max_y = INT_MIN;
	while (i < map_data->x * map_data->y)
	{
		if (pixel_data[i].calc_y < min_y)
			min_y = pixel_data[i].calc_y;
		if (pixel_data[i].calc_y > max_y)
			max_y = pixel_data[i].calc_y;
		i++;
	}
	map_data->real_height = (max_y - min_y);
	if (min_y < 0)
	{
		i = 0;
		while (i < map_data->x * map_data->y)
		{
			pixel_data[i].calc_y += (min_y * -1);
			i++;
		}
	}
}

double	degree_to_rad(double angle)
{
	return ((M_PI * angle / 180.0));
}
