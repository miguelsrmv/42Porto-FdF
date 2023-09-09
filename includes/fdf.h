/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:11:18 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/09 20:38:24 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include "libft.h"


// Macros
# define SUCCESS 1
# define USAGE_ERROR 1
# define OPEN_ERROR 2
# define READ_ERROR 3
# define CLOSE_ERROR 4
# define INVALID_MAP 5 Found wrong line length. Exiting.
# define MALLOC_ERROR 6
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

typedef struct s_map_dimensions {
	int		x;
	int		y;
	int		z_min;
	int		z_max;
}				t_map_dimensions;

typedef struct s_pixel {
	int		x;
	int 	y;
	int		z;
	int		color;
}				t_pixel;

// Function declarations
/// Draw.c
void	my_pixel_put(t_img *img, int x, int y, int color);

/// Map_dimensions
t_map_dimensions	get_map_dimensions(char *input_map);
int					count_size(char *line);
void				get_min_and_max(t_map_dimensions *map_dimensions, char *total_buffer);
char 				*trim_line(char *line);

// Fill_data
void	fill_pixel_data (t_pixel *pixel_data, t_map_dimensions map_dimensions, char *input_map);
void	fill_from_buffer(t_pixel *pixel_data, t_map_dimensions map_dimensions, char **split_total_buffer);
void	consider_hex_data(t_pixel *pixel_data, char *split_total_buffer, int i);
char	*corrected_hex(char *number);

/// Helpers
void    print_buffered_data(t_pixel *pixel_data, t_map_dimensions map_dimensions);

/*
/// Valid_map
void    check_valid_map(char *input);
void    check_name(char *input);
void    check_size(char *input);
*/

#endif