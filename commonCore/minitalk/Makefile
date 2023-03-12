# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: FelipeBelfort <FelipeBelfort@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 18:21:34 by FelipeBelfo       #+#    #+#              #
#    Updated: 2023/03/11 20:38:11 by FelipeBelfo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minitalk

CLIENT			=	client

SERVER			=	server

GCC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

SRC_CLIENT		=	client.c

SRC_SERVER		=	server.c

OBJ_CLIENT		=	$(OBJS_DIR)client.o

OBJ_SERVER		=	$(OBJS_DIR)server.o

OBJS_DIR		=	objs/

RM				=	rm -fr

HEADER			=	minitalk.h

LIBFT			=	libft

LIBFT_A			=	$(LIBFT)/$(LIBFT).a

LIB_FLAG		=	-L$(LIBFT) -lft

$(OBJS_DIR)%.o	: 	%.c $(HEADER) $(LIBFT_A) $(OBJS_DIR)
			$(GCC) $(CFLAGS) -c $< -o $@

all				:	$(NAME)

$(NAME)			:	$(CLIENT) $(SERVER)

$(SERVER)		:	$(OBJ_SERVER) Makefile
			$(GCC) -o $(SERVER) $(OBJ_SERVER) $(LIB_FLAG)

$(CLIENT)		:	$(OBJ_CLIENT) Makefile
			$(GCC) -o $(CLIENT) $(OBJ_CLIENT) $(LIB_FLAG)

$(LIBFT_A)		:	FORCE
				$(MAKE) -C $(LIBFT)

FORCE			:

$(OBJS_DIR)		:
			mkdir -p $(OBJS_DIR)

clean			:
			$(MAKE) -C $(LIBFT) clean
			$(RM) $(OBJS_DIR)

fclean			:	clean
			$(RM) $(NAME) $(LIBFT)/$(LIBFT).a $(CLIENT) $(SERVER)

re				:	fclean all

.PHONY			:	all clean fclean re FORCE
