# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkyeki <minkyeki@42SEOUL.KR>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 09:58:56 by minkyeki          #+#    #+#              #
#    Updated: 2022/02/22 08:59:48 by minkyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
HEADER = includes
SRCS = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c ./srcs/ft_swap.c
OBJS = ${SRCS:.c=.o}

.PHONY : clean fclean re 

all : ${NAME}
	
${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}
	ranlib ${NAME}

.c.o :
	${CC} ${CFLAGS} -c $< -o $@ -I${HEADER}

clean :
	rm -f ${OBJS} 

fclean : clean
	rm -f ${NAME} 

re : fclean all
