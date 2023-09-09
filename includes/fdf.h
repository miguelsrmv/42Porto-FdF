/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:11:18 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/09 23:56:27 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"


// Macros
# define SUCCESS 1
# define USAGE_ERROR 1
# define USAGE_ERROR_MSG "Usage: ./fdf <map_file>"
# define OPEN_ERROR 2
# define OPEN_ERROR_MSG "Error opening file."
# define CLOSE_ERROR 3
# define CLOSE_ERROR_MSG "Error closing file."
# define INVALID_MAP 4
# define INVALID_MAP_MSG "Found wrong line length. Exiting."
# define MALLOC_ERROR 5
# define MALLOC_ERROR_MSG "Malloc error."
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

typedef struct s_map_data {
	int		x;
	int		y;
	int		z_min;
	int		z_max;
}				t_map_data;

typedef struct s_pixel {
	int		x;
	int		y;
	int		z;
	int		color;
}				t_pixel;

// Function declarations
/// Draw.c
void		my_pixel_put(t_img *img, int x, int y, int color);

/// Map_data.c
t_map_data	get_map_data(char *input_map);
void		process_lines(char *line, int input_fd, t_map_data *map_data,
				char **total_buffer);
int			count_size(char *line);
char		*trim_line(char *line);
void		get_min_and_max(t_map_data *map_data, char *total_buffer);

// Pixel_data.c
void		fill_pixel_data(t_pixel *pixel_data, t_map_data map_data,
				char *input_map);
void		fill_from_buffer(t_pixel *pixel_data, t_map_data map_data,
				char **split_total_buffer);
void		consider_hex_data(t_pixel *pixel_data, char **split_total_buffer,
				int i);
char		*corrected_hex(char *number);

/// Exit_error.c
void		exit_error(int exit_code, t_pixel *pixel_data,
				char *buffer1, char *buffer2);

/// Helpers
void		print_buffered_data(t_pixel *pixel_data, t_map_data map_data);

/*
/// Valid_map
void    check_valid_map(char *input);
void    check_name(char *input);
void    check_size(char *input);
*/

#endif