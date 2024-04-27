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

SERVER_SRC		=	server.c
CLIENT_SRC		=	client.c
42COLLECTION	=	./42_collection/42collection.a

SERVER_OBJ	=	$(SERVER_SRC:.c=.o)
CLIENT_OBJ	=	$(CLIENT_SRC:.c=.o)

RM	=	rm -rf
CC	=	gcc
CFLAGS	= -Wall -Wextra -Werror

all:	client server

$(42COLLECTION):
	@make -s -C ./42_collection

client: $(CLIENT_OBJ) $(42COLLECTION)
	@$(CC) $(CFLAGS) -fsanitize=address $(42COLLECTION) $(CLIENT_SRC) -o client

server: $(SERVER_OBJ) $(42COLLECTION)
	@$(CC) $(CFLAGS) $(42COLLECTION) $(SERVER_OBJ) -o server

clean:
	@make clean -C ./42_collection
	@$(RM) $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	@make fclean -C ./42_collection
	@$(RM) server client

