/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:11:18 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/09 12:09:34 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"

// Macros
# define SUCCESS 1
# define USAGE_ERROR 1
# define OPEN_ERROR 2
# defube READ_ERROR 3
# define CLOSE_ERROR 4
# define INT_MIN -2147483648
# define INT_MAX 2147483647

// Struct typedefs
/// Image data
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data_data {
	int		x;
	int		y;
	int		z_min;
	int		z_max;
}				t_map_data;

typedef struct s_pixel_data {
	int		x;
	int 	y;
	int		z;
	int		color;
}				t_pixel_data;

// Function declarations
/// Draw.c
void	my_pixel_put(t_img *img, int x, int y, int color);

/// Voxelgrid.c
t_map_data	parse_map(char *input_map);
void	read_from_file(int input_fd, t_map_data *map_data);

// int		**create_voxel(char *input);
// void	init_coordinates(t_coordinates *coordinates);
//int		**malloc_voxel(char *input, t_coordinates *coordinates);

#endif