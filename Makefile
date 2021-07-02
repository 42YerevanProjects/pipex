NAME = pipex

SRCS = main.c utils.c
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}
	@${RM} ${OBJS}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
