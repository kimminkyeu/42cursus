
# .SUFFIXEX 를 넣으니까 테스터에서 NAME을 인식한다. 왜 그럴까?
# .SUFFIXEX 의 역할이 대체 뭘까?
.SUFFIXEX : .c.o
NAME = libft.a


# TODO : 리링크가 도대체 뭐여? 어덯게 해야 리링크가 됨?

CC = gcc
CFLAGS = -Werror -Wextra -Wall

# makefile wildcard 사용법
SRCS = ${wildcard *.c}
OBJS = ${SRCS:.c=.o}

# (0) create library
# check : 헤더 인클루드를 꼭 해줘야 하나? 해보니 굳이 안해줘도 될 듯 한데?
.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

# (1) make object files for lib

# Do i nead phony?

# delete all objs
clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
#
#
# rule ${NAME} 을 못찾아서 다른 깃허브 코드를 봄. 이건 왜 되지?
# .SUFFIXEX : .c .o
# NAME = libft.a
# CC = gcc
# AFLAGS = rc
# CFLAGS = -Wall -Wextra -Werror
# SRCS = *.c
# OBJECTS = $(SRCS:.c=.o)
#
# all : $(NAME)
#
# clean :
#     rm -rf $(OBJECTS)
# fclean : clean
#     rm -rf $(NAME)
# re : fclean all
#
# $(NAME) : $(OBJECTS)
#     ar $(AFLAGS) $@ $?
# %.o : %.c
#     $(CC) $(CFLAGS) -c $?
# .PHONY : all clean fclean re
