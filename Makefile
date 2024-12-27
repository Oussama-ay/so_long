# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 21:29:09 by oayyoub           #+#    #+#              #
#    Updated: 2024/12/27 09:20:26 by oayyoub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
SRC =	so_long.c setup_game.c free_memory.c handel_input_output.c handel_input_output_2.c\
		get_next_line.c get_next_line_utils.c free_memory.c\
		read_the_map.c setup_game.c setup_sprites_1.c setup_sprites_2.c
MANDATORY = check_errors.c
BONUS = check_errors_bonus.c
OBJ = $(SRC:.c=.o) $(MANDATORY:.c=.o)
OBJ_BONUS = $(SRC:.c=.o) $(BONUS:.c=.o)
LIBS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext
INCLUDES = -Iincludes
LIB_NAME = lib$(NAME).a

all: $(NAME)

$(NAME): $(LIB_NAME)
	$(CC) -o $(NAME) $(LIB_NAME) $(LIBS)

$(LIB_NAME): $(OBJ)
	ar rcs $(LIB_NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
