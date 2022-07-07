NAME = BSQ
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCS = includes
SRCS = srcs/bsq.c srcs/bsq2.c srcs/parser.c srcs/t_array.c srcs/t_map.c
OBJS = ${SRCS:.c=.o}

all : ${NAME}

.c.o:
	${CC} ${CFLAGS} -I ${INCS} -c $^ -o $@

${NAME} : ${OBJS}
	gcc -o $@ ${OBJS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all
