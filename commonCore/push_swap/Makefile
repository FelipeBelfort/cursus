# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 18:21:34 by FelipeBelfo       #+#    #+#              #
#    Updated: 2023/01/30 17:52:07 by fbelfort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

NAME_BONUS		=	checker

GCC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

SRC_MAIN		=	main.c

SRC				=	bool_tests.c cost_utils_1.c cost_utils_2.c free.c \
			ft_error.c parsing.c sort.c stack_info.c \
			stack_manip.c stack_op_utils1.c stack_op_utils2.c \
			stack_operations.c
			
OBJS_DIR		=	objs/

GNL				=	get_next_line

GNL_FLAG		=	-L$(GNL) -l$(GNL)

CHECKER			=	checker.c

OBJ_CHECKER		=	$(addprefix $(OBJS_DIR), $(CHECKER:.c=.o))

OBJ				=	$(addprefix $(OBJS_DIR), $(SRC:.c=.o))

OBJ_MAIN		=	$(addprefix $(OBJS_DIR), $(SRC_MAIN:.c=.o))

RM				=	rm -fr

HEADER			=	push_swap.h 

LIBFT			=	libft

LIBFT_FLAG		=	-L$(LIBFT) -lft

$(OBJS_DIR)%.o	: 	%.c $(HEADER)
			$(GCC) $(CFLAGS) -I. -c $< -o $@ 

all				:	$(NAME)

$(NAME)			:	$(OBJS_DIR) $(LIBFT) $(OBJ) $(OBJ_MAIN) 
			$(MAKE) -C $(LIBFT)
			$(GCC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LIBFT_FLAG)

$(OBJS_DIR)		:
			mkdir $(OBJS_DIR)

bonus			: $(NAME_BONUS)

$(NAME_BONUS)	:	$(OBJS_DIR) $(LIBFT) $(OBJ) $(OBJ_CHECKER)
				$(MAKE) -C $(LIBFT)
				$(MAKE) -C $(GNL)
				$(GCC) -g3 -o $(NAME_BONUS) $(OBJ) $(OBJ_CHECKER) $(LIBFT_FLAG) $(GNL_FLAG)

duo				: $(NAME) $(NAME_BONUS)

clean			:
			$(MAKE) -C $(LIBFT) clean
			$(MAKE) -C $(GNL) clean
			$(RM) $(OBJS_DIR)

fclean			:	clean
			$(RM) $(NAME) $(LIBFT)/$(LIBFT).a $(NAME_BONUS) $(GNL)/lib$(GNL).a

re				:	fclean all

.PHONY			:	all clean fclean re