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

SRCS 		=	$(shell find . -name "*.c")

OBJS		=	$(SRCS:.c=.o)

NAME 		= 	libft_collection.a

CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus