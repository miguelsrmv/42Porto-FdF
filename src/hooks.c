/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:03:12 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/26 10:38:28 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	esc_pressed(int keycode, void *mlx_service)
{
	if (keycode == ESC_KEY)
		mlx_loop_end(mlx_service);
	return (0);
}

void	set_hooks(void *mlx_win, void *mlx_service)
{
	mlx_hook(mlx_win, 17, 1L << 17, mlx_loop_end, mlx_service);
	mlx_key_hook(mlx_win, esc_pressed, mlx_service);
}
