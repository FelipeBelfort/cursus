# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelfort <fbelfort@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 18:21:34 by FelipeBelfo       #+#    #+#              #
#    Updated: 2023/03/11 15:32:30 by fbelfort         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

GCC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

SRC				=	main.c parsing.c error.c

OBJS_DIR		=	objs/

OBJ				=	$(addprefix $(OBJS_DIR), $(SRC:.c=.o))

RM				=	rm -fr

HEADER			=	$(NAME).h

LIBFT			=	libft

MLX				=	mlx

MLX_PATH		=	minilibx-linux

LIBFT_A			=	$(LIBFT)/$(LIBFT).a

MLX_A			=	minilibx-linux/lib$(MLX).a

LIB_FLAG		=	-L$(LIBFT) -L$(MLX_PATH) -lft -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

EXTRA_LIBVPATH	=

$(OBJS_DIR)%.o	: 	%.c $(HEADER) $(LIBFT_A) $(MLX_A)
			$(GCC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all				:	$(NAME)

$(NAME)			:  $(OBJS_DIR) $(OBJ) $(OBJ_MAIN) Makefile
			$(GCC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LIB_FLAG)

$(LIBFT_A)		:	FORCE
				$(MAKE) -C $(LIBFT)

$(MLX_A)		:	FORCE
				$(MAKE) -C $(MLX_PATH)

FORCE			:

$(OBJS_DIR)		:
			mkdir -p $(OBJS_DIR)

clean			:
			$(MAKE) -C $(LIBFT) clean
			$(RM) $(OBJS_DIR)

fclean			:	clean
			$(RM) $(NAME) $(LIBFT)/$(LIBFT).a

re				:	fclean all

.PHONY			:	all clean fclean re FORCE
