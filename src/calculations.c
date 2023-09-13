/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:21:56 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/13 22:24:32 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_isometric(t_pixel *pixel_data, t_map_data map_data, int angle)
{
	int	i;

	i = 0;
	angle = degree_to_rad(angle);
	while (i < map_data.x * map_data.y)
	{
		pixel_data[i].real_x = (pixel_data[i].x) * cos(angle)
			+ (pixel_data[i].y) * cos(angle + 120)
			+ (pixel_data[i].z) * cos(angle - 120);
		pixel_data[i].real_y = (pixel_data[i].x) * sin(angle)
			+ (pixel_data[i].y) * sin(angle + 120)
			+ (pixel_data[i].z) * sin(angle - 120);
		i++;
	}
}

int			degree_to_rad(int angle)
{
	return ((M_PI * angle / 180.0));
}
