/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:16:13 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/16 15:43:23 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_service(t_pixel *pixel_data, t_map_data map_data)
{
	void		*mlx_service;
	void		*mlx_win;
	t_img_data	img;

	mlx_service = mlx_init();
	mlx_win = mlx_new_window(mlx_service, map_data.real_width + 1 + (PADDING * 2),
			map_data.real_height + 1 + (PADDING * 2), "FdF");
	img.img = mlx_new_image(mlx_service, map_data.real_width + 1, map_data.real_height + 1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);

	draw_pixels(pixel_data, map_data, img);
//	draw_lines(pixel_data, map_data, img);
	mlx_put_image_to_window(mlx_service, mlx_win, img.img,
		PADDING, PADDING);
	pseudo_draw_lines(pixel_data, map_data, mlx_service, mlx_win);
	mlx_loop(mlx_service);
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

	rows = 0;
	while (rows < map_data.y - 1)
	{
		draw_line_for_row(pixel_data, map_data, img, rows);
		rows++;
	}
}

void	draw_line_for_row(t_pixel *pixel_data, t_map_data map_data, t_img_data img, int row)
{
	int	i;

	i = row * map_data.x;
	while (i < ((row * map_data.x) + map_data.x))
	{
		line_bresenhaim(pixel_data[i], pixel_data[i + 1], img);
		if (row != map_data.real_height)
			line_bresenhaim(pixel_data[i], pixel_data[i + map_data.x], img);
		i++;
	}
}

void	line_bresenhaim(t_pixel pixel_from, t_pixel pixel_to, t_img_data img)
{
	int	current_x;
	int	current_y;
	int	delta_x;
	int	delta_y;
	int	decision;

	current_x = pixel_from.real_x + PADDING;
	current_y = pixel_from.real_y + PADDING;
	delta_x = pixel_to.real_x - pixel_from.real_x;
	delta_y = pixel_to.real_y - pixel_from.real_y;
	decision = 2 * delta_y - delta_x;
	my_pixel_put(&img, current_x, current_y, pixel_from.color);
	while (current_x != pixel_to.real_x)
	{
		if (decision > 0)
		{
			current_y++;
			decision = decision + 2 * (delta_y - delta_x);
		}
		else
			decision = decision + 2 * delta_y;
		if (current_x < pixel_to.real_x)
			current_x++;
		else
			current_x--;
		my_pixel_put(&img, current_x, current_y, pixel_from.color);
	}
}

void	pseudo_draw_lines(t_pixel *pixel_data, t_map_data map_data, void *mlx_service, void *mlx_win)
{
	int	rows;

	rows = 0;
	while (rows < map_data.y - 1)
	{
		pseudo_draw_line_for_row(pixel_data, map_data, mlx_service, mlx_win, rows);
		rows++;
	}
}

void	pseudo_draw_line_for_row(t_pixel *pixel_data, t_map_data map_data, void *mlx_service, void *mlx_win, int row)
{
	int	i;

	i = row * map_data.x;
	while (i < ((row * map_data.x) + map_data.x))
	{
		pseudo_line_bresenhaim(pixel_data[i], pixel_data[i + 1], mlx_service, mlx_win);
		if (row != map_data.real_height)
			pseudo_line_bresenhaim(pixel_data[i], pixel_data[i + map_data.x], mlx_service, mlx_win);
		i++;
	}
}

void	pseudo_line_bresenhaim(t_pixel pixel_from, t_pixel pixel_to, void *mlx_service, void *mlx_win)
{
	int	current_x;
	int	current_y;
	int	delta_x;
	int	delta_y;
	int	decision;

	current_x = pixel_from.real_x;
	current_y = pixel_from.real_y;
	delta_x = pixel_to.real_x - pixel_from.real_x;
	delta_y = pixel_to.real_y - pixel_from.real_y;
	decision = 2 * delta_y - delta_x;
	mlx_pixel_put(mlx_service, mlx_win, current_x + PADDING, current_y + PADDING, pixel_from.color);
	while (current_x != pixel_to.real_x)
	{
		if (decision > 0)
		{
			current_y++;
			decision = decision + 2 * (delta_y - delta_x);
		}
		else
			decision = decision + 2 * delta_y;
		if (current_x < pixel_to.real_x)
			current_x++;
		else
			current_x--;
		mlx_pixel_put(mlx_service, mlx_win, current_x + PADDING, current_y + PADDING, pixel_from.color);
	}
}
