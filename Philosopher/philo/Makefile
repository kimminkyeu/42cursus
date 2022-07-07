# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 13:32:45 by minkyeki          #+#    #+#              #
#    Updated: 2022/07/04 14:07:02 by minkyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
CFLAGS			= -Werror -Wextra -Wall
# CFLAGS			= -Werror -Wextra -Wall -fsanitize=address,undefined

# NOTE: Add souce files here!
# ==========================================
SRC_FILES			= main philo_routine monitor_routine \
					  philo_helper philo_utils philo_routine_action
# ==========================================

RM			= rm -f

SRC 			= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 			= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJ_MANDATORY	= $(OBJ)

SRC_DIR		= 
OBJ_DIR		= obj/

NAME_MANDATORY	= philo

NAME = $(NAME_MANDATORY)
OBJ_RESULT = $(OBJ_MANDATORY)

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
	$(CC) $(CFLAGS) $^ -o $@
	@echo "$(YELLOW)===============================================$(DEF_COLOR)"
	@echo "$(YELLOW)|    Philo mandatory compile finished.        |$(DEF_COLOR)"
	@echo "$(YELLOW)===============================================$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_MKDIR)
	$(CC) $(CFLAGS) -c $^ -o $@
	@echo "$(YELLOW)Compiling... \t$< $(DEF_COLOR)"

$(OBJ_MKDIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -rf $(OBJ_DIR)
	@echo "$(BLUE)Philo obj files has been deleted.$(DEF_COLOR)"

fclean:		clean
	$(RM) -f $(NAME) $(NAME_BONUS)
	@echo "$(BLUE)Philo archive files has been deleted.$(DEF_COLOR)"

re:			fclean all
	@echo "$(GREEN)Cleaned and rebuilt Philo.$(DEF_COLOR)"

.PHONY:		all clean fclean re
