# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 12:57:40 by minkyeki          #+#    #+#              #
#    Updated: 2022/05/04 11:37:13 by minkyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Werror -Wextra -Wall -g

# NOTE: Add souce files here!
# ==========================================
SRC_FILES	= fdf \
			  map_parser \
			  engine engine_control1 engine_control2 \
			  camera \
			  control_panel \
			  color1 color2 \
			  matrix1 matrix2 matrix3 matrix4 vector4 \
			  draw_functions1 draw_functions2 draw_functions3 \
# ==========================================

MLX			= mlx_mms
LIBFT		= libft
INCLUDE		= include
RM			= rm -f

SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
SRC_DIR		= src/
OBJ_DIR		= obj/

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

# TODO : change mlx directory when you push to Final repo!
#1) -L[라이브러리 디렉토리] 옵션 : 라이브러리를 찾을 디렉토리를 지정한다.
#2) -l 옵션 : 같이 링크할 라이브러리를 지정한다.

# Linux X11 version (FIXME : 컴파일 $^ 로 변경, libft.a 연결)
# =================================================
# $(NAME): $(OBJ)
#     @make -C $(LIBFT)
#     mv libft/libft.a ./$(OBJ_DIR)
#     @$(CC) $(CFLAGS) $^ $(OBJ_DIR)/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
#     @echo "$(BLUE)==============================================$(DEF_COLOR)"
#     @echo "$(BLUE)|   fdf Linux X11 version compile finished.  |$(DEF_COLOR)"
#     @echo "$(BLUE)==============================================$(DEF_COLOR)"
#
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_MKDIR)
#     @$(CC) -Wall -Wextra -Werror -I/usr/include -I$(INCLUDE) -Imlx_linux -O3 -c $< -o $@
#     @echo "$(YELLOW)Compiling... \t$< $(DEF_COLOR)"
# =================================================

# MacOS openGL version (FIXME : 컴파일 $^ 로 변경, libft.a 연결)
# =================================================
# $(NAME): $(OBJ)
#     @make -C $(LIBFT)
#     @mv libft/libft.a ./$(OBJ_DIR)
#     @$(CC) $< -L mlx -l mlx -framework OpenGL -framework AppKit -o $@
#     @echo "$(BLUE)===========================================$(DEF_COLOR)"
#     @echo "$(BLUE)|   fdf openGL version compile finished.  |$(DEF_COLOR)"
#     @echo "$(BLUE)===========================================$(DEF_COLOR)"
#
# $(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_MKDIR)
#     @$(CC) -Wall -Wextra -Werror -Imlx -I$(INCLUDE) -c $< -o $@
#     @echo "$(YELLOW)Compiling... \t$< $(DEF_COLOR)"
# =================================================

# TODO : $< 는 OBJ의 첫번째 파일 (main) 만 들어간다. 
# main 과 기타 소스파일을 함께 넣으려면 $^를 써야 한다!

# MacOS MMS(Metal) Beta version
# =================================================
$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@mv libft/libft.a ./$(OBJ_DIR)
	@make -C $(MLX)
	@cp $(MLX)/libmlx.dylib .
	@$(CC) $(CFLAGS) $^ $(OBJ_DIR)/libft.a -Lmlx_mms -lmlx -framework Cocoa -framework Metal -framework MetalKit -framework QuartzCore -o $@
	@echo "$(BLUE)============================================$(DEF_COLOR)"
	@echo "$(BLUE)|   fdf mlx-mms version compile finished.  |$(DEF_COLOR)"
	@echo "$(BLUE)============================================$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_MKDIR)
	@$(CC) $(CFLAGS) -Imlx_mms -I$(INCLUDE) -c $^ -o $@
	@echo "$(YELLOW)Compiling... \t$< $(DEF_COLOR)"
# =================================================

$(OBJ_MKDIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -rf libft.a
	@make fclean -C $(LIBFT)
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(BLUE)FDF obj files has been deleted.$(DEF_COLOR)"

fclean:		clean
	@$(RM) -f $(NAME)
	@$(RM) -f libmlx.dylib
	@echo "$(BLUE)FDF archive files has been deleted.$(DEF_COLOR)"

re:			fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything.$(DEF_COLOR)"

.PHONY:		all clean fclean re
