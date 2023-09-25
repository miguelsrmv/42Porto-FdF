/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 08:27:20 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/25 15:43:57 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map_data	map_data;
	t_pixel		*pixel_data;
	t_screen	screen_data;

	if (argc != 2)
		exit_error(USAGE_ERROR, NULL, NULL, NULL);
	map_data = get_map_data(argv[1]);
	pixel_data = (t_pixel *)malloc((map_data.x * map_data.y) * sizeof(t_pixel));
	if (!pixel_data)
		exit_error(MALLOC_ERROR, NULL, NULL, NULL);
	fill_pixel_data(pixel_data, &map_data, argv[1]);
	screen_data.x = malloc(sizeof(int));
	screen_data.y = malloc(sizeof(int));
	if (!(screen_data.x) || !(screen_data.y))
		exit_error(MALLOC_ERROR, pixel_data, NULL, NULL);
	start_service(pixel_data, map_data, screen_data);
	return (SUCCESS);
}
// To Do: 
//// 1. Organize Draw Functions
//// 2. Do I need Z min and Z Max ?