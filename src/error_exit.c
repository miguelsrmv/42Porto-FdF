/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 22:23:51 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/09 22:40:05 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_exit(int exit_code, char *buffer1, char *buffer2)
{
	if (buffer1)
		free(buffer1);
	if (buffer2)
		free(buffer2);
	if (exit_code == INVALID_MAP)
		ft_printf("Found wrong line length. Exiting.\n");
	exit(exit_code);
}
