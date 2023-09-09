/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:23:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/09 23:26:32 by mde-sa--         ###   ########.fr       */
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
		ft_fprintf(STDERR_FILENO, "Usage: ./fdf <map_file>\n");
	else if (exit_code == OPEN_ERROR)
		ft_fprintf(STDERR_FILENO, "Error opening file.\n");
	else if (exit_code == CLOSE_ERROR)
		ft_fprintf(STDERR_FILENO, "Error closing file.\n");
	else if (exit_code == INVALID_MAP)
		ft_fprintf(STDERR_FILENO, "Found wrong line length. Exiting.\n");
	else if (exit_code == MALLOC_ERROR)
		ft_fprintf(STDERR_FILENO, "Malloc error.\n");
	exit(exit_code);
}
