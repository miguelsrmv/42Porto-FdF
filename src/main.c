/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:27:20 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/09 12:19:19 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (USAGE_ERROR);

/*
	void	*mlx_service;
	void	*mlx_win;
	t_img	img;
	mlx_service = mlx_init();
	mlx_win = mlx_new_window(mlx_service, 800, 800, "FdF");
	img.img = mlx_new_image(mlx_service, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	my_pixel_put(&img, 5, 5, 0xFF0000);
	mlx_put_image_to_window(mlx_service, mlx_win, img.img, 0, 0);
	mlx_loop(mlx_service);
*/
	t_map_data map_data;
	t_pixel_data *pixel_data;

	map_data = parse_map(argv[1]);

	return (SUCCESS);
}
