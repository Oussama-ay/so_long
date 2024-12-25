# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 21:29:09 by oayyoub           #+#    #+#              #
#    Updated: 2024/12/24 20:44:14 by oayyoub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc -g
#CFLAGS = -Wall -Wextra -Werror
SRC = so_long.c preparations.c free_memory.c check_errors.c \
		get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)
LIBS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
INCLUDES = -Iincludes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
