/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:15:48 by jaurasma          #+#    #+#             */
/*   Updated: 2023/02/24 17:54:25 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void map_handler(int argc, char **argv, t_map_data *map)
{
	int fd;
	int i;
	int	j;
	char **temp;
	char *line;

	fd = 0;
	i = 0;
	j = 0;
	if(argc != 2)
	{
		ft_printf("Please enter only two arguments!\n");
		exit (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit (1);
	line = get_next_line(fd);
	temp = ft_split(line, ' ');
	if (!temp)
		return ;
	while(temp[i] != NULL)
	{
		free(temp[i]);
		i++;
	}
	map->width = i;
	free(temp);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		j++;
	}
	free(line);
	map->height = j;
	close(fd);
	save_map(map, argv, i ,j);
}

void	save_map(t_map_data *map, char **argv, int i, int j)
{
	char **temp;
	int	fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit (1);
 	map->map = (int **)malloc((sizeof(int *) * map->height));
	if(!map->map)
		return ;
	while(i < map->height)
	{
		j = 0;
		temp = ft_split(get_next_line(fd), ' ');
		map->map[i]  = (int *)malloc(sizeof(int) * map->width);
		while (temp[j] != NULL)
		{
			map->map[i][j] = ft_atoi(temp[j]);
			free(temp[j]);
			j++;
		}
		free(temp);
		i++;
	}
	close(fd);
}

void	inizialize_counter(t_counter *count)
{
	count->i = 0;
	count->j = 0;
	count->k = 0;
	count->l = 0;
}

void	scaler(t_map_data *map, t_counter *count)
{
	while(map->height * count->i < WINDOW_HEIGHT && map->width * count->i < WINDOW_WIDTH)
		count->i++;
	if(count->i > 1)
		map->line_len = count->i / 2;
	else
		map->line_len = 1;
	count->i = 0;
}

int	my_abs(int num)
{
	if (num >= 0)
		return (num);
	else
		return (num * -1);
}

void draw_line(t_data *img, int x1, int y1, int x2, int y2, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int err;
	int e2;

	dx = my_abs(x2 - x1);
	dy = my_abs(y2 - y1);
	err = dx - dy;
	sx = -1;
	sy = -1;
	if (x1 < x2)
		sx = 1;
	if (y1 < y2)
		sy = 1;
	while (1)
	{
		if ((x1 > 0 && y1 > 0) && (x1 < WINDOW_WIDTH && y1 < WINDOW_HEIGHT))
			my_mlx_pixel_put(img, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}