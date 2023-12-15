/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:33:05 by niboukha          #+#    #+#             */
/*   Updated: 2023/02/03 11:16:58 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *map, int i, int j)
{
	if (map->mapp[i][j] < 0 || map->mapp[i][j] == '1' || map->mapp[i][j] == 'E')
	{
		(map->mapp[i][j] == 'E') && (map->mapp[i][j] *= -1);
		return ;
	}
	map->mapp[i][j] *= -1;
	flood_fill(map, i - 1, j);
	flood_fill(map, i + 1, j);
	flood_fill(map, i, j - 1);
	flood_fill(map, i, j + 1);
}

void	check_path(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	flood_fill(map, map->coor.p_i, map->coor.p_j);
	while (map->mapp[i])
	{
		j = 0;
		while (map->mapp[i][j])
		{
			if (map->mapp[i][j] == 'C' || map->mapp[i][j] == 'E')
				exit_function(6);
			if (map->mapp[i][j] < 0)
				map->mapp[i][j] *= -1;
			j++;
		}
		i++;
	}
}
