/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:23:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/25 15:39:25 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_error(int exit_code, t_pixel *pixel_data,
			char *buffer1, char *buffer2)
{
	if (pixel_data)
		free(pixel_data);
	if (buffer1)
		free(buffer1);
	if (buffer2)
		free(buffer2);
	if (exit_code == USAGE_ERROR)
		ft_fprintf(STDERR_FILENO, USAGE_ERROR_MSG);
	else if (exit_code == OPEN_ERROR)
		ft_fprintf(STDERR_FILENO, OPEN_ERROR_MSG);
	else if (exit_code == CLOSE_ERROR)
		ft_fprintf(STDERR_FILENO, CLOSE_ERROR_MSG);
	else if (exit_code == INVALID_MAP)
		ft_fprintf(STDERR_FILENO, INVALID_MAP_MSG);
	else if (exit_code == MALLOC_ERROR)
		ft_fprintf(STDERR_FILENO, MALLOC_ERROR_MSG);
	exit(exit_code);
}

void	clean_data(t_pixel *pixel_data, t_screen screen)
{
	free(screen.x);
	free(screen.y);
	free(pixel_data);
}

void	clean_mlx(void *img, void *mlx_win, void *mlx_service)
{
	mlx_destroy_image(mlx_service, img);
	mlx_destroy_window(mlx_service, mlx_win);
	mlx_destroy_display(mlx_service);
	free(mlx_service);
}
