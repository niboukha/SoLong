# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niboukha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 14:53:49 by niboukha          #+#    #+#              #
#    Updated: 2023/02/03 12:12:17 by niboukha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = lib/libft.a
PRINTF = ft_printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = check_map.c read_map.c so_long.c get_next_line.c get_next_line_utils.c main.c handel_map.c valid_path.c move_player.c\
	animation_p.c init_imgs.c

OBJ = $(SRC:.c=.o)

all : $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT) :
	make -C lib/

$(PRINTF) :
	make -C ft_printf/

clean :
	make clean -C lib/
	make clean -C ft_printf/
	rm -f $(OBJ)

fclean : clean
	make fclean -C lib/
	make fclean -C ft_printf/
	rm -f $(NAME)

re : fclean all

.PHONY: all re clean fclean
