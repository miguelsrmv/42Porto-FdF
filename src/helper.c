/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:09:45 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/10 00:04:00 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print_buffered_data(t_pixel *pixel_data, t_map_data map_data)
{
	ft_printf("\n\tx\t\ty\t\tz\t\thex\n");
    ft_printf("_________________________________________________________________\n");
	for (int i = 0; i < (map_data.x * map_data.y); i++)
		ft_printf("\t%i\t\t%i\t\t%i\t\t0x%x\n", pixel_data[i].x, pixel_data[i].y, pixel_data[i].z, pixel_data[i].color);
	ft_printf("_________________________________________________________________\n");
}
