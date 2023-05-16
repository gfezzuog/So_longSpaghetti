# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfezzuog <gfezzuog@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 17:28:37 by gfezzuog          #+#    #+#              #
#    Updated: 2022/11/21 17:42:46 by gfezzuog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c \
	  ft_matrix.c \
	  ft_mapchecker.c \
	  ft_countinglen.c \
	  ft_mapchecker2.c \
	  ft_movement_checker.c \
	  ft_printing.c \
	  ft_movements.c \
	  ft_movements2.c \
	  ft_createblack.c \
	  ft_movements2p2.c \

HDRS = libft.h

OBJ = $(SRC:.c=.o)

RM = rm -f

%.o: %.c
	gcc -g -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	make -C ./libft/ all
	make -C ./mlx/
	gcc $(OBJ) -L./libft/ -lft -L./mlx -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

ex: $(NAME)
	./$(NAME) maps/map2.ber
	make clean./
	make -C ./mlx/ clean

clean:
	${RM} $(OBJ)
	make -C ./libft/ clean
	make -C ./mlx/ clean

fclean: clean
	${RM} $(NAME) ${OBJ}
	make -C ./libft/ fclean
	make -C ./mlx/ clean

re: $(NAME)

.PHONY: all clean fclean re