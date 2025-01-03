/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_input_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:35:20 by oayyoub           #+#    #+#             */
/*   Updated: 2025/01/03 08:29:04 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	finish_game(t_game *game, int x)
{
	if (x)
		print_error ("You win nice\n");
	else
		print_error ("You lose\n");
	close_window(game);
	exit (1);
}

static void	ft_player_move(t_game *game, int new_y, int new_x,
		int player_sprite)
{
	int	last_x;
	int	last_y;

	(1) && (last_x = game->player_x, last_y = game->player_y);
	if (game->map.grid[new_y][new_x] == 'E' && game->map.coins == 0)
		finish_game(game, 1);
	else if (game->map.grid[new_y][new_x] == 'B')
		finish_game(game, 0);
	else if ((game->map.grid[new_y][new_x] == '0')
	|| (game->map.grid[new_y][new_x] == 'C'))
	{
		game->map.grid[last_y][last_x] = '0';
		if (game->map.grid[new_y][new_x] == 'C')
			game->map.coins--;
		if (!game->map.coins)
			game->finish = 1;
		game->player_direction = player_sprite;
		(1) && (game->player_x = new_x, game->player_y = new_y);
		game->map.grid[new_y][new_x] = 'P';
		game->movements++;
		_display_counter(game);
		render_map(game);
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Up || keycode == XK_w)
		ft_player_move(game, game->player_y - 1, game->player_x, 1);
	else if (keycode == XK_Left || keycode == XK_a)
		ft_player_move(game, game->player_y, game->player_x - 1, 2);
	else if (keycode == XK_Right || keycode == XK_d)
		ft_player_move(game, game->player_y, game->player_x + 1, 3);
	else if (keycode == XK_Down || keycode == XK_s)
		ft_player_move(game, game->player_y + 1, game->player_x, 4);
	else if (keycode == XK_Escape || keycode == XK_q)
		close_window(game);
	return (0);
}

void	draw_tile(t_game *game, int x, int y, void *sprite)
{
	if (game->map.grid[y][x] == 'C' && game->sprites.collectible)
		draw_collectible(game, x, y);
	else if (game->map.grid[y][x] == 'P')
		draw_player(game, x, y);
	else if (game->map.grid[y][x] == 'B' && game->sprites.boss)
		draw_boss(game, x, y);
	else if (game->map.grid[y][x] == 'E' && game->finish)
		draw_exit(game, x, y);
	else if (sprite)
		mlx_put_image_to_window(game->mlx, game->win, sprite, x * 64, y * 64);
}

int	render_map(t_game *game)
{
	t_cord	cord;

	cord.y = 0;
	while (cord.y < game->map.rows)
	{
		cord.x = 0;
		while (cord.x < game->map.columns)
		{
			if (game->map.grid[cord.y][cord.x] == '1')
				draw_tile(game, cord.x, cord.y, game->sprites.wall);
			else if (game->map.grid[cord.y][cord.x] == 'C')
				draw_tile(game, cord.x, cord.y, NULL);
			else if (game->map.grid[cord.y][cord.x] == 'E')
				draw_tile(game, cord.x, cord.y, game->sprites.exit);
			else if (game->map.grid[cord.y][cord.x] == 'P')
				draw_tile(game, cord.x, cord.y, NULL);
			else if (game->map.grid[cord.y][cord.x] == 'B')
				draw_tile(game, cord.x, cord.y, NULL);
			else
				draw_tile(game, cord.x, cord.y, game->sprites.floor);
			cord.x++;
		}
		cord.y++;
	}
	return (_display_counter(game));
}
