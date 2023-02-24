/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:06:01 by jaurasma          #+#    #+#             */
/*   Updated: 2023/02/24 17:48:04 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define  FDF_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define WINDOW_WIDTH 1980
# define WINDOW_HEIGHT 1080
# define LINE_LENGHT 7

# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x008000
# define CYAN  0x00FF00
# define YELLOWISH 0xFFC300

typedef struct s_map_data
{
	int	width;
	int height;
	int color;
	int line_len;
	int	**map;
	int max_height;
}t_map_data;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_win_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*ptr;
}t_win_data;

typedef struct s_counter
{
	int		i;
	int		j;
	int		k;
	int		l;
}t_counter;

typedef struct s_coordinates
{
	int start_x;
	int start_y;
	int end_x;
	int end_y;
	double angle;
	double z_scale;
	double difference;
} t_coordinates;

typedef struct s_x_save
{
	int x_save;
	int y_save;
} t_x_save;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		handle_keypress(int keysym, t_win_data *data);
void	map_handler(int argc, char **argv, t_map_data *map);
void	inizialize_counter(t_counter *count);
void	scaler(t_map_data *map, t_counter *count);
void	draw_line(t_data *img, int x1, int y1, int x2, int y2, int color);
int		my_abs(int num);
int		handle_cross(t_win_data *data);
int		count_difference_x(t_map_data *map, int y, int x);
int		count_difference_y(t_map_data *map, int y, int x);
void	init_coords_x(t_coordinates *coords, t_map_data *map);
void	draw_y_lines(t_data *img, t_map_data *map, t_coordinates *coords, int y, int x);
void	draw_first_y_lines(t_data *img, t_map_data *map, t_coordinates *coords,t_x_save *save, int y, int x);
void	draw_grid(t_data *img, t_map_data *map, t_coordinates *coords);
int 	colortree(t_map_data *map, int x ,int y);
void	free_map(t_map_data *map);
void	save_map(t_map_data *map, char **argv, int i, int j);


#endif