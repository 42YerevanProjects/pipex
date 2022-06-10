# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: shovsepy <marvin@42.fr>                    +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/06/30 16:12:45 by shovsepy          #+#    #+#             #
#   Updated: 2021/06/30 17:02:42 by shovsepy         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME		= libft.a

SRCS		= $(shell find "." -name "*.c" ! -name "ft_lst*.c")
BONUSES 	= $(shell find "." -name "ft_lst*.c")

OBJS		= ${SRCS:.c=.o}
BONUS_OBJS 	= ${BONUSES:.c=.o}

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

AR		= ar csr
RM		= rm -rf

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	@${AR} libft.a ${OBJS}

bonus : ${BONUS_OBJS}
	@${AR} libft.a ${BONUS_OBJS}


all : ${NAME}

clean :
	@${RM} ${OBJS} ${BONUS_OBJS}

fclean : clean
	@${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean bonus re .c.o

