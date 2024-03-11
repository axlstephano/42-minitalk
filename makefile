# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axcastil <axcastil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 13:53:55 by axcastil          #+#    #+#              #
#    Updated: 2023/10/25 18:25:08 by axcastil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

all:			libft

libft:			
				@make -C ./libft

.PHONY:			all clean fclean re bonus