# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 10:56:10 by minkyeki          #+#    #+#              #
#    Updated: 2022/06/18 16:05:32 by minkyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
CFLAGS			= -Werror -Wextra -Wall

# NOTE: Add souce files here!
# ==========================================
SRC_FILES			= mandatory check_input \
					  stack stack2 \
					  command command_utils operation operation2 helper \
					  sort_main sort_utils \
					  sort_merge sort_merge2 \
					  sort_divide sort_divide2

SRC_FILES_BONUS		= bonus bonus_utils bonus_utils2 check_input \
					  stack stack2 \
					  command command_utils operation operation2 helper \
					  sort_main sort_utils \
					  sort_merge sort_merge2 \
					  sort_divide sort_divide2
# ==========================================

LIBFT		= libft
RM			= rm -f

SRC 			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJ_MANDATORY	= $(OBJ)

SRC_BONUS 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES_BONUS)))
OBJ_BONUS 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES_BONUS)))

SRC_DIR		= 
OBJ_DIR		= obj/

NAME_MANDATORY	= push_swap
NAME_BONUS		= checker

# for bonus
ifdef BONUS
	NAME = $(NAME_BONUS)
else
	NAME = $(NAME_MANDATORY)
endif

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
	@make bonus -C $(LIBFT)
	@mv libft/libft.a ./$(OBJ_DIR)
	@$(CC) $(CFLAGS) $^ $(OBJ_DIR)libft.a -o $@
ifdef BONUS
	@echo "$(YELLOW)===============================================$(DEF_COLOR)"
	@echo "$(YELLOW)|      Push_Swap bonus compile finished.      |$(DEF_COLOR)"
	@echo "$(YELLOW)===============================================$(DEF_COLOR)"
else
	@echo "$(YELLOW)===============================================$(DEF_COLOR)"
	@echo "$(YELLOW)|    Push_Swap mandatory compile finished.    |$(DEF_COLOR)"
	@echo "$(YELLOW)===============================================$(DEF_COLOR)"
endif

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_MKDIR)
	@$(CC) $(CFLAGS) -c $^ -o $@
	@echo "$(YELLOW)Compiling... \t$< $(DEF_COLOR)"

$(OBJ_MKDIR):
	@mkdir -p $(OBJ_DIR)

bonus:
	@make BONUS=1

clean:
	@$(RM) -rf libft.a
	@make fclean -C $(LIBFT)
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(BLUE)Push_Swap obj files has been deleted.$(DEF_COLOR)"

fclean:		clean
	@$(RM) -f $(NAME) $(NAME_BONUS)
	@echo "$(BLUE)Push_Swap archive files has been deleted.$(DEF_COLOR)"

re:			fclean all
	@echo "$(GREEN)Cleaned and rebuilt Push_Swap.$(DEF_COLOR)"

.PHONY:		all bonus clean fclean re
