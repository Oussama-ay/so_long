/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:59:32 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/28 20:00:06 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	open_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		print_error ("Error: Failed to initialize MLX\n");
		close_window (game);
		return ;
	}
	game->win = mlx_new_window(game->mlx, (game->map.columns - 1) * 64,
								game->map.rows * 64, WIN_TITLE);
	if (!game->win)
	{
		print_error ("Error: Failed to create window\n");
		close_window (game);
		return ;
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	_setup(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->sprites.wall = NULL;
	game->sprites.floor = NULL;
	game->sprites.exit_animation = NULL;
	game->sprites.collectible = NULL;
	game->sprites.player_down = NULL;
	game->sprites.player_right = NULL;
	game->sprites.player_left = NULL;
	game->sprites.player_up = NULL;
	game->sprites.boss = NULL;
	game->sprites.exit = NULL;
	game->sprites.exit_open = NULL;
	game->current_frame_coin = 0;
	game->current_frame_player = 0;
	game->current_frame_boss = 0;
	game->current_frame_exit = 0;
	game->finish = 0;
	game->movements = 0;
	game->player_direction = 4;
	game->map.columns = ft_strlen (game->map.grid[0]) + 1;
}

void	delay_ms(long delay_time)
{
	long	start_time;

	start_time = 0;
	while (start_time < delay_time)
		start_time++;
}
