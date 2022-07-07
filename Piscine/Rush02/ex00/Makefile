# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjeki2 <minjeki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/22 16:42:40 by odelvaux          #+#    #+#              #
#    Updated: 2022/02/20 18:56:39 by minjeki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OUT = rush-02
SRC = main.c tool.c tool2.c error.c convert.c convert2.c file_read.c
OBJ = $(SRC:.c=.o)

CC = gcc
CCFLAGS = -Wall -Werror -Wextra

.PHONY: all
all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(OUT)

%.o: %.c mylib.h
	$(CC) $(CCFLAGS) -c $< -o $@

.PHONY: fclean
fclean:
	rm -f $(OBJ) $(OUT)
