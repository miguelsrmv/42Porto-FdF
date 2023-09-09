/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:27:20 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/09 18:11:17 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map_dimensions map_dimensions;
	t_pixel	*pixel_data;
	
	if (argc != 2)
		return (USAGE_ERROR);
	map_dimensions = get_map_dimensions(argv[1]);
	pixel_data = (t_pixel *)malloc((map_dimensions.x * map_dimensions.y) * sizeof(t_pixel));
	if (!pixel_data)
		exit(MALLOC_ERROR);
	fill_pixel_data(pixel_data, map_dimensions, argv[1]);
	print_buffered_data(pixel_data, map_dimensions);

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
//	check_valid_map(argv[1]);
	return (SUCCESS);
}
