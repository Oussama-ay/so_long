/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:49:04 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/28 17:26:10 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P'
			|| c == 'E' || c == 'C' || c == 'B');
}

static int	valid_characters(char **grid, int rows, int *counts, t_cord *player)
{
	int	i;
	int	cols;
	int	j;

	(1) && (cols = ft_strlen(grid[0]), i = 0);
	while (i < rows)
	{
		if (ft_strlen(grid[i]) != cols)
			return (0);
		j = 0;
		while (grid[i][j])
		{
			if (!valid_char(grid[i][j]))
				return (0);
			if (grid[i][j] == 'P')
				(1) && (player->x = i, player->y = j, counts[0]++);
			else if (grid[i][j] == 'E')
				counts[1]++;
			else if (grid[i][j] == 'C')
				counts[2]++;
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_surrounded_by_walls(char **grid, int rows, int cols)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		if (grid[i][0] != '1' || grid[i][cols - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < cols)
	{
		if (grid[0][i] != '1' || grid[rows - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static void	flood_fill(char **grid, int rows, int cols, int x, int y, t_test *test)
{
	if (x < 0 || x >= rows || y < 0 || y >= cols)
		return ;
	if (grid[x][y] == '1' || grid[x][y] == 'f' || grid[x][y] == 'B')
		return ;
	if (grid[x][y] == 'E')
		test->exit = 1;
	if (grid[x][y] == 'C')
		test->coins++;
	grid[x][y] = 'f';
	flood_fill(grid, rows, cols, x + 1, y, test);
	flood_fill(grid, rows, cols, x - 1, y, test);
	flood_fill(grid, rows, cols, x, y + 1, test);
	flood_fill(grid, rows, cols, x, y - 1, test);
}

int	validate_map(t_game *game)
{
	int		counts[3];
	int		cols;
	char	**grid_copy;
	t_cord	player;
	t_test	test;

	if (!game->map.grid)
		return (print_error("Error: Map is empty\n"), 0);
	cols = ft_strlen(game->map.grid[0]);
	if (game->map.rows < 3 || cols < 3)
		return (print_error("Error: Map is too small\n"), 0);
	(1) && (counts[0] = 0, counts[1] = 0, counts[2] = 0);
	if (!valid_characters(game->map.grid, game->map.rows, counts, &player))
		return (print_error("Error: Map is not rectangular or invalid characters\n"), 0);
	if (!is_surrounded_by_walls(game->map.grid, game->map.rows, cols))
		return (print_error("Error: Map is not surrounded by walls\n"), 0);
	if (counts[0] != 1 || counts[1] != 1 || counts[2] < 1)
		return (print_error("Error: (One 'P'),(One 'E'), (At lest one 'C')\n"), 0);
	(1) && (test.coins = 0, test.exit = 0);
	grid_copy = ft_copy_map(game);
	flood_fill(grid_copy, game->map.rows, cols, player.x, player.y, &test);
	free_map(grid_copy, game->map.rows);
	return (1);
}
