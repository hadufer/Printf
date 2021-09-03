# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/06 19:55:06 by hadufer           #+#    #+#              #
#    Updated: 2021/09/03 22:35:29 by hadufer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	=	ft_printf.c\
			flags.c\
			print_ascii.c\
			print_signed.c\
			print_unsigned.c\


OBJS	= ${SRCS:.c=.o}

HEADER	= includes

CC		= gcc
RM		= rm -f
AR		= ar rcs

CFLAGS = -Wall -Wextra -Werror

%.o: %.c
			${CC} -c ${CFLAGS} -I./Libft -o $@ $<

${NAME}: all


all:	libft ${OBJS}
			$(AR) ${NAME} ${OBJS}

libft:
	$(MAKE) -C ./Libft bonus

clean:
		$(MAKE) -C ./Libft clean
		${RM} ${OBJS}

fclean:	clean
		$(MAKE) -C ./Libft fclean
		${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re ${NAME} libft
