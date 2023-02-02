/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:27:18 by niboukha          #+#    #+#             */
/*   Updated: 2023/02/02 15:24:08 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lines_col_map(t_map *map)
{
	size_t	len_y;

	map->coor.y = 0;
	len_y = ft_strlen(map->mapp[map->coor.y]);
	while (map->mapp[map->coor.y])
	{
		map->coor.x = 0;
		while (map->mapp[map->coor.y][map->coor.x])
		{
			if (len_y != ft_strlen(map->mapp[map->coor.y]))
				exit_function(2);
			else
				map->coor.x++;
		}
		map->coor.y++;
	}
	walls_map(map);
	contain_map(map);
	contain_map2(map);
}

void	walls_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->mapp[i])
	{
		j = 0;
		while (map->mapp[i][j])
		{
			if (map->mapp[0][j] != '1' || map->mapp[map->coor.y - 1][j] != '1')
				exit_function(3);
			else
				j++;
			if (map->mapp[i][0] != '1'
				|| map->mapp[i][ft_strlen(map->mapp[i]) - 1] != '1')
				exit_function(3);
		}
		i++;
	}
}

void	contain_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->mapp[i])
	{
		j = 0;
		while (map->mapp[i][j])
		{
			if (map->mapp[i][j] == 'P')
			{
				map->cmpt.pcpt++;
				map->coor.p_i = i;
				map->coor.p_j = j;
			}
			if (map->mapp[i][j] == 'E')
				map->cmpt.ecpt++;
			if (map->mapp[i][j] == 'C')
				map->cmpt.ccpt++;
			j++;
		}
		i++;
	}
	if (map->cmpt.pcpt != 1 || map->cmpt.ecpt != 1 || map->cmpt.ccpt < 1)
		exit_function(5);
}

void	contain_map2(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->mapp[i])
	{
		j = 0;
		while (map->mapp[i][j])
		{
			if (map->mapp[i][j] != '0' && map->mapp[i][j] != '1'
				&& map->mapp[i][j] != 'C' && map->mapp[i][j] != 'E'
				&& map->mapp[i][j] != 'P')
				exit_function(4);
			j++;
		}
		i++;
	}
}
