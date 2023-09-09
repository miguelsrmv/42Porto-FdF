/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:27:20 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/09 22:59:41 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map_data	map_data;
	t_pixel		*pixel_data;

	if (argc != 2)
		exit_error(USAGE_ERROR, NULL, NULL, NULL);
	map_data = get_map_data(argv[1]);
	pixel_data = (t_pixel *)malloc((map_data.x * map_data.y) * sizeof(t_pixel));
	if (!pixel_data)
		exit_error(MALLOC_ERROR, NULL, NULL, NULL);
	fill_pixel_data(pixel_data, map_data, argv[1]);
	print_buffered_data(pixel_data, map_data);

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
	free(pixel_data);
	return (SUCCESS);
}
