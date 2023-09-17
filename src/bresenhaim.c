/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhaim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:14:56 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/17 21:51:00 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_line_point(t_img_data img, t_bresenhaim b, int color)
{
	if (b.steep)
		my_pixel_put(&img, (b.current_y), (b.current_x), color);
	else
		my_pixel_put(&img, (b.current_x), (b.current_y), color);
}

void	init_bresenham(t_bresenhaim *b, t_pixel *pixel_from, t_pixel *pixel_to)
{
	b->steep = ft_abs(pixel_to->real_y - pixel_from->real_y)
		> ft_abs(pixel_to->real_x - pixel_from->real_x);
	if (b->steep)
	{
		ft_int_swap(&pixel_from->real_x, &pixel_from->real_y);
		ft_int_swap(&pixel_to->real_x, &pixel_to->real_y);
		ft_int_swap(&pixel_to->color, &pixel_to->color);
	}
	if (pixel_from->real_x > pixel_to->real_x)
	{
		ft_int_swap(&pixel_from->real_x, &pixel_to->real_x);
		ft_int_swap(&pixel_from->real_y, &pixel_to->real_y);
		ft_int_swap(&pixel_from->color, &pixel_to->color);
	}
	b->current_x = pixel_from->real_x;
	b->current_y = pixel_from->real_y;
	b->delta_x = pixel_to->real_x - pixel_from->real_x;
	b->delta_y = ft_abs(pixel_to->real_y - pixel_from->real_y);
	b->decision = b->delta_x / 2;
}

void	update_coordinates(t_bresenhaim *b, t_pixel pixel_from,
			t_pixel pixel_to)
{
	b->decision -= b->delta_y;
	if (b->decision < 0)
	{
		if (pixel_to.real_y > pixel_from.real_y)
			b->current_y += 1;
		else
			b->current_y -= 1;
		b->decision += b->delta_x;
	}
	b->current_x++;
}

void	line_bresenhaim(t_pixel pixel_from, t_pixel pixel_to, t_img_data img)
{
	t_bresenhaim	b;
	int				color_gradient;
	int				i;

	init_bresenham(&b, &pixel_from, &pixel_to);
	color_gradient = (pixel_to.color - pixel_from.color)
		/ (sqrt(pow(pixel_to.real_x - pixel_from.real_x, 2)
				+ pow(pixel_to.real_y - pixel_from.real_y, 2)));
	i = 1;
	while (b.current_x < pixel_to.real_x)
	{
		update_coordinates(&b, pixel_from, pixel_to);
		plot_line_point(img, b, pixel_from.color + color_gradient * i);
		i++;
	}
}
