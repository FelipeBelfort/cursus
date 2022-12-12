# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 17:05:37 by fbelfort          #+#    #+#              #
#    Updated: 2022/12/08 14:45:31 by fbelfort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

GCC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

SRC		=	ft_printf.c ft_printf_utils.c ft_parsechar.c

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

HEADER	=	ft_printf.h

%.o		: 	%.c $(HEADER) Makefile
			$(GCC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

all		:	$(NAME)

$(NAME)	:	$(OBJ) 
			ar rcs $(NAME) $(OBJ)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re