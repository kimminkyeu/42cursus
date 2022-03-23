# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 15:31:26 by minkyeki          #+#    #+#              #
#    Updated: 2022/03/18 14:06:59 by minkyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Werror -Wextra -Wall

.c = ${wildcard *.c}
SRCS_BONUS = ${wildcard ft_lst*.c}
SRCS = ${filter-out ${SRCS_BONUS}, ${.c}}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
OBJS = ${SRCS:.c=.o}

all: ${NAME}

mandatory: ${NAME} ${OBJS}

bonus: ${NAME} ${OBJS_BONUS}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	ar rcs $@ $^
	ranlib $@

bonus: ${OBJS_BONUS} 
	ar rcs ${NAME} $^
	ranlib ${NAME}

clean:
	rm -f ${OBJS} ${OBJS_BONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
