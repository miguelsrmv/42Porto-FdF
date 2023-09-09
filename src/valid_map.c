/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:43:30 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/10 00:34:08 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_valid_map(char *input)
{
	int	file_fd;

	check_name(input);
	check_size(input);
	file_fd = open(input, O_RDONLY);
	if (file_fd == -1)
		exit(READ_ERROR);
	if (!close(file_fd))
		exit(CLOSE_ERROR);
}

void	check_name(char *input)
{
	int	len;

	len = ft_strlen(input);
	if (len < 5)
		exit(INVALID_MAP);
	if (!ft_strncmp(&input[len - 5], "/", 1))
		exit(INVALID_MAP);
	if (ft_strncmp(&input[len - 4], ".fdf", 4))
		exit(INVALID_MAP);
}

void	check_size(char *input)
{
	int		file_fd;
	char	*line;
	char	**split_line;

	file_fd = open(input, O_RDONLY);
	if (file_fd == -1)
		exit(READ_ERROR);
	line = get_next_line(file_fd);
	free(line);
	line = get_next_line(file_fd);
	if (!line)
		exit(INVALID_MAP);
	split_line = ft_split(line, ' ');
	if ((ft_count_tabs((void **)split_line)) < 2)
		exit(INVALID_MAP);
	ft_free_tabs((void **)split_line);
	free(line);
	if (!close(file_fd))
		exit(CLOSE_ERROR);
}
// Maior que 2 por 2
// So tem numeros
// Hexadecimal cores
// Linhas de tamanhos iguais