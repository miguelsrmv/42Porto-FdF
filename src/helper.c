/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:09:45 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/10 00:37:17 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_buffered_data(t_pixel *pixel_data, t_map_data map_data)
{
	int	i;

	ft_printf("\nx\t\ty\t\tz\t\thex\n");
	ft_printf("_________________________________________________________\n");
	i = 0;
	while (i < (map_data.x * map_data.y))
	{
		ft_printf("%i\t\t%i\t\t%i\t\t0x%x\n", pixel_data[i].x, pixel_data[i].y,
			pixel_data[i].z, pixel_data[i].color);
		i++;
	}
	ft_printf("_________________________________________________________\n");
}
