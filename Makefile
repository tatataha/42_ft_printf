# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muhcelik <muhcelik@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 19:33:21 by muhcelik          #+#    #+#              #
#    Updated: 2023/01/05 18:18:59 by muhcelik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

SRCS	 	=	ft_printf.c ft_pall.c

OBJS 		= $(SRCS:.c=.o)

CFLAGS 		= -Wall -Werror -Wextra

$(NAME):	$(OBJS)
			ar -rc $(NAME) $(OBJS) 

.o:			.c ft_printf.h
			gcc $(CFLAGS) -o $@ -c $<

all: 		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re bonus