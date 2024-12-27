/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:03:51 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/27 10:04:54 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_map(t_map *mape)
{
	int	i = 0;

	if (!mape)
		return ;
	while (i < mape->rows)
		free (mape->grid[i++]);
	free (mape->grid);
}

static void	destroy_image(void *mlx, void **sprites)
{
	int	i;

	i = 0;
	if (!sprites)
		return;
	while (sprites[i])
		mlx_destroy_image(mlx, sprites[i++]);
	free(sprites);
}

int	close_window(t_game *game)
{
	free_map(&game->map);
	if (game->sprites.wall)
		mlx_destroy_image(game->mlx, game->sprites.wall);
	if (game->sprites.floor)
		mlx_destroy_image(game->mlx, game->sprites.floor);
	if (game->sprites.exit)
		mlx_destroy_image(game->mlx, game->sprites.exit);
	if (game->sprites.exit_open)
		mlx_destroy_image(game->mlx, game->sprites.exit_open);
	destroy_image(game->mlx, game->sprites.collectible);
	destroy_image(game->mlx, game->sprites.player_down);
	destroy_image(game->mlx, game->sprites.exit_animation);
	destroy_image(game->mlx, game->sprites.boss);
	destroy_image(game->mlx, game->sprites.player_right);
	destroy_image(game->mlx, game->sprites.player_left);
	destroy_image(game->mlx, game->sprites.player_up);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}
