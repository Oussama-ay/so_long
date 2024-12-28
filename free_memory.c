/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:03:51 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/28 09:58:59 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_map(char	**mape, int rows)
{
	int	i;

	if (!mape)
		return ;
	i = 0;
	while (i < rows)
		free (mape[i++]);
	free (mape);
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
	free_map(game->map.grid, game->map.rows);
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

static char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_copy_map(t_game *game)
{
	char	**grid;
	int		i;

	grid = (char **)malloc(sizeof(char *) * (game->map.rows + 1));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < game->map.rows)
	{
		grid[i] = ft_strdup(game->map.grid[i]);
		if (!grid[i])
		{
			while (i >= 0)
				free(grid[i--]);
			free(grid);
			return (NULL);
		}
		i++;
	}
	grid[i] = NULL;
	return (grid);
}
