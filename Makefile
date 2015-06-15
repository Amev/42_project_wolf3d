# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vame <vame@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/12 15:09:58 by vame              #+#    #+#              #
#    Updated: 2015/06/15 14:07:36 by vame             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

CFLAGS = -Werror -Wextra -Wall -I libft/includes/

LIBX = -lm -L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

SRC =	./wolf_main.c \
		./wolf_key_hook.c

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
