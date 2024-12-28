/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_sprites_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:27:45 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/28 11:17:28 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils.h"

int	player_down(t_game *game)
{
	game->sprites.player_down = malloc(sizeof(void *) * (6 + 1));
	if (!game->sprites.collectible)
		return (print_error("Error: Memory allocation failed (collectible)\n"), 0);
	game->sprites.player_down[6] = NULL;
	game->sprites.player_down[0] = mlx_xpm_file_to_image(game->mlx, "textures/stand_1.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_down[1] = mlx_xpm_file_to_image(game->mlx, "textures/stand_2.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_down[2] = mlx_xpm_file_to_image(game->mlx, "textures/stand_3.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_down[3] = mlx_xpm_file_to_image(game->mlx, "textures/stand_4.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_down[4] = mlx_xpm_file_to_image(game->mlx, "textures/stand_5.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_down[5] = mlx_xpm_file_to_image(game->mlx, "textures/stand_6.xpm",
														&game->sprites.width, &game->sprites.height);
	return (1);
}

int	player_right(t_game *game)
{
	game->sprites.player_right = malloc(sizeof(void *) * (6 + 1));
	if (!game->sprites.player_right)
		return (print_error("Error: Memory allocation failed (player_right)\n"), 0);
	game->sprites.player_right[6] = NULL;
	game->sprites.player_right[0] = mlx_xpm_file_to_image(game->mlx, "textures/right_1.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_right[1] = mlx_xpm_file_to_image(game->mlx, "textures/right_2.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_right[2] = mlx_xpm_file_to_image(game->mlx, "textures/right_3.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_right[3] = mlx_xpm_file_to_image(game->mlx, "textures/right_4.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_right[4] = mlx_xpm_file_to_image(game->mlx, "textures/right_5.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_right[5] = mlx_xpm_file_to_image(game->mlx, "textures/right_6.xpm",
														&game->sprites.width, &game->sprites.height);
	return (1);
}

int	player_left(t_game *game)
{
	game->sprites.player_left = malloc(sizeof(void *) * (6 + 1));
	if (!game->sprites.player_left)
		return (print_error("Error: Memory allocation failed (player_left)\n"), 0);
	game->sprites.player_left[6] = NULL;
	game->sprites.player_left[0] = mlx_xpm_file_to_image(game->mlx, "textures/left_1.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_left[1] = mlx_xpm_file_to_image(game->mlx, "textures/left_2.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_left[2] = mlx_xpm_file_to_image(game->mlx, "textures/left_3.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_left[3] = mlx_xpm_file_to_image(game->mlx, "textures/left_4.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_left[4] = mlx_xpm_file_to_image(game->mlx, "textures/left_5.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_left[5] = mlx_xpm_file_to_image(game->mlx, "textures/left_6.xpm",
														&game->sprites.width, &game->sprites.height);
	return (1);
}

int	player_up(t_game *game)
{
	game->sprites.player_up = malloc(sizeof(void *) * (6 + 1));
	if (!game->sprites.player_up)
		return (print_error("Error: Memory allocation failed (player_up)\n"), 0);
	game->sprites.player_up[6] = NULL;
	game->sprites.player_up[0] = mlx_xpm_file_to_image(game->mlx, "textures/up_1.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_up[1] = mlx_xpm_file_to_image(game->mlx, "textures/up_2.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_up[2] = mlx_xpm_file_to_image(game->mlx, "textures/up_3.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_up[3] = mlx_xpm_file_to_image(game->mlx, "textures/up_4.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_up[4] = mlx_xpm_file_to_image(game->mlx, "textures/up_5.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player_up[5] = mlx_xpm_file_to_image(game->mlx, "textures/up_6.xpm",
														&game->sprites.width, &game->sprites.height);
	return (1);
}
