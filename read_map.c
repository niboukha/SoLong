/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:40:14 by niboukha          #+#    #+#             */
/*   Updated: 2023/02/01 17:22:46 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(int fd, t_map *map)
{
	char	*buffer;
	char	*map_join;

	map_join = NULL;
	buffer = get_next_line(fd);
	while (buffer)
	{
		if (ft_strlen(buffer) == 1)
			exit_function(1);
		map_join = ft_strjoin(map_join, buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	if (!map_join)
		exit(1);
	map->mapp = ft_split(map_join, '\n');
	free(map_join);
}

void	exit_function(int i)
{
	if (i == 0)
		ft_printf("Error\n Invalid file.");
	else if (i == 1)
		ft_printf("Error\n Empty line!");
	else if (i == 2)
		ft_printf("Error\n Map is not rectangular.");
	else if (i == 3)
		ft_printf("Error\n The map must be closed/surrounded by 1.");
	else if (i == 4)
		ft_printf("Error\n The map can be composed of only 0 1 C E P.");
	else if (i == 5)
		ft_printf("Error\n The map must contain 1 E, at least 1 C, and 1 P.");
	else if (i == 6)
		ft_printf("Error\n Invalid path.");
	else
		ft_printf("Error\n Invalid image");
	exit(1);
}
