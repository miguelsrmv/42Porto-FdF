/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:03:12 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/25 14:45:56 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	cross_pressed(int keycode, void *mlx_service)
{
	if (keycode == ESC_KEY)
		mlx_loop_end(mlx_service);
	return (0);
}
