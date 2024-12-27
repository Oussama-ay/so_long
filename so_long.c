/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:34:02 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/27 10:10:21 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

# include <stdio.h>
int main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (write(2, "Error: Invalid number of arguments\n", 33));
	read_map (av[1], &game);
	// if (!validate_map(&game))
	// {
	// 	free_map(&game.map);
	// 	return (write(2, "Error: Invalid map\n", 19));
	// }
	_setup (&game);
	open_window (&game);

	// Load sprites
	load_sprites (&game);

	// Set up event hooks
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_loop_hook(game.mlx, render_map, &game);

	// Start game loop
	mlx_loop(game.mlx);
    return (0);
}
