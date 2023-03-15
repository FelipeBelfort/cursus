# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 18:21:34 by FelipeBelfo       #+#    #+#              #
#    Updated: 2023/03/15 16:57:14 by FelipeBelfo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

GCC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

SRC				=	main.c parsing.c endgame.c \
					display.c ft_free.c item_utils.c \
					bool.c key_press.c create_map.c

OBJS_DIR		=	objs/

OBJ				=	$(addprefix $(OBJS_DIR), $(SRC:.c=.o))

RM				=	rm -fr

HEADER			=	includes/$(NAME).h

LIBFT			=	libft

MLX				=	mlx

LIBFT_A			=	$(LIBFT)/$(LIBFT).a

MLX_A			=	$(MLX_PATH)/lib$(MLX).a

UNAME			:=	$(shell uname)

ifeq ($(UNAME), Darwin)
	DEFINE		=	-D K_ESC=53 -D K_UP=126 -D K_DOWN=125 -D K_LEFT=123 -D K_RIGHT=124 -D K_W=13 -D K_S=1 -D K_A=0 -D K_D=2
	MLX_PATH	=	minilibx_opengl
	LIB_FLAG	=	-L$(LIBFT) -L$(MLX_PATH) -lft -lmlx -framework OpenGL -framework AppKit
else
	DEFINE		=	-D K_ESC=65307 -D K_UP=65362 -D K_DOWN=65364 -D K_LEFT=65361 -D K_RIGHT=65363 -D K_W=119 -D K_S=115 -D K_A=97 -D K_D=100
	MLX_PATH	=	minilibx-linux
	LIB_FLAG	=	-L$(LIBFT) -L$(MLX_PATH) -lft -lmlx_Linux -L/usr/lib -lm -lXext -lX11 -lz
endif

$(OBJS_DIR)%.o	: 	%.c $(HEADER) $(LIBFT_A) $(MLX_A)
			$(GCC) $(CFLAGS) $(DEFINE) -I/usr/include -Imlx -O3 -c $< -o $@

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
