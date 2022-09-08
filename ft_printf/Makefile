NAME = libftprintf.a

SRCS = ft_printf.c

OBJS = ${SRCS:.c=.o}

CC		= cc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		make -C ./libft
		cp ./libft/libft.a $(NAME)
		ar rcs ${NAME} ${OBJS}


all:	${NAME}

clean:
		${RM} ${OBJS}
		make clean -C ./libft

fclean:	clean
		${RM} ${NAME}
		make fclean -C ./libft

re:		fclean all
		make re -C ./libft

.PHONY: all clean fclean re

