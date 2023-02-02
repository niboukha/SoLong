/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:58:14 by niboukha          #+#    #+#             */
/*   Updated: 2023/02/02 19:43:21 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/libft.h"
# include "get_next_line.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <string.h>
# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# define ON_KEYDOWN 2
# define ON_DESTROY 17
# define PATH_WALL "./textures/1.xpm"
# define PATH_COL "./textures/C.xpm"
# define PATH_EXIT "./textures/E.xpm"
# define PATH_0 "./textures/0.xpm"

# define PATH_P_RIGHT "./textures/Pright.xpm"
# define PATH_P0_RIGHT "./textures/P0right.xpm"
# define PATH_P1_RIGHT "./textures/P1right.xpm"

# define PATH_P_LEFT "./textures/Pleft.xpm"
# define PATH_P0_LEFT "./textures/P0left.xpm"
# define PATH_P1_LEFT "./textures/P1left.xpm"

# define PATH_P_DOWN "./textures/Pdown.xpm"
# define PATH_P0_DOWN "./textures/P0down.xpm"
# define PATH_P1_DOWN "./textures/P1down.xpm"

# define PATH_P_UP "./textures/Pup.xpm"
# define PATH_P0_UP "./textures/P0up.xpm"
# define PATH_P1_UP "./textures/P1up.xpm"

# define A 0
# define S 1
# define W 13
# define D 2
# define ESC 53

typedef struct t_player_mov
{
	void	*img_player;
	void	*img_dplayer;
	void	*img_uplayer;
	void	*img_lplayer;
	void	*img_0player;
	void	*img_d0player;
	void	*img_u0player;
	void	*img_l0player;
	void	*img_1player;
	void	*img_d1player;
	void	*img_u1player;
	void	*img_l1player;
}			t_player_mov;

typedef struct t_player_arr
{
	void	*img_p_up[3];
	void	*img_p_down[3];
	void	*img_p_left[3];
	void	*img_p_right[3];
}			t_player_arr;

typedef struct t_path
{
	void	*img_wall;
	void	*img_col;
	void	*img_exit;
	void	*img_0;
}			t_path;

typedef struct t_cmpt
{
	int	pcpt;
	int	ecpt;
	int	ccpt;
}		t_cmpt;

typedef struct t_coor
{
	int	p_i;
	int	p_j;
	int	new_p_i;
	int	new_p_j;
	int	x;
	int	y;
}		t_coor;

typedef struct t_map
{
	char			**mapp;
	void			*mlx;
	void			*win;
	int				moves;
	int				incr;
	int				dir;
	t_coor			coor;
	t_player_mov	player;
	t_player_arr	player_a;
	t_path			img;
	t_cmpt			cmpt;
}			t_map;
int		check_file_ber(const char *file_ber);
int		check_arg(int ac, char **av);
void	lines_col_map(t_map *map);
void	read_map(int fd, t_map *map);
void	walls_map(t_map *map);
void	contain_map(t_map *map);
void	contain_map2(t_map *map);
void	init_struct(t_map *map);
void	exit_function(int i);
void	flood_fill(t_map *map, int i, int j);
void	check_path(t_map *map);
void	put_img_to_win(t_map *map);
void	init_img(t_map *map);
int		key(int key, t_map *map);
void	check_null(t_map *map);
void	move_player(t_map *map, int y, int x, void *img);
int		animation(t_map *map);
int		put_left(t_map *map);
int		put_down(t_map *map);
int		put_up(t_map *map);
int		put_right(t_map *map);
void	init_img_right(t_map *map);
void	init_img_left(t_map *map);
void	init_img_down(t_map *map);
void	init_img_up(t_map *map);
void	init_img_player(t_map *map);

#endif
