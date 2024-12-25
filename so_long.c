/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:34:02 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/25 20:20:11 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void delay_ms(int delay_time)
{
	int	start_time;

	start_time = 0;
	while (start_time < delay_time)
		start_time++;
}

void draw_tile(t_game *game, int x, int y, void *sprite)
{
	int i;

	i = 0;
	if (game->map.grid[y][x] == 'C' && game->sprites.collectible)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.collectible[game->current_frame_coin], x * 64, y * 64);
		game->current_frame_coin = (game->current_frame_coin + 1) % 18;
		delay_ms(90000000);
	}
	else if (game->map.grid[y][x] == 'P' && game->sprites.player)
	{
		game->player_x = x;
		game->player_y = y;
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.player[game->current_frame_player], x * 64, y * 64);
		game->current_frame_player = (game->current_frame_player + 1) % 6;
		delay_ms(90000000);
	}
	else if (game->map.grid[y][x] == 'B' && game->sprites.boss)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.boss[game->current_frame_boss], x * 64, y * 64);
		game->current_frame_boss = (game->current_frame_boss + 1) % 6;
		delay_ms(20000000);
	}
	else if (game->map.grid[y][x] == 'E' && game->finish && game->current_frame_exit < 4)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->sprites.exit_animation[game->current_frame_exit], x * 64, y * 64);
		game->current_frame_exit = (game->current_frame_exit + 1);
		delay_ms(900000000);
	}
	else if (game->finish && game->map.grid[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->sprites.exit_open, x * 64, y * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, sprite, x * 64, y * 64);
}

int render_map(t_game *game)
{
	int x;
	int y;

	mlx_clear_window(game->mlx, game->win);
	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.grid[y][x] == '1')
				draw_tile(game, x, y, game->sprites.wall);
			else if (game->map.grid[y][x] == 'C')
				draw_tile(game, x, y, NULL);
			else if (game->map.grid[y][x] == 'E')
				draw_tile(game, x, y, game->sprites.exit);
			else if (game->map.grid[y][x] == 'P')
				draw_tile(game, x, y, NULL);
			else if (game->map.grid[y][x] == 'B')
				draw_tile(game, x, y, NULL);
			else
				draw_tile(game, x, y, game->sprites.floor);
			x++;
		}
		y++;
	}
	return (0);
}


void	ft_player_move(t_game *game, int new_y, int new_x, int player_sprite)
{
	int	last_x;
	int	last_y;

	last_x = game->player_x;
	last_y = game->player_y;
	// if (game->map.grid[new_y][new_x] == 'E' && game->map.coins == 0)
	// 	ft_victory(game);
	if ((game->map.grid[new_y][new_x] == '0')
	|| (game->map.grid[new_y][new_x] == 'C'))
	{
		game->map.grid[last_y][last_x] = '0';
		if (game->map.grid[new_y][new_x] == 'C')
			game->map.coins--;
		if (!game->map.coins)
			game->finish = 1;
		game->current_frame_move = 0;
		game->player_direction = player_sprite;
		game->player_x = new_x;
		game->player_y= new_y;
		game->map.grid[new_y][new_x] = 'P';
		game->movements++;
		render_map(game);
	}
}

int handle_keypress(int keycode, t_game *game)
{
	if (keycode == XK_Up || keycode == XK_w)
		ft_player_move(game, game->player_y - 1, game->player_x, 1);
	else if (keycode == XK_Left || keycode == XK_a)
		ft_player_move(game, game->player_y, game->player_x - 1, 2);
	else if (keycode == XK_Right || keycode == XK_d)
		ft_player_move(game, game->player_y, game->player_x + 1, 3);
	else if (keycode == XK_Down || keycode == XK_s)
		ft_player_move(game, game->player_y + 1, game->player_x, 4);
    else if (keycode == XK_Escape)
		close_window(game);
    return (0);
}

int _lines_nbr(char *filename)
{
	int		lines;
	int		rows;
	char	*line;
	int		fd;
	int		flag;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	lines = 0;
	flag = 0;
	while (line)
	{
		free(line);
		if (!flag)
			line++;
		flag = 1;
		line = get_next_line(fd);
		lines++;
	}
	close(fd);
	return (lines);
}

int	ft_strchr(char *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

static void	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;
	int		rows;
	int		i;

	rows = _lines_nbr(filename);
	if (rows < 0)
		print_error("Error: Failed to open the map\n");
	rows = _lines_nbr(filename);
	game->map.grid = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!game->map.grid)
		print_error("Error: Memory allocation failed\n");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("Error while open the map\n");
	game->map.rows = rows;
	game->map.coins = 0;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->map.grid[i++] = line;
		game->map.coins += ft_strchr(line, 'C');
		line = get_next_line(fd);
	}
	game->map.grid[i] = NULL;
	close (fd);
}

int main(int ac, char **av)
{
    t_game	game;

	if (ac != 2)
		return (write(2, "Error: Invalid number of arguments\n", 33));
	read_map (av[1], &game);
	_setup (&game);
	preparation (&game);

	// Load sprites
	if (!load_sprites(&game))
		print_error("Error: Failed to load sprites\n");

	// Set up event hooks
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_loop_hook(game.mlx, render_map, &game);

	// Start game loop
	mlx_loop(game.mlx);
    return (0);
}
