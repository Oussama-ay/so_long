# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 21:29:09 by oayyoub           #+#    #+#              #
#    Updated: 2025/01/03 08:19:36 by oayyoub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC =	so_long.c setup_game.c free_memory.c handel_input_output.c handel_input_output_2.c\
		get_next_line.c get_next_line_utils.c read_the_map.c setup_sprites_1.c setup_sprites_2.c
MANDATORY = check_errors.c
BONUS = check_errors_bonus.c
LIBS = -L/home/oayyoub/includes/minilibx-linux -lmlx_Linux -lX11 -lXext
OBJ = $(SRC:.c=.o) $(MANDATORY:.c=.o)
OBJ_BONUS = $(SRC:.c=.o) $(BONUS:.c=.o)

all: check_bonus $(NAME) 

check_bonus:
	@if [ -f check_errors_bonus.o ]; then\
		rm -f check_errors_bonus.o;\
	fi

bonus: .bonus

.bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBS) -o $(NAME)
	@touch .bonus

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS) .bonus

fclean: clean
	rm -f $(NAME)

re: fclean all
