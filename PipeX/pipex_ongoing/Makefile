# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 14:06:52 by minkyeki          #+#    #+#              #
#    Updated: 2022/05/15 21:57:04 by minkyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= pipex
CC				= gcc
CFLAGS			= -Werror -Wextra -Wall
CFLAGS_DEBUG	= -Werror -Wextra -Wall -g

# NOTE: Add souce files here!
# ==========================================
SRC_FILES			= pipex pipex_utils

SRC_FILES_BONUS		= pipex_bonus pipex_utils
# ==========================================

LIBFT		= libft
INCLUDE		= include/
RM			= rm -f

SRC 			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJ_MANDATORY	= $(OBJ)

SRC_BONUS 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES_BONUS)))
OBJ_BONUS 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_BONUS)))

SRC_DIR		= src/
OBJ_DIR		= obj/

# Keep makefile from relink
ifdef BONUS
     OBJ_RESULT = $(OBJ_BONUS)
else
     OBJ_RESULT = $(OBJ_MANDATORY)
endif

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

OBJ_MKDIR		=	create_dir

all: $(NAME)

$(NAME): $(OBJ_RESULT)
	@make -C $(LIBFT)
	@mv libft/libft.a ./$(OBJ_DIR)
	$(CC) $(CFLAGS) $(OBJ_DIR)libft.a $^ -o $@
ifdef BONUS
	@echo "$(BLUE)============================================$(DEF_COLOR)"
	@echo "$(BLUE)|      Pipe-X bonus compile finished.      |$(DEF_COLOR)"
	@echo "$(BLUE)============================================$(DEF_COLOR)"
else
	@echo "$(BLUE)============================================$(DEF_COLOR)"
	@echo "$(BLUE)|    Pipe-X mandatory compile finished.    |$(DEF_COLOR)"
	@echo "$(BLUE)============================================$(DEF_COLOR)"
endif

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_MKDIR)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $^ -o $@
	@echo "$(YELLOW)Compiling... \t$< $(DEF_COLOR)"

$(OBJ_MKDIR):
	@mkdir -p $(OBJ_DIR)

bonus:
	make BONUS=1

clean:
	@$(RM) -rf libft.a
	@make fclean -C $(LIBFT)
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(BLUE)Pipe-X obj files has been deleted.$(DEF_COLOR)"

fclean:		clean
	@$(RM) -f $(NAME)
	@echo "$(BLUE)Pipe-X archive files has been deleted.$(DEF_COLOR)"

re:			fclean all
	@echo "$(GREEN)Cleaned and rebuilt Pipe-X.$(DEF_COLOR)"

.PHONY:		all bonus clean fclean re
