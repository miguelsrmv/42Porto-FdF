/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:03:12 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/25 14:17:23 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		cross_pressed(int keycode, t_pixel *pixel_data)
{
	if (keycode == ESC_KEY)
	{
		free(pixel_data);
		exit(0);
	}
	return (0);
}
