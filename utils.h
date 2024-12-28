/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:02:16 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/28 19:56:27 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <X11/keysym.h>

#define WIN_TITLE "so_long"

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
	void	*exit;
	void	*exit_open;
	void	**exit_animation;
	void	**collectible;
	void	**player_down;
	void	**player_right;
	void	**player_left;
	void	**player_up;
	void	**boss;
	int		width;
	int		height;
}	t_sprites;

typedef struct s_game
{
	void 		*mlx;
	void 		*win;
	t_map		map;
	t_sprites	sprites;
	int         current_frame_coin;
	int			current_frame_player;
	int			current_frame_boss;
	int			current_frame_exit;
	int			player_direction;
	int			movements;
	int			player_x;
	int			player_y;
	int			attack;
	int			finish;
}	t_game;

typedef struct s_cord
{
	int	x;
	int	y;
}	t_cord;

typedef struct s_test
{
	int	coins;
	int	exit;
}	t_test;

char	*get_next_line(int fd);
void	print_error(char *str);
void	open_window(t_game *game);
int		close_window(t_game *game);
char	*ft_strjoin(char *s1, char *s2);
int		read_map(char *filename, t_game *game);
void	_setup(t_game *game);
int		ft_strlen(const char *s);
void	free_map(char	**mape, int rows);
int		handle_keypress(int keycode, t_game *game);
void	stream (t_game *game, void **frames, int i, t_cord cord);
int		render_map(t_game *game);
int		player_down(t_game *game);
int		player_right(t_game *game);
int		player_left(t_game *game);
int		player_up(t_game *game);
int		boss(t_game *game);
int		exit_animation(t_game *game);
void	draw_collectible(t_game *game, int x, int y);
void	draw_player(t_game *game, int x, int y);
void	draw_boss(t_game *game, int x, int y);
void	draw_exit(t_game *game, int x, int y);
char	**ft_copy_map(t_game *game);
void	load_sprites(t_game *game);
void	delay_ms(long delay_time);
int		validate_map(t_game *game);
void	_display_counter(t_game *game);

#endif