# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 18:21:34 by FelipeBelfo       #+#    #+#              #
#    Updated: 2023/01/27 19:03:04 by fbelfort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

GCC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	libft.a

OBJS_DIR=	objs

SRC		=	bool_tests.c cost_utils_1.c cost_utils_2.c \
			free.c ft_error.c main.c parsing.c sort.c stack_info.c \
			stack_manip.c stack_op_utils1.c stack_op_utils2.c stack_operations.c

OBJ		=	$(SRC:%.c=$(OBJS_DIR)/%.o)

RM		=	rm -f

HEADER	=	push_swap.h

VPATH = $(OBJS_DIR)

%.o		: 	%.c $(HEADER) $(OBJS_DIR)
			$(GCC) $(CFLAGS) -I. -c $< -o $(OBJS_DIR)/$@ 

all		:	$(NAME) 

$(OBJS_DIR)	:	
				mkdir -p $(OBJS_DIR)

$(NAME)	:	$(OBJ) 
			# $(MAKE) -C libft/ all
			$(GCC) -o $(NAME) $< $(LIBFT)

clean	:	
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re