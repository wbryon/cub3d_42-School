# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbryon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/22 12:23:46 by wbryon            #+#    #+#              #
#    Updated: 2021/02/26 23:19:41 by wbryon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

HEADER		= srcs/cub3d.h

SRCS		= srcs/raycast.c srcs/move_keys.c srcs/check_id.c srcs/get_colors.c\
			  srcs/parse_textures.c srcs/check_player.c srcs/create_image.c\
			  srcs/cub3d.c srcs/screenshot.c srcs/sprite_position.c\
			  srcs/errors_table_1.c srcs/keys_rule.c srcs/draw_textures.c\
			  srcs/errors_table_2.c srcs/map_checker.c srcs/utils.c\
			  srcs/get_textures.c srcs/init_all.c

LIBFT		= libft/*.c

OBJS		= $(SRCS:.c=.o)

GCC			= gcc -Wall -Wextra -Werror

MLX			= mlx/libmlx.dylib

DYLIB		= -lmlx -framework OpenGL -framework AppKit

RM			= rm -f

all:			$(NAME)

.c.o:		=
				$(GCC) -c $< -o $(<:.c=.o)

$(NAME):		$(SRCS) $(HEADER) $(LIBFT) $(MLX)
						make -C libft
						$(GCC) -o $(NAME) $(MLX) $(DYLIB) $(SRCS) libft/libft.a gnl/*.c

$(MLX):
						make -C "mlx"
						cp mlx/libmlx.dylib . 

clean:
						$(RM) $(OBJS)
						make clean -C "libft"
						make clean -C "mlx"

fclean:			clean
						$(RM) $(NAME) libmlx.dylib
						make fclean -C "libft"

re:						fclean all

.PHONY:			all clean fclean re
