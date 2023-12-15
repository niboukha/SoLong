/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:54:51 by niboukha          #+#    #+#             */
/*   Updated: 2023/02/03 11:44:03 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_map *map)
{
	map->mapp = 0;
	map->coor.x = 0;
	map->coor.y = 0;
	map->cmpt.ecpt = 0;
	map->cmpt.pcpt = 0;
	map->cmpt.ccpt = 0;
	map->coor.p_i = 0;
	map->coor.p_j = 0;
	map->moves = 0;
	map->incr = 0;
	map->dir = 0;
}

int	exit_prog(void)
{
	exit(1);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;
	int		fd;

	init_struct(&map);
	map.mlx = mlx_init();
	check_arg(ac, av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror(av[1]);
		exit(1);
	}
	read_map(fd, &map);
	lines_col_map(&map);
	check_path(&map);
	map.win = mlx_new_window(map.mlx, map.coor.x * 60, map.coor.y * 60,
			"./so_long");
	init_img(&map);
	put_img_to_win(&map);
	mlx_hook(map.win, ON_KEYDOWN, 0, key, &map);
	mlx_loop_hook(map.mlx, animation, &map);
	mlx_hook(map.win, ON_DESTROY, 0, exit_prog, &map);
	mlx_loop(map.mlx);
	return (0);
}
