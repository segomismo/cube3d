# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ruben <ruben@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 17:20:06 by ruben             #+#    #+#              #
#    Updated: 2021/05/13 12:35:08 by ruben            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

SRC = check_errors.c	\
	  description_read.c	\
	  errors.c			\
	  ft_atoi.c			\
	  funciones.c		\
	  get_next_line.c	\
	  get_next_line_utils.c	\
	  main.c			\
	  map_errors.c		\
	  map_read.c		\

LIB = minilibx-$(OS)/libmlx.a

OS  = $(shell uname -s)

OBJ = $(SRC:.c=.o)

ifeq ($(OS), Darwin)
    MINILIB = -framework OpenGL -framework AppKit
else
    MINILIB = -lm -lz -lXext -lX11 -L ./minilibx-Linux -pthread
endif

ifeq ($(OS), Darwin)
    SYSTEM = -D MAC_SYSTEM=1
else
    SYSTEM = -D LINUX_SYSTEM=1
endif

%.o: %.c
	gcc $(SYSTEM) -Wall -Werror -Wextra -g -I /usr/local/include -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C minilibx-$(OS)/
		gcc -Wall -Werror -Wextra -g $(OBJ) -I /usr/local/include $(LIB) $(MINILIB) -o $(NAME)

clean:
		make -C minilibx-$(OS) clean
		rm -rf $(OBJ)

fclean: clean
		make -C minilibx-$(OS) clean
		rm -rf $(NAME)

re : fclean all
