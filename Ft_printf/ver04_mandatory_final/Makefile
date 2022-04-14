# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 10:09:31 by minkyeki          #+#    #+#              #
#    Updated: 2022/04/14 10:09:33 by minkyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables
NAME		= libftprintf.a

# -I option으로 헤더의 위치가 바뀌더라도 .c파일 내부에서 경로를 바꿀 필요 없음. 
INCLUDE		= include
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I
RM			= rm -f
AR			= ar rcs

#Sources
SRC_FILES	=	ft_printf ft_vprintf \
				ft_printf_parse \
				ft_printf_info \
				ft_printf_spec1 ft_printf_spec2 \
				ft_printf_hex \

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		=	create_dir

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFT)
			cp libft/libft.a .
			mv libft.a $(NAME)
			$(AR) $(NAME) $(OBJ)

# https://stackoverflow.com/questions/12299369/what-does-and-the-pipe-symbol-in-makefile-stand-for
# Pipe : order-only prerequisite
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			$(RM) -rf $(OBJ_DIR)
			make clean -C $(LIBFT)

fclean:		clean
			$(RM) -f $(NAME)
			$(RM) -f $(LIBFT)/libft.a

re:			fclean all

.PHONY:		all clean fclean re
