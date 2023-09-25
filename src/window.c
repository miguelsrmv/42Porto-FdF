/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:16:13 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/25 16:10:19 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_service(t_pixel *pixel_data, t_map_data map_data,
			t_screen screen_data)
{
	void		*mlx_service;
	void		*mlx_win;
	t_img_data	img;

	mlx_service = mlx_init();
	mlx_get_screen_size(mlx_service, screen_data.x, screen_data.y);
	mlx_win = mlx_new_window(mlx_service, (*(screen_data.x) / 2)
			+ (PADDING * 2), (*(screen_data.y) / 2) + (PADDING * 2), "FdF");
	img.img = mlx_new_image(mlx_service, (*(screen_data.x) / 2) + 1,
			(*(screen_data.y) / 2) + 1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	process_and_draw_image(pixel_data, &map_data, &screen_data, &img);
	mlx_put_image_to_window(mlx_service, mlx_win, img.img,
		PADDING, PADDING);
	mlx_key_hook(mlx_win, cross_pressed, mlx_service);
	mlx_loop(mlx_service);
	clean_data(pixel_data, screen_data);
	clean_mlx(img.img, mlx_win, mlx_service);
}
