/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:50:38 by niboukha          #+#    #+#             */
/*   Updated: 2023/02/02 21:02:24 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_map *map, int y, int x, void *img)
{
	if (map->mapp[y][x] == '0' || map->mapp[y][x] == 'C')
	{
		mlx_put_image_to_window (map->mlx, map->win, img,
			x * 60, y * 60);
		mlx_put_image_to_window (map->mlx, map->win, map->img.img_0,
			map->coor.p_j * 60, map->coor.p_i * 60);
		map->coor.p_i = y;
		map->coor.p_j = x;
		if (map->mapp[y][x] == 'C')
		{
			map->mapp[y][x] = '0';
			map->cmpt.ccpt--;
		}
		map->moves++;
		ft_printf("%d\n", map->moves);
	}
	if (map->mapp[y][x] == 'E' && map->cmpt.ccpt == 0)
	{
		ft_printf("%d\n", ++map->moves);
		ft_printf("YOU WON!\n");
		exit(0);
	}
}

void	key_norm(int key_hook, t_map *map)
{
	if (key_hook == S || key_hook == 125)
	{
		map->dir = 3;
		move_player(map, map->coor.new_p_i + 1, map->coor.new_p_j,
			map->player.img_dplayer);
	}
	else if (key_hook == W || key_hook == 126)
	{
		map->dir = 2;
		move_player(map, map->coor.new_p_i - 1, map->coor.new_p_j,
			map->player.img_uplayer);
	}
	else if (key_hook == ESC)
		exit(1);
}

int	key(int key_hook, t_map *map)
{
	map->coor.new_p_i = map->coor.p_i;
	map->coor.new_p_j = map->coor.p_j;
	map->mapp[map->coor.new_p_i][map->coor.new_p_j] = '0';
	if (key_hook == A || key_hook == 123)
	{
		map->dir = 1;
		move_player(map, map->coor.new_p_i, map->coor.new_p_j - 1,
			map->player.img_lplayer);
	}
	else if (key_hook == D || key_hook == 124)
	{
		map->dir = 0;
		move_player(map, map->coor.new_p_i, map->coor.new_p_j + 1,
			map->player.img_player);
	}
	key_norm(key_hook, map);
	return (0);
}
