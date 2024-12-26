/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:03:51 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/26 09:09:43 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *mape)
{
	int	i = 0;

	while (i < mape->rows)
		free (mape->grid[i++]);
	free (mape->grid);
}
int close_window(t_game *game)
{
	int	i;

	// Free map
	free_map (&game->map);

	// Destroy sprites
	if (game->sprites.wall)
		mlx_destroy_image(game->mlx, game->sprites.wall);
	if (game->sprites.floor)
		mlx_destroy_image(game->mlx, game->sprites.floor);
	if (game->sprites.collectible)
	{
		i = 0;
		while (game->sprites.collectible[i])
			mlx_destroy_image(game->mlx, game->sprites.collectible[i++]);
		free(game->sprites.collectible);
	}
	if (game->sprites.player)
	{
		i = 0;
		while (game->sprites.player[i])
			mlx_destroy_image(game->mlx, game->sprites.player[i++]);
		free(game->sprites.player);
	}
	if (game->sprites.exit)
		mlx_destroy_image(game->mlx, game->sprites.exit);
	if (game->sprites.exit_open)
		mlx_destroy_image(game->mlx, game->sprites.exit_open);
	if (game->sprites.exit_animation)
	{
		i = 0;
		while (game->sprites.exit_animation[i])
			mlx_destroy_image(game->mlx, game->sprites.exit_animation[i++]);
		free(game->sprites.exit_animation);
	}
	if (game->sprites.boss)
	{
		i = 0;
		while (game->sprites.boss[i])
			mlx_destroy_image(game->mlx, game->sprites.boss[i++]);
		free(game->sprites.boss);
	}
	if (game->sprites.player_right)
	{
		i = 0;
		while (game->sprites.player_right[i])
			mlx_destroy_image(game->mlx, game->sprites.player_right[i++]);
		free(game->sprites.player_right);
	}
	if (game->sprites.player_left)
	{
		i = 0;
		while (game->sprites.player_left[i])
			mlx_destroy_image(game->mlx, game->sprites.player_left[i++]);
		free(game->sprites.player_left);
	}
	if (game->sprites.player_up)
	{
		i = 0;
		while (game->sprites.player_up[i])
			mlx_destroy_image(game->mlx, game->sprites.player_up[i++]);
		free(game->sprites.player_up);
	}
	if (game->sprites.attack)
	{
		i = 0;
		while (game->sprites.attack[i])
			mlx_destroy_image(game->mlx, game->sprites.attack[i++]);
		free(game->sprites.attack);
	}
	if (game->sprites.boy_lose)
	{
		i = 0;
		while (game->sprites.boy_lose[i])
			mlx_destroy_image(game->mlx, game->sprites.boy_lose[i++]);
		free(game->sprites.boy_lose);
	}	
	// Destroy window and MLX
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	printf("Bye\n");
    exit(0);
    return (0);
}
