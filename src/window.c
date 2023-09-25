/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:16:13 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/25 14:58:21 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_service(t_pixel *pixel_data, t_map_data map_data, t_window window_data)
{
	void		*mlx_service;
	void		*mlx_win;
	t_img_data	img;

	mlx_service = mlx_init();
	mlx_get_screen_size(mlx_service, window_data.sizex, window_data.sizey);
	mlx_win = mlx_new_window(mlx_service, (*(window_data.sizex) / 2) + (PADDING * 2),
			(*(window_data.sizey) / 2) + (PADDING * 2), "FdF");
	calculate_projection(pixel_data, &map_data, ANGLE);
	resize_projection(pixel_data, &map_data, get_scale(map_data, window_data.sizex, window_data.sizey));
	center_projection(pixel_data, map_data, window_data.sizex, window_data.sizey);
	img.img = mlx_new_image(mlx_service, (*(window_data.sizex) / 2) + 1,
			(*(window_data.sizey) / 2) + 1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_image(pixel_data, map_data, img);
	mlx_put_image_to_window(mlx_service, mlx_win, img.img,
		PADDING, PADDING);
	mlx_key_hook(mlx_win, cross_pressed, mlx_service);
	mlx_loop(mlx_service);
	clean_exit(pixel_data, window_data, mlx_win, mlx_service);
}
