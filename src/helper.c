/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:09:45 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/09 18:13:54 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print_buffered_data(t_pixel *pixel_data, t_map_dimensions map_dimensions)
{
	ft_printf("x\t\ty\t\tz\t\thex\n");
    ft_printf("_________________________________________________________\n");
	for (int i = 0; i < (map_dimensions.x * map_dimensions.y); i++)
	{
		ft_printf("%i\t\t%i\t\t%i\t\t0x%x\n", pixel_data[i].x, pixel_data[i].y, pixel_data[i].z, pixel_data[i].color);
	}
}