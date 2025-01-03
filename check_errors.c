/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:49:04 by oayyoub           #+#    #+#             */
/*   Updated: 2025/01/03 09:08:02 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P'
		|| c == 'E' || c == 'C');
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

static int	check_map_conditions(t_game *game, int *counts, t_cord *player)
{
	if (!valid_characters(game->map.grid, game->map.rows, counts, player))
		return (print_error("Error: Invalid characters or shape\n"), 0);
	if (!is_surrounded_by_walls(game->map.grid, game->map.rows,
			ft_strlen(game->map.grid[0])))
		return (print_error("Error: Map not surrounded by walls\n"), 0);
	if (counts[0] != 1 || counts[1] != 1 || counts[2] < 1)
		return (print_error("Error: Needs 1 'P', 1 'E', ≥1 'C'\n"), 0);
	return (1);
}

static void	flood_fill(char **grid, t_map_size size, t_cord pos, t_test *test)
{
	if (pos.x < 0 || pos.x >= size.rows || pos.y < 0 || pos.y >= size.cols)
		return ;
	if (grid[pos.x][pos.y] == '1' || grid[pos.x][pos.y] == 'f'
		|| grid[pos.x][pos.y] == 'B')
		return ;
	if (grid[pos.x][pos.y] == 'E')
		test->exit = 1;
	if (grid[pos.x][pos.y] == 'C')
		test->coins++;
	grid[pos.x][pos.y] = 'f';
	flood_fill(grid, size, (t_cord){pos.x + 1, pos.y}, test);
	flood_fill(grid, size, (t_cord){pos.x - 1, pos.y}, test);
	flood_fill(grid, size, (t_cord){pos.x, pos.y + 1}, test);
	flood_fill(grid, size, (t_cord){pos.x, pos.y - 1}, test);
}

int	validate_map(t_game *game)
{
	int			counts[3];
	char		**grid_copy;
	t_cord		player;
	t_test		test;
	t_map_size	size;

	if (!game->map.grid)
		return (print_error("Error: Map is empty\n"), 0);
	size.rows = game->map.rows;
	size.cols = ft_strlen(game->map.grid[0]);
	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	if (!check_map_conditions(game, counts, &player))
		return (0);
	(1) && (test.coins = 0, test.exit = 0);
	grid_copy = ft_copy_map(game);
	flood_fill(grid_copy, size, player, &test);
	if (!test.exit || test.coins != game->map.coins)
	{
		free_map(grid_copy, game->map.rows);
		return (print_error("Error: Map is not valid\n"), 0);
	}
	free_map(grid_copy, game->map.rows);
	return (1);
}
