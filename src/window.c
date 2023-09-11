/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:16:13 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/11 17:03:47 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start_service(t_pixel *pixel_data, t_map_data map_data)
{
	void		*mlx_service;
	void		*mlx_win;
	t_img_data	img;

	mlx_service = mlx_init();
	mlx_win = mlx_new_window(mlx_service, 900, 900, "FdF");
	img.img = mlx_new_image(mlx_service, 900, 900);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_image(pixel_data, map_data, img);
	mlx_put_image_to_window(mlx_service, mlx_win, img.img, 20, 20);
	mlx_loop(mlx_service);
}

void	draw_image(t_pixel *pixel_data, t_map_data map_data, t_img_data img)
{
	int	i;
	int j;
	
	i = 0;
	j = 20;
	while (i < (map_data.x * map_data.y))
	{
		my_pixel_put(&img, (pixel_data[i].x) * j, (pixel_data[i].y) * j, pixel_data[i].color);
		i++;
	}
}
