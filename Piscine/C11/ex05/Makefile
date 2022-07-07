SRCS = main.c do_op.c ft_atoi.c ft_putnbr.c ft_putstr.c operator.c
OBJS = ${SRCS:.c=.o} 
NAME = do-op
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}:
	${CC} ${CFLAGS} -o ${NAME} ${SRCS} -Imylib.h

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
