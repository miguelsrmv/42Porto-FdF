/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:37:01 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/21 21:03:03 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*target;

	target = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)target = color;
}

void	draw_vertical_line(t_img_data *img, t_map_data map_data, int x)
{
	int	j;

	j = 0;
	while (j < map_data.real_height)
	{
		my_pixel_put(img, x, j, 0xFF0000);
		j++;
	}
}

void	draw_horizontal_line(t_img_data *img, t_map_data map_data, int y)
{
	int	j;

	j = 0;
	while (j < 300 + map_data.real_width - map_data.real_width)
	{
		my_pixel_put(img, j, y, 0x00FF00);
		j++;
	}
}
