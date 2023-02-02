/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:27:34 by niboukha          #+#    #+#             */
/*   Updated: 2023/02/02 18:37:25 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_right(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_0,
		map->coor.p_j * 60, map->coor.p_i * 60);
	mlx_put_image_to_window(map->mlx, map->win,
		map->player_a.img_p_right[map->incr / 10],
		map->coor.p_j * 60, map->coor.p_i * 60);
	return (0);
}

int	put_left(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_0,
		map->coor.p_j * 60, map->coor.p_i * 60);
	mlx_put_image_to_window(map->mlx, map->win,
		map->player_a.img_p_left[map->incr / 10],
		map->coor.p_j * 60, map->coor.p_i * 60);
	return (0);
}

int	put_up(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_0,
		map->coor.p_j * 60, map->coor.p_i * 60);
	mlx_put_image_to_window(map->mlx, map->win,
		map->player_a.img_p_up[map->incr / 10], map->coor.p_j * 60,
		map->coor.p_i * 60);
	return (0);
}

int	put_down(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->img.img_0,
		map->coor.p_j * 60, map->coor.p_i * 60);
	mlx_put_image_to_window(map->mlx, map->win,
		map->player_a.img_p_down[map->incr / 10],
		map->coor.p_j * 60, map->coor.p_i * 60);
	return (0);
}

int	animation(t_map *map)
{
	map->incr += 1;
	if (map->incr >= 30)
		map->incr = 0;
	if (map->dir == 0)
		put_right(map);
	if (map->dir == 1)
		put_left(map);
	if (map->dir == 2)
		put_up(map);
	if (map->dir == 3)
		put_down(map);
	return (0);
}
