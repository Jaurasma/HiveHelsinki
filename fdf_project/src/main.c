/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:21:35 by jaurasma          #+#    #+#             */
/*   Updated: 2023/02/24 18:26:06 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Read .fdf file: Write code to read the .fdf file and store the coordinates of the landscape in an appropriate data structure.
Render the model in isometric projection: Write code to represent the landscape in isometric projection using the stored coordinates.
Display image in a window: Use MiniLibX functions to display the image in a window.
Handle window management: Write code to handle window management smoothly, including minimizing,
 changing to another window, and closing the window and quitting the program in a clean way when either the ESC key is pressed or the close button is clicked.
Error handling: Add error handling to ensure the program doesn't crash when run with improperly formatted maps.
Use libft functions: Make use of the functions in libft, such as get_next_line(), ft_split(), and others, to read data from the .fdf file in a quick and simple way.
*/

#include "../inc/fdf.h"
#include <stdio.h>
//#include <stdio.h>

/* int offset = (y * line_length + x * (bits_per_pixel / 8));*/

/*int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}*/
void	free_map(t_map_data *map)
{
	int y;

	y = map->height -1;
	while(y >= 0)
	{
		free(map->map[y]);
		y--;
	}
	free(map->map);
}

int	handle_keypress(int keysym, t_win_data *data)
{
	ft_printf("key press is %d\n", keysym);
	if (keysym == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data->mlx_ptr);
		data->win_ptr = NULL;
		exit (0);
	}
	return (0);
}

int handle_cross(t_win_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	data->win_ptr = NULL;
	exit (0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int count_difference_x(t_map_data *map, int y, int x)
{
	int difference;

	difference = 0;
	if (x < map->width -1)
		difference = map->map[y][x + 1] - map->map[y][x];
	return (difference * 3);
}

int count_difference_y(t_map_data *map, int y, int x)
{
	int difference;

	difference = 0;
	if (y < map->height -1)
		difference = map->map[y + 1][x] - map->map[y][x];
	return (difference * 3);
}

void init_coords_x(t_coordinates *coords, t_map_data *map)
{
	coords->angle = 2;
	coords->z_scale = 0.1;
	coords->start_x = WINDOW_WIDTH / 2 ;
	coords->start_y = WINDOW_HEIGHT / 2 - (map->height * map->line_len) + map->map[0][0];
	coords->end_x = coords->start_x + map->line_len; 
	coords->end_y = (coords->start_y + map->line_len/coords->angle) - count_difference_x(map, 0, 0);
}

void draw_y_lines(t_data *img, t_map_data *map, t_coordinates *coords, int y, int x)
{
	int start_y = coords->start_y;
	int start_x = coords->start_x;
	int end_y;
	int end_x;

	end_x = start_x - map->line_len; 
	end_y = (start_y + map->line_len) - count_difference_y(map, y, x);
	draw_line(img, start_x, start_y, end_x, end_y, colortree(map, y ,x));
}

void draw_first_y_lines(t_data *img, t_map_data *map, t_coordinates *coords,t_x_save *save, int y, int x)
{
	int start_y = coords->start_y;
	int start_x = coords->start_x;
	int end_y;
	int end_x;

	end_x = start_x - map->line_len; 
	end_y = (start_y + map->line_len) - count_difference_y(map, y, x);
	draw_line(img, start_x, start_y, end_x, end_y, colortree(map, y ,x));
	save->x_save = end_x;
	save->y_save = end_y;
}
int colortree(t_map_data *map, int y ,int x)
{
	if(map->map[y][x] < 3)
		return(0xC9B311);
	else if (map->map[y][x] < 6)
		return (0xDF855A);
	else if (map->map[y][x] < 13)
		return (0xB2497F);
	else if (map->map[y][x] < 18)
		return (0x7F1B9F);
	else
		return (0x270f8f);
}

void draw_grid(t_data *img, t_map_data *map, t_coordinates *coords)
{
	int	x;
	int	y;
	t_x_save save;

	y = 0;
	x = 0;
	init_coords_x(coords, map);
	while(y < map->height)
	{
		while(x < map->width - 1)
		{
			draw_line(img, coords->start_x, coords->start_y, coords->end_x, coords->end_y, colortree(map, y ,x));
			if(x == 0 && y != map->height -1)
				draw_first_y_lines(img, map, coords, &save, y, x);
			x++;
			coords->start_x = coords->end_x;
			coords->start_y = coords->end_y;
			if(x > 0 && y != map->height -1)
				draw_y_lines(img, map, coords, y, x);
			coords->end_x = coords->start_x + map->line_len; 
			coords->end_y = (coords->start_y + map->line_len/coords->angle) - count_difference_x(map, y, x);
		}
		y++;
		if (y == map->height)
		{
			free_map(map);
			break ;
		}
		x = 0;
		coords->start_x = save.x_save;
		coords->start_y = save.y_save;
		coords->end_x = coords->start_x + map->line_len;
		coords->end_y = (coords->start_y + map->line_len/coords->angle) - count_difference_x(map, y, x);
	}
}

int main(int argc, char **argv)
{
	t_win_data  window;
	t_data img;
	t_map_data map;
	t_counter count;
	t_coordinates coords;
	
	map.width = 0;
	map.height = 0;
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	img.img = mlx_new_image(window.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	window.ptr = img.img;
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	map_handler(argc, argv, &map);
	inizialize_counter(&count);
	scaler(&map, &count);
	map.max_height = 10;
	draw_grid(&img, &map, &coords);
	//free_map(map);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, img.img, 0, 0);
	mlx_key_hook(window.win_ptr, handle_keypress, &window);
	mlx_hook(window.win_ptr, 17, 0, handle_cross, window.mlx_ptr);
	mlx_loop(window.mlx_ptr);
	return (0);
}