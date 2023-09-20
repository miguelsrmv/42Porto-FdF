/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:23:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/20 20:38:49 by mde-sa--         ###   ########.fr       */
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
