/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:16:13 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/19 19:23:35 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_service(t_pixel *pixel_data, t_map_data map_data)
{
	void		*mlx_service;
	void		*mlx_win;
	int			*sizex;
	int			*sizey;
	t_img_data	img;

	sizex = malloc(sizeof(int));
	sizey = malloc(sizeof(int));
	mlx_service = mlx_init();
	mlx_get_screen_size(mlx_service, sizex, sizey);
	mlx_win = mlx_new_window(mlx_service, ((*sizex) / 2) + (PADDING * 2) + 1,
			((*sizey) / 2) + (PADDING * 2), "FdF");
	img.img = mlx_new_image(mlx_service, ((*sizex) / 2),
			((*sizey) / 2) + 1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	calculate_projection(pixel_data, &map_data, ANGLE);
	scale_projection(pixel_data, &map_data, pixel_distance(map_data, sizex, sizey));
	draw_pixels(pixel_data, map_data, img);
	draw_lines(pixel_data, map_data, img);
	mlx_put_image_to_window(mlx_service, mlx_win, img.img,
		PADDING, PADDING);
	mlx_loop(mlx_service);
}

int	pixel_distance(t_map_data map_data, int *sizex, int *sizey)
{
	int	distance;

	if (map_data.real_width > map_data.real_height)
		distance = ((*sizex) / 2) / map_data.real_width;
	else
		distance = ((*sizey) / 2) / map_data.real_height;
	free(sizex);
	free(sizey);
	return(distance);
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
