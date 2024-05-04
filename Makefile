# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 13:53:55 by axcastil          #+#    #+#              #
#    Updated: 2024/05/04 16:46:45 by axcastil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRC		=	server.c
CLIENT_SRC		=	client.c
NAME	=	./42_collection/42collection.a

SERVER_OBJ	=	$(SERVER_SRC:.c=.o)
CLIENT_OBJ	=	$(CLIENT_SRC:.c=.o)

RM	=	rm -rf
CC	=	gcc
CFLAGS	= -Wall -Wextra -Werror

all:	client server

$(NAME):
	@make -s -C ./42_collection

client: $(CLIENT_OBJ) $(NAME)
	@$(CC) $(CFLAGS) -fsanitize=address $(NAME) $(CLIENT_SRC) -o client

server: $(SERVER_OBJ) $(NAME)
	@$(CC) $(CFLAGS) $(NAME) $(SERVER_OBJ) -o server

clean:
	@make clean -C ./42_collection
	@$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	@make fclean -C ./42_collection
	@$(RM) server client

re: fclean all

.PHONY: all clean fclean re
