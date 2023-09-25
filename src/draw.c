/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:37:01 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/25 14:43:45 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*target;

	target = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)target = color;
}

void	draw_pixels(t_pixel *pixel_data, t_map_data map_data, t_img_data img)
{
	int	i;

	i = 0;
	while (i < (map_data.x * map_data.y))
	{
		my_pixel_put(&img, (pixel_data[i].real_x),
			(pixel_data[i].real_y), pixel_data[i].color);
		i++;
	}
}

void	draw_lines(t_pixel *pixel_data, t_map_data map_data, t_img_data img)
{
	int	rows;
	int	i;

	rows = 0;
	while (rows < map_data.y - 1)
	{
		i = rows * map_data.x;
		while (i < ((rows * map_data.x) + map_data.x))
		{
			if (i + 1 < ((rows * map_data.x) + map_data.x))
				line_bresenhaim(pixel_data[i], pixel_data[i + 1], img);
			if (rows != map_data.real_height)
				line_bresenhaim(pixel_data[i], pixel_data[i + map_data.x], img);
			i++;
		}
		if (rows == map_data.y - 2)
		{
			while (i < ((rows * map_data.x) + map_data.x) + map_data.x - 1)
			{
				line_bresenhaim(pixel_data[i], pixel_data[i + 1], img);
				i++;
			}
		}
		rows++;
	}
}

void	draw_image(t_pixel *pixel_data, t_map_data map_data, t_img_data img)
{
	draw_pixels(pixel_data, map_data, img);
	draw_lines(pixel_data, map_data, img);
}
