/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_input_output_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:22:15 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/27 13:50:04 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void delay_ms(int delay_time)
{
	int	start_time;

	start_time = 0;
	while (start_time < delay_time)
		start_time++;
}

void	stream(t_game *game, void **frames, int i, t_cord cord)
{
	if (!frames || !frames[i])
        return;
	mlx_put_image_to_window(game->mlx, game->win, frames[i], cord.x * 64, cord.y * 64);
	delay_ms(90000000);
	i++;
}

void	draw_collectible(t_game *game, int x, int y)
{
	t_cord	cord;

	cord.x = x;
	cord.y = y;
	game->current_frame_coin = (game->current_frame_coin + 1) % 18;
	stream(game, game->sprites.collectible, game->current_frame_coin, cord);
}

void	draw_player(t_game *game, int x, int y)
{
	t_cord	cord;

	cord.x = x;
	cord.y = y;
	game->player_x = x;
	game->player_y = y;
	game->current_frame_player = (game->current_frame_player + 1) % 6;
	if (game->player_direction == 1 && game->sprites.player_up)
		stream(game, game->sprites.player_up, game->current_frame_player, cord);
	else if (game->player_direction == 2 && game->sprites.player_left)
		stream(game, game->sprites.player_left, game->current_frame_player, cord);
	else if (game->player_direction == 3 && game->sprites.player_right)
		stream(game, game->sprites.player_right, game->current_frame_player, cord);
	else if (game->player_direction == 4 && game->sprites.player_down)
		stream(game, game->sprites.player_down, game->current_frame_player, cord);
}

void	draw_boss(t_game *game, int x, int y)
{
	t_cord	cord;

	cord.x = x;
	cord.y = y;
	game->current_frame_boss = (game->current_frame_boss + 1) % 6;
	stream(game, game->sprites.boss, game->current_frame_boss, cord);
}

void	draw_exit(t_game *game, int x, int y)
{
	t_cord	cord;

	cord.x = x;
	cord.y = y;
	game->current_frame_exit++;
	if (game->current_frame_exit < 4 && game->sprites.exit_animation)
		stream(game, game->sprites.exit_animation, game->current_frame_exit, cord);
	else if (game->sprites.exit_open)
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.exit_open, x * 64, y * 64);
}
