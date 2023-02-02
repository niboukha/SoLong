/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:55:20 by niboukha          #+#    #+#             */
/*   Updated: 2023/02/02 21:17:11 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_null(t_map *map)
{
	if (!map->img.img_wall || !map->img.img_col
		|| !map->img.img_exit || !map->img.img_0)
		exit_function(7);
}

void	init_img(t_map *map)
{
	int	height_img;
	int	width_img;

	height_img = 60;
	width_img = 60;
	map->img.img_wall = mlx_xpm_file_to_image
		(map->mlx, PATH_WALL, &width_img, &height_img);
	map->img.img_col = mlx_xpm_file_to_image
		(map->mlx, PATH_COL, &width_img, &height_img);
	map->img.img_exit = mlx_xpm_file_to_image
		(map->mlx, PATH_EXIT, &width_img, &height_img);
	map->img.img_0 = mlx_xpm_file_to_image
		(map->mlx, PATH_0, &width_img, &height_img);
	init_img_player(map);
	init_img_down(map);
	init_img_up(map);
	init_img_right(map);
	init_img_left(map);
	check_null(map);
}

void	check_img_to_win(t_map *map, int y, int x)
{
	mlx_put_image_to_window (map->mlx, map->win, map->img.img_0,
		x * 60, y * 60);
	if (map->mapp[y][x] == '1')
		mlx_put_image_to_window (map->mlx, map->win, map->img.img_wall,
			x * 60, y * 60);
	else if (map->mapp[y][x] == 'C')
		mlx_put_image_to_window (map->mlx, map->win, map->img.img_col,
			x * 60, y * 60);
	else if (map->mapp[y][x] == 'E')
		mlx_put_image_to_window (map->mlx, map->win, map->img.img_exit,
			x * 60, y * 60);
}

void	put_img_to_win(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->mapp[y])
	{
		x = 0;
		while (map->mapp[y][x])
		{
			check_img_to_win(map, y, x);
			x++;
		}
		y++;
	}
}
