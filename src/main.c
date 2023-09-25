/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:27:20 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/25 14:57:55 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map_data	map_data;
	t_pixel		*pixel_data;
	t_window	window_data;

	if (argc != 2)
		exit_error(USAGE_ERROR, NULL, NULL, NULL);
	map_data = get_map_data(argv[1]);
	pixel_data = (t_pixel *)malloc((map_data.x * map_data.y) * sizeof(t_pixel));
	if (!pixel_data)
		exit_error(MALLOC_ERROR, NULL, NULL, NULL);
	fill_pixel_data(pixel_data, &map_data, argv[1]);
	window_data.sizex = malloc(sizeof(int));
	window_data.sizey = malloc(sizeof(int));
	if (!(window_data.sizex) || !(window_data.sizey))
		exit_error(MALLOC_ERROR, pixel_data, NULL, NULL);
	//print_buffered_data(pixel_data, map_data);
	start_service(pixel_data, map_data, window_data);
	return (SUCCESS);
}

// To Do:
// - Process Data to window??
// - Check MLX Loop for pressing X
// - Check MLX Loop for pressing ESC
// - Check Projections
// - Do I need Z Max and Z Min ?