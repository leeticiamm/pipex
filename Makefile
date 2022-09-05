NAME = pipex

SRCS = pipex.c ft_path.c ft_children.c

OBJS = ${SRCS:.c=.o}

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

PRINTF = ./ft_printf/libftprintf.a

$(NAME): ${OBJS}
		make -C ./ft_printf
		cc $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)
		

all:	${NAME}

clean:
		${RM} ${OBJS}
		make clean -C ./ft_printf

fclean:	clean
		${RM} ${NAME}
		make fclean -C ./ft_printf

re:		fclean all
		make re -C ./ft_printf

.PHONY: all clean fclean re

