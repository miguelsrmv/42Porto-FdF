/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 09:37:01 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/11 16:45:16 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img_data *img, int x, int y, int color)
{
	char	*target;

	target = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)target = color;
}
