SOURCES =	mlx.c
			

OBJECTS				=	${SOURCES:.c=.o}

NAME = cub3D

CC = gcc
RM = rm -f

CC_FLAGS = -Wall -Wextra -Werror
L_FLAGS = -lmlx -lX11 -lXext -lbsd -lm

.c.o:
	${CC} ${CC_FLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJECTS}
	${CC} -o ${NAME} ${OBJECTS} ${L_FLAGS}

all : ${NAME}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re