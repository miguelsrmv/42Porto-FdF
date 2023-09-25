/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhaim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:14:56 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/25 19:07:48 by mde-sa--         ###   ########.fr       */
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
		ft_swap(&pixel_from->real_x, &pixel_from->real_y, sizeof(int));
		ft_swap(&pixel_to->real_x, &pixel_to->real_y, sizeof(int));
	}
	if (pixel_from->real_x > pixel_to->real_x)
	{
		ft_swap(&pixel_from->real_x, &pixel_to->real_x, sizeof(int));
		ft_swap(&pixel_from->real_y, &pixel_to->real_y, sizeof(int));
		ft_swap(&pixel_from->color, &pixel_to->color, sizeof(int));
		ft_swap(&pixel_from->rgb, &pixel_to->rgb, sizeof(t_rgb));
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

int	interpolate_color(t_pixel pixel_from, t_pixel pixel_to,
			float interpolation_param)
{
	int		interpolated_color;
	t_rgb	interpolated_rgb;

	interpolated_rgb.red = (int)(pixel_from.rgb.red + interpolation_param
			* (pixel_to.rgb.red - pixel_from.rgb.red));
	interpolated_rgb.green = (int)(pixel_from.rgb.green + interpolation_param
			* (pixel_to.rgb.green - pixel_from.rgb.green));
	interpolated_rgb.blue = (int)(pixel_from.rgb.blue + interpolation_param
			* (pixel_to.rgb.blue - pixel_from.rgb.blue));
	interpolated_color = (interpolated_rgb.red << 16)
		+ (interpolated_rgb.green << 8) + interpolated_rgb.blue;
	return (interpolated_color);
}

void	line_bresenhaim(t_pixel pixel_from, t_pixel pixel_to, t_img_data img)
{
	t_bresenhaim	b;
	float			distance;
	float			interpolation_param;
	int				interpolated_color;
	int				i;

	init_bresenham(&b, &pixel_from, &pixel_to);
	distance = sqrt(pow(pixel_to.real_x - pixel_from.real_x, 2)
			+ pow(pixel_to.real_y - pixel_from.real_y, 2));
	i = 0;
	while (b.current_x < pixel_to.real_x)
	{
		interpolation_param = ((float)i / distance);
		interpolated_color = interpolate_color(pixel_from, pixel_to,
				interpolation_param);
		update_coordinates(&b, pixel_from, pixel_to);
		plot_line_point(img, b, interpolated_color);
		i++;
	}
}
