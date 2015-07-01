# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vame <vame@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/12 15:09:58 by vame              #+#    #+#              #
#    Updated: 2015/07/01 09:51:14 by vame             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CFLAGS = -Werror -Wextra -Wall -I libft/includes/

LIBX = -lm -L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

SRC =	./wolf_main.c \
		./wolf_draw.c \
		./wolf_expose.c \
		./wolf_key_hook.c \
		./wolf_create_map.c

BINAIRE = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BINAIRE) $(INC)
		@make -C libft/
		@make -C minilibx_macos/
		cc -g -o $(NAME) $(BINAIRE) $(LIBX)

lib :
		@make -C libft/ fclean
		@make -C libft/

clean:
		rm -f $(BINAIRE)
		@make -C libft/ clean

fclean: clean
		rm -f $(NAME)
		@make -C libft/ fclean

re: fclean all

.PHONY: all lib clean fclean re
