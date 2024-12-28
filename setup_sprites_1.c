/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_sprites_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:27:45 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/28 20:01:53 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*f_t_i(t_game *game, char *path)
{
	return (mlx_xpm_file_to_image(game->mlx, path,
		&game->sprites.width, &game->sprites.height));
}

int coins(t_game *game)
{
	game->sprites.collectible = malloc(sizeof(void *) * (18 + 1));
	if (!game->sprites.collectible)
		return (print_error("Error: Memory allocation failed (collectible)\n"), 0);
	game->sprites.collectible[18] = NULL;
	game->sprites.collectible[0] = f_t_i(game, "textures/coin_1.xpm");
	game->sprites.collectible[1] = f_t_i(game, "textures/coin_2.xpm");
	game->sprites.collectible[2] = f_t_i(game, "textures/coin_3.xpm");
	game->sprites.collectible[3] = f_t_i(game, "textures/coin_4.xpm");
	game->sprites.collectible[4] = f_t_i(game, "textures/coin_5.xpm");
	game->sprites.collectible[5] = f_t_i(game, "textures/coin_6.xpm");
	game->sprites.collectible[6] = f_t_i(game, "textures/coin_7.xpm");
	game->sprites.collectible[7] = f_t_i(game, "textures/coin_8.xpm");
	game->sprites.collectible[8] = f_t_i(game, "textures/coin_9.xpm");
	game->sprites.collectible[9] = f_t_i(game, "textures/coin_10.xpm");
	game->sprites.collectible[10] = f_t_i(game, "textures/coin_11.xpm");
	game->sprites.collectible[11] = f_t_i(game, "textures/coin_12.xpm");
	game->sprites.collectible[12] = f_t_i(game, "textures/coin_13.xpm");
	game->sprites.collectible[13] = f_t_i(game, "textures/coin_14.xpm");
	game->sprites.collectible[14] = f_t_i(game, "textures/coin_15.xpm");
	game->sprites.collectible[15] = f_t_i(game, "textures/coin_16.xpm");
	game->sprites.collectible[16] = f_t_i(game, "textures/coin_17.xpm");
	game->sprites.collectible[17] = f_t_i(game, "textures/coin_18.xpm");
	return (1);
}

int	boss(t_game *game)
{
	game->sprites.boss = malloc(sizeof(void *) * (6 + 1));
	if (!game->sprites.boss)
		return (print_error("Error: Memory allocation failed (boss)\n"), 0);
	game->sprites.boss[6] = NULL;
	game->sprites.boss[0] = mlx_xpm_file_to_image(game->mlx, "textures/boss_stand_1.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.boss[1] = mlx_xpm_file_to_image(game->mlx, "textures/boss_stand_2.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.boss[2] = mlx_xpm_file_to_image(game->mlx, "textures/boss_stand_3.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.boss[3] = mlx_xpm_file_to_image(game->mlx, "textures/boss_stand_4.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.boss[4] = mlx_xpm_file_to_image(game->mlx, "textures/boss_stand_5.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.boss[5] = mlx_xpm_file_to_image(game->mlx, "textures/boss_stand_6.xpm",
														&game->sprites.width, &game->sprites.height);
	return (1);
}

int	exit_animation(t_game *game)
{
	game->sprites.exit_animation = malloc(sizeof(void *) * (4 + 1));
	if (!game->sprites.exit_animation)
		return (print_error("Error: Memory allocation failed (exit_animation)\n"), 0);
	game->sprites.exit_animation[4] = NULL;
	game->sprites.exit_animation[0] = mlx_xpm_file_to_image(game->mlx, "textures/exit_1.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.exit_animation[1] = mlx_xpm_file_to_image(game->mlx, "textures/exit_2.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.exit_animation[2] = mlx_xpm_file_to_image(game->mlx, "textures/exit_3.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.exit_animation[3] = mlx_xpm_file_to_image(game->mlx, "textures/exit_4.xpm",
														&game->sprites.width, &game->sprites.height);
	return (1);
}

void	load_sprites(t_game *game)
{
	game->sprites.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
		&game->sprites.width, &game->sprites.height);
	game->sprites.floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
		&game->sprites.width, &game->sprites.height);
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit_1.xpm",
		&game->sprites.width, &game->sprites.height);
	game->sprites.exit_open = mlx_xpm_file_to_image(game->mlx, "textures/exit_4.xpm",
		&game->sprites.width, &game->sprites.height);
	coins(game);
	player_down(game);
	boss(game);
	exit_animation(game);
	player_right(game);
	player_left(game);
	player_up(game);
	
}
