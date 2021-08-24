# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/06 19:55:06 by hadufer           #+#    #+#              #
#    Updated: 2021/08/19 23:58:02 by hadufer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= $(wildcard *.c)

OBJS	= ${SRCS:.c=.o}

HEADER	= includes

CC		= gcc
RM		= rm -f
AR		= ar rcs

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			${CC} -c ${CFLAGS} -o $@ $<

${NAME}: all


all:	${OBJS}
			$(AR) ${NAME} ${OBJS}

libft:
	$(MAKE) -C ./Libft bonus

debug: libft
			gcc *.c -L./Libft -l:libft.a -I./Libft -g

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re ${NAME} libft
