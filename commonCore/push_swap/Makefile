# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 18:21:34 by FelipeBelfo       #+#    #+#              #
#    Updated: 2023/01/31 20:47:46 by FelipeBelfo      ###   ########.fr        #
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

CHECKER			=	checker_bonus.c

OBJ_CHECKER		=	$(addprefix $(OBJS_DIR), $(CHECKER:.c=.o))

OBJ				=	$(addprefix $(OBJS_DIR), $(SRC:.c=.o))

OBJ_MAIN		=	$(addprefix $(OBJS_DIR), $(SRC_MAIN:.c=.o))

RM				=	rm -fr

HEADER			=	push_swap.h 

LIBFT			=	libft

LIBFT_A			=	$(LIBFT)/$(LIBFT).a

LIBFT_FLAG		=	-L$(LIBFT) -lft

EXTRA_LIBVPATH	= 

$(OBJS_DIR)%.o	: 	%.c $(HEADER) $(LIBFT_A) 
			$(GCC) $(CFLAGS) -I. -c $< -o $@ 

all				:	$(NAME) 

$(NAME)			:  $(OBJS_DIR) $(OBJ) $(OBJ_MAIN) Makefile
			$(GCC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LIBFT_FLAG)

$(LIBFT_A)		:	FORCE
				$(MAKE) -C $(LIBFT)

FORCE			:

$(OBJS_DIR)		:
			mkdir -p $(OBJS_DIR)

bonus			: $(NAME_BONUS)

$(NAME_BONUS)	:	$(OBJS_DIR) $(OBJ) $(OBJ_CHECKER) Makefile
				$(GCC) -o $(NAME_BONUS) $(OBJ) $(OBJ_CHECKER) $(LIBFT_FLAG)

duo				: $(NAME) $(NAME_BONUS)

clean			:
			$(MAKE) -C $(LIBFT) clean
			$(RM) $(OBJS_DIR)

fclean			:	clean
			$(RM) $(NAME) $(LIBFT)/$(LIBFT).a $(NAME_BONUS)

re				:	fclean all

.PHONY			:	all clean fclean re