/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:48:55 by niboukha          #+#    #+#             */
/*   Updated: 2023/02/02 21:18:48 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img_right(t_map *map)
{
	int	height_img;
	int	width_img;

	height_img = 60;
	width_img = 60;
	map->player_a.img_p_right[1] = mlx_xpm_file_to_image
		(map->mlx, PATH_P_RIGHT, &width_img, &height_img);
	map->player_a.img_p_right[2] = mlx_xpm_file_to_image
		(map->mlx, PATH_P0_RIGHT, &width_img, &height_img);
	map->player_a.img_p_right[0] = mlx_xpm_file_to_image
		(map->mlx, PATH_P1_RIGHT, &width_img, &height_img);
	if (!map->player_a.img_p_right[1] || !map->player_a.img_p_right[2]
		|| !map->player_a.img_p_right[0])
		exit_function(7);
}

void	init_img_left(t_map *map)
{
	int	height_img;
	int	width_img;

	height_img = 60;
	width_img = 60;
	map->player_a.img_p_left[1] = mlx_xpm_file_to_image
		(map->mlx, PATH_P_LEFT, &width_img, &height_img);
	map->player_a.img_p_left[2] = mlx_xpm_file_to_image
		(map->mlx, PATH_P0_LEFT, &width_img, &height_img);
	map->player_a.img_p_left[0] = mlx_xpm_file_to_image
		(map->mlx, PATH_P1_LEFT, &width_img, &height_img);
	if (!map->player_a.img_p_left[1] || !map->player_a.img_p_left[0]
		|| !map->player_a.img_p_left[2])
		exit_function(7);
}

void	init_img_up(t_map *map)
{
	int	height_img;
	int	width_img;

	height_img = 60;
	width_img = 60;
	map->player_a.img_p_up[1] = mlx_xpm_file_to_image
		(map->mlx, PATH_P_UP, &width_img, &height_img);
	map->player_a.img_p_up[2] = mlx_xpm_file_to_image
		(map->mlx, PATH_P0_UP, &width_img, &height_img);
	map->player_a.img_p_up[0] = mlx_xpm_file_to_image
		(map->mlx, PATH_P1_UP, &width_img, &height_img);
	if (!map->player_a.img_p_up[1] || !map->player_a.img_p_up[0]
		|| !map->player_a.img_p_up[1])
		exit_function(7);
}

void	init_img_down(t_map *map)
{
	int	height_img;
	int	width_img;

	height_img = 60;
	width_img = 60;
	map->player_a.img_p_down[1] = mlx_xpm_file_to_image
		(map->mlx, PATH_P_DOWN, &width_img, &height_img);
	map->player_a.img_p_down[2] = mlx_xpm_file_to_image
		(map->mlx, PATH_P0_DOWN, &width_img, &height_img);
	map->player_a.img_p_down[0] = mlx_xpm_file_to_image
		(map->mlx, PATH_P1_DOWN, &width_img, &height_img);
	if (!map->player_a.img_p_down[1] || !map->player_a.img_p_down[0]
		|| !map->player_a.img_p_down[2])
		exit_function(7);
}

void	init_img_player(t_map *map)
{
	int	height_img;
	int	width_img;

	height_img = 60;
	width_img = 60;
	map->player.img_player = mlx_xpm_file_to_image
		(map->mlx, PATH_P_RIGHT, &width_img, &height_img);
	map->player.img_lplayer = mlx_xpm_file_to_image
		(map->mlx, PATH_P_LEFT, &width_img, &height_img);
	map->player.img_uplayer = mlx_xpm_file_to_image
		(map->mlx, PATH_P_UP, &width_img, &height_img);
	map->player.img_dplayer = mlx_xpm_file_to_image
		(map->mlx, PATH_P_DOWN, &width_img, &height_img);
	if (!map->player.img_player || !map->player.img_lplayer
		|| !map->player.img_uplayer || !map->player.img_dplayer)
		exit_function(7);
}
