/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:49:04 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/26 22:43:05 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P'
			|| c == 'E' || c == 'C');
}

static int	valid_characters(char **grid, int rows, int *counts)
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
				counts[0]++;
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

int	validate_map(t_game *game)
{
	int	counts[3];
	int	cols;

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	cols = ft_strlen(game->map.grid[0]);
	if (!valid_characters(game->map.grid, game->map.rows, counts))
		return (print_error("Error: Map is not rectangular or invalid characters\n"), 0);
	if (!is_surrounded_by_walls(game->map.grid, game->map.rows, cols))
		return (print_error("Error: Map is not surrounded by walls\n"), 0);
	if (counts[0] != 1)
		return (print_error("Error: Map must have exactly one player ('P')\n"), 0);
	if (counts[1] < 1)
		return (print_error("Error: Map must have at least one exit ('E')\n"), 0);
	if (counts[2] < 1)
		return (print_error("Error: Map must have at least one collectible ('C')\n"), 0);
	return (1);
}

