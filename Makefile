NAME = pipex

SRCS = pipex.c 

CC		= cc

RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

PRINTF = ./ft_printf/libftprintf.a

$(NAME):
		make -C ./ft_printf
		cc -o pipex $(FlAGS) -c pipex.c $(PRINTF)
		

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

