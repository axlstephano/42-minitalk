# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: axcastil <axcastil@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 13:53:55 by axcastil          #+#    #+#              #
#    Updated: 2024/05/04 18:29:18 by axcastil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRC		=	server.c
CLIENT_SRC		=	client.c
42_COLLECTION	=	./42_collection/42collection.a

SERVER_OBJ	=	$(SERVER_SRC:.c=.o)
CLIENT_OBJ	=	$(CLIENT_SRC:.c=.o)

RM	=	rm -rf
CC	=	gcc
CFLAGS	= -Wall -Wextra -Werror

all:	client server

$(42_COLLECTION):
	@make -s -C ./42_collection

client: $(CLIENT_OBJ) $(42_COLLECTION)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) -o client $(42_COLLECTION)

server: $(SERVER_OBJ) $(42_COLLECTION)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) -o server $(42_COLLECTION)

clean:
	@make clean -C ./42_collection
	@$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	@make fclean -C ./42_collection
	@$(RM) server client

re: fclean all

.PHONY: all clean fclean re
