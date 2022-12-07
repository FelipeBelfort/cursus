# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 17:05:37 by fbelfort          #+#    #+#              #
#    Updated: 2022/12/06 21:45:08 by FelipeBelfo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

GCC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

SRC		=	ft_printf.c ft_printf_utils.c ft_parsechar.c ft_format_ptr.c

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

HEADER	=	ft_printf.h

%.o		: 	%.c $(HEADER)
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