/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:34:34 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/26 09:36:46 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <X11/keysym.h>

#define WIN_TITLE "GTA VI"

typedef struct s_map
{
	char		**grid;
	int			columns;
	int			rows;
	int			coins;
}	t_map;

typedef struct s_sprites
{
	void	*wall;
	void	*floor;
	void	**collectible;
	void	*exit;
	void	**exit_animation;
	void	*exit_open;
	void	**player;
	void	**player_right;
	void	**player_left;
	void	**player_up;
	void	**attack;
	void	**boss;
	void	**boy_lose;
	int		width;
	int		height;
}	t_sprites;

typedef struct s_game
{
	void        *mlx;
	void        *win;
	t_map       map;
	t_sprites   sprites;
	int         current_frame_coin;
	int			current_frame_player;
	int			current_frame_boss;
	int			current_frame_exit;
	int			current_frame_move;
	int			movements;
	int			player_direction;
	int			player_x;
	int			player_y;
	int			attack;
	int			finish;
}	t_game;

void	free_map(t_map *mape);
void	print_error(char *str);
char	*get_next_line(int fd);
void	preparation (t_game *game);
int		close_window(t_game *game);
void	_setup(t_game *game);
int		load_sprites(t_game *game);
char	*ft_strjoin(char *s1, char *s2);

#endif
