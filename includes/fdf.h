/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:11:18 by mde-sa--          #+#    #+#             */
/*   Updated: 2023/09/26 10:37:33 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../src/libft/libft.h"
# include <math.h>

// Macros
# define SUCCESS 1
# define USAGE_ERROR 1
# define USAGE_ERROR_MSG "Usage: ./fdf <map_file>\n"
# define OPEN_ERROR 2
# define OPEN_ERROR_MSG "Error opening file.\n"
# define CLOSE_ERROR 3
# define CLOSE_ERROR_MSG "Error closing file.\n"
# define INVALID_MAP 4
# define INVALID_MAP_MSG "Found wrong line length. Exiting.\n"
# define MALLOC_ERROR 5
# define MALLOC_ERROR_MSG "Malloc error.\n"
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define ANGLE 30
# define PADDING 50
# define ESC_KEY 65307

// Struct typedefs
/// Image data
typedef struct s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct s_map_data {
	int		x;
	int		y;
	int		real_width;
	int		real_height;
	int		final_min_x;
	int		final_max_x;
	int		final_min_y;
	int		final_max_y;
}				t_map_data;

typedef struct s_rgb {
	int		red;
	int		blue;
	int		green;
}		t_rgb;

typedef struct s_pixel {
	int		x;
	int		y;
	int		z;
	double	calc_x;
	double	calc_y;
	int		real_x;
	int		real_y;
	t_rgb	rgb;
	int		color;
}				t_pixel;

typedef struct s_screen {
	int		*x;
	int		*y;
}			t_screen;

typedef struct s_bresenhaim {
	int		current_x;
	int		current_y;
	int		delta_x;
	int		delta_y;
	int		decision;
	int		steep;
}		t_bresenhaim;

// Function declarations
/// Map_data.c
t_map_data	get_map_data(char *input_map);
void		create_total_buffer(char *line, int input_fd, t_map_data *map_data,
				char **total_buffer);
int			count_size(char *line);
char		*trim_line(char *line);

/// Pixel_data.c
void		fill_pixel_data(t_pixel *pixel_data, t_map_data *map_data,
				char *input_map);
void		fill_from_buffer(t_pixel *pixel_data, t_map_data map_data,
				char **split_total_buffer);
void		consider_hex_data(t_pixel *pixel_data, char **split_total_buffer,
				int i);
void		get_color(char *hex, t_pixel *pixel_data);

/// Mlx_service.c
void		start_service(t_pixel *pixel_data, t_map_data map_data,
				t_screen window_data);

/// Calculations_Rotation.c
void		calculate_projection(t_pixel *pixel_data, t_map_data *map_data,
				double angle);
void		adjust_map_real_width(t_pixel *pixel_data, t_map_data *map_data);
void		adjust_map_real_height(t_pixel *pixel_data, t_map_data *map_data);
double		degree_to_rad(double angle);

/// Calculations_Resize_Center.c
int			get_scale(t_map_data map_data, int *sizex, int *sizey);
void		resize_projection(t_pixel *pixel_data, t_map_data *map_data,
				int distance);
void		center_projection(t_pixel *pixel_data, t_map_data map_data,
				int *sizex, int *sizey);

/// Draw.c
void		my_pixel_put(t_img_data *img, int x, int y, int color);
void		draw_pixels(t_pixel *pixel_data, t_map_data map_data,
				t_img_data img);
void		draw_lines(t_pixel *pixel_data, t_map_data map_data,
				t_img_data img);
void		process_and_draw_image(t_pixel *pixel_data, t_map_data *map_data,
				t_screen *screen_data, t_img_data *img);

/// Bresenhaim.c
void		line_bresenhaim(t_pixel pixel_from, t_pixel pixel_to,
				t_img_data img);
void		plot_line_point(t_img_data img, t_bresenhaim b, int color);
void		init_bresenham(t_bresenhaim *b, t_pixel *pixel_from,
				t_pixel *pixel_to);
void		update_coordinates(t_bresenhaim *b, t_pixel pixel_from,
				t_pixel pixel_to);
int			interpolate_color(t_pixel pixel_from, t_pixel pixel_to,
				float interpolation_param);

/// Hooks.c
int			esc_pressed(int keycode, void *mlx_service);
void		set_hooks(void *mlx_win, void *mlx_service);

/// Data_clean.c
void		exit_error(int exit_code, t_pixel *pixel_data,
				char *buffer1, char *buffer2);
void		clean_data(t_pixel *pixel_data, t_screen screen);
void		clean_mlx(void *img, void *mlx_win, void *mlx_service);

#endif