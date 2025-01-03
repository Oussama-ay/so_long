/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_the_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:18:45 by oayyoub           #+#    #+#             */
/*   Updated: 2025/01/03 09:05:39 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_error(char *str)
{
	while (*str)
		write (2, str++, 1);
}

static int	_lines_nbr(char *filename)
{
	int		lines;
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
	int	i;
	int	count;

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

int	read_map(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	int		rows;
	int		i;

	rows = _lines_nbr(filename);
	if (rows < 0)
		return (print_error("Error: Failed to open the map\n"), 0);
	game->map.grid = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!game->map.grid)
		return (print_error("Error: Memory allocation failed\n"), 0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (print_error("Error while open the map\n"), 0);
	(1) && (game->map.rows = rows, game->map.coins = 0);
	(1) && (i = 0, line = get_next_line(fd));
	while (line)
	{
		game->map.grid[i++] = line;
		game->map.coins += ft_strchr(line, 'C');
		line = get_next_line(fd);
	}
	game->map.grid[i] = NULL;
	return (close (fd), 1);
}

int	is_surrounded_by_walls(char **grid, int rows, int cols)
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
