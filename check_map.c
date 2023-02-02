/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:15:26 by niboukha          #+#    #+#             */
/*   Updated: 2023/02/02 18:37:18 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_ber(const char *file_ber)
{
	char	*ext;
	int		len_file;
	int		len_ext;

	ext = ".ber";
	len_file = ft_strlen(file_ber) - 1;
	len_ext = ft_strlen(ext) - 1;
	while (len_ext >= 0)
	{
		if (file_ber[len_file] != ext[len_ext])
			return (0);
		len_ext--;
		len_file--;
	}
	return (1);
}

int	check_arg(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("ERROR\nArg number incorrect");
		exit(1);
	}
	if (check_file_ber(av[1]) == 0)
		exit_function(0);
	return (1);
}
