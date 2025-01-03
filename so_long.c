/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:34:02 by oayyoub           #+#    #+#             */
/*   Updated: 2025/01/03 08:45:38 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	nbr_digits(int n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		is_negative;
	int		size;
	int		i;

	is_negative = n < 0;
	if (is_negative)
		n = -n;
	size = nbr_digits(n) + is_negative;
	result = malloc(size + 1);
	if (!result)
		return (0);
	i = size;
	result[i--] = '\0';
	while (i >= 0)
	{
		result[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	if (is_negative)
		result[0] = '-';
	return (result);
}

int	_display_counter(t_game *game)
{
	char	*str;
	char	*movements;

	movements = ft_itoa(game->movements);
	if (!movements)
		return (0);
	str = ft_strjoin("Movements: ", movements);
	if (!str)
	{
		free(movements);
		return (0);
	}
	mlx_string_put(game->mlx, game->win, 10, 10, 0x00FFFFFF, str);
	free(movements);
	free(str);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (write(2, "Error: Invalid number of arguments\n", 33));
	read_map (av[1], &game);
	if (!validate_map(&game))
	{
		free_map(game.map.grid, game.map.rows);
		return (write(2, "Error: Invalid map\n", 19));
	}
	_setup (&game);
	open_window (&game);
	load_sprites (&game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_loop_hook(game.mlx, render_map, &game);
	mlx_loop(game.mlx);
	return (0);
}
