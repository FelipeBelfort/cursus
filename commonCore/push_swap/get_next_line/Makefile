# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 18:21:34 by FelipeBelfo       #+#    #+#              #
#    Updated: 2023/01/30 15:27:35 by fbelfort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libget_next_line.a

GCC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SRC		=	get_next_line_utils.c get_next_line.c

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

HEADER	=	get_next_line.h

%.o		: 	%.c $(HEADER)
			$(GCC) $(CFLAGS) -I. -c $< -o $@ 

all		:	$(NAME)

$(NAME)	:	$(OBJ_B) $(OBJ)
			@ar rcs $(NAME) $(OBJ)
			
clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re