/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:59:32 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/26 09:03:19 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collectible(t_game *game);
int	player(t_game *game);
int	boss(t_game *game);
int	exit_animation (t_game *game);
int	player_right(t_game *game);
int	player_left(t_game *game);
int	player_up (t_game *game);
int	boss_attack(t_game *game);
int	boy_died (t_game *game);

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	_setup(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->sprites.wall = NULL;
	game->sprites.floor = NULL;
	game->sprites.collectible = NULL;
	game->sprites.exit = NULL;
	game->sprites.player = NULL;
	game->sprites.boss = NULL;
	game->sprites.exit_animation = NULL;
	game->sprites.exit_open = NULL;
	game->sprites.player_left = NULL;
	game->sprites.player_right = NULL;
	game->sprites.player_up = NULL;
	game->sprites.attack = NULL;
	game->current_frame_coin = 0;
	game->current_frame_player = 0;
	game->current_frame_boss = 0;
	game->current_frame_exit = 0;
	game->finish = 0;
	game->attack = 0;
	game->movements = 0;
	game->player_direction = 4;
	game->map.columns = ft_strlen (game->map.grid[0]);
}

void	preparation (t_game *game)
{
	game->mlx = mlx_init();
    if (!game->mlx)
    {
		print_error ("Error: Failed to initialize MLX\n");
		close_window (game);
		return ;
	}
	game->win = mlx_new_window(game->mlx, (game->map.columns - 1) * 64, game->map.rows * 64, WIN_TITLE);
	if (!game->win)
	{
		print_error ("Error: Failed to create window\n");
		close_window (game);
		return ;
	}
}

int load_sprites(t_game *game)
{
	int	i;

	game->sprites.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
		&game->sprites.width, &game->sprites.height);
	if (!game->sprites.wall)
		return (print_error("Error: Failed to load wall texture\n"), 0);
	game->sprites.floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
		&game->sprites.width, &game->sprites.height);
	if (!game->sprites.floor)
		return (print_error("Error: Failed to load floor texture\n"), 0);
	game->sprites.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit_1.xpm",
		&game->sprites.width, &game->sprites.height);
	if (!game->sprites.exit)
		return (print_error("Error: Failed to load exit texture\n"), 0);
	game->sprites.exit_open = mlx_xpm_file_to_image(game->mlx, "textures/exit_4.xpm",
		&game->sprites.width, &game->sprites.height);
	if (!game->sprites.exit_open)
		return (print_error("Error: Failed to load exit_open texture\n"), 0);
	if (!collectible(game))
		return (print_error("Error: Failed to load collectible texture\n"), 0);
	if (!player(game))
		return (print_error("Error: Failed to load player texture\n"), 0);
	if (!boss(game))
		return (print_error("Error: Failed to load boss texture\n"), 0);
	if (!exit_animation(game))
		return (print_error("Error: Failed to load exit animation texture\n"), 0);
	if (!player_right(game))
		return (print_error("Error: Failed to load player_right texture\n"), 0);
	if (!player_left(game))
		return (print_error("Error: Failed to load player_left texture\n"), 0);
	if (!player_up(game))
		return (print_error("Error: Failed to load player_up texture\n"), 0);
	if (!boss_attack(game))
		return (print_error("Error: Failed to load boss_attack texture\n"), 0);
	if (!boy_died(game))
		return (print_error("Error: Failed to load boy_died texture\n"), 0);
	return (1);
}

int collectible(t_game *game)
{
	game->sprites.collectible = malloc(sizeof(void *) * (18 + 1));
	if (!game->sprites.collectible)
		return (print_error("Error: Memory allocation failed (collectible)\n"), 0);
	game->sprites.collectible[18] = NULL;
	game->sprites.collectible[0] = mlx_xpm_file_to_image(game->mlx, "textures/coin_1.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[1] = mlx_xpm_file_to_image(game->mlx, "textures/coin_2.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[2] = mlx_xpm_file_to_image(game->mlx, "textures/coin_3.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[3] = mlx_xpm_file_to_image(game->mlx, "textures/coin_4.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[4] = mlx_xpm_file_to_image(game->mlx, "textures/coin_5.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[5] = mlx_xpm_file_to_image(game->mlx, "textures/coin_6.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[6] = mlx_xpm_file_to_image(game->mlx, "textures/coin_7.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[7] = mlx_xpm_file_to_image(game->mlx, "textures/coin_8.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[8] = mlx_xpm_file_to_image(game->mlx, "textures/coin_9.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[9] = mlx_xpm_file_to_image(game->mlx, "textures/coin_10.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[10] = mlx_xpm_file_to_image(game->mlx, "textures/coin_11.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[11] = mlx_xpm_file_to_image(game->mlx, "textures/coin_12.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[12] = mlx_xpm_file_to_image(game->mlx, "textures/coin_13.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[13] = mlx_xpm_file_to_image(game->mlx, "textures/coin_14.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[14] = mlx_xpm_file_to_image(game->mlx, "textures/coin_15.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[15] = mlx_xpm_file_to_image(game->mlx, "textures/coin_16.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[16] = mlx_xpm_file_to_image(game->mlx, "textures/coin_17.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.collectible[17] = mlx_xpm_file_to_image(game->mlx, "textures/coin_18.xpm",
														&game->sprites.width, &game->sprites.height);
	return (1);
}

int player(t_game *game)
{
	game->sprites.player = malloc(sizeof(void *) * (6 + 1));
	if (!game->sprites.collectible)
		return (print_error("Error: Memory allocation failed (collectible)\n"), 0);
	game->sprites.player[6] = NULL;
	game->sprites.player[0] = mlx_xpm_file_to_image(game->mlx, "textures/stand_1.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player[1] = mlx_xpm_file_to_image(game->mlx, "textures/stand_2.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player[2] = mlx_xpm_file_to_image(game->mlx, "textures/stand_3.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player[3] = mlx_xpm_file_to_image(game->mlx, "textures/stand_4.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player[4] = mlx_xpm_file_to_image(game->mlx, "textures/stand_5.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.player[5] = mlx_xpm_file_to_image(game->mlx, "textures/stand_6.xpm",
														&game->sprites.width, &game->sprites.height);
	return (1);
}

int boss(t_game *game)
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

int	exit_animation (t_game *game)
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

int	boss_attack(t_game *game)
{
	game->sprites.attack = malloc(sizeof(void *) * (8 + 1));
	if (!game->sprites.attack)
		return (print_error("Error: Memory allocation failed (boss_attack)\n"), 0);
	game->sprites.attack[8] = NULL;
	game->sprites.attack[0] = mlx_xpm_file_to_image(game->mlx, "textures/attack_right_1.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.attack[1] = mlx_xpm_file_to_image(game->mlx, "textures/attack_right_2.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.attack[2] = mlx_xpm_file_to_image(game->mlx, "textures/attack_right_3.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.attack[3] = mlx_xpm_file_to_image(game->mlx, "textures/attack_right_4.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.attack[4] = mlx_xpm_file_to_image(game->mlx, "textures/attack_left_1.xpm",
														&game->sprites.width, &game->sprites.height);																												
	game->sprites.attack[5] = mlx_xpm_file_to_image(game->mlx, "textures/attack_left_2.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.attack[6] = mlx_xpm_file_to_image(game->mlx, "textures/attack_left_3.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.attack[7] = mlx_xpm_file_to_image(game->mlx, "textures/attack_left_4.xpm",
														&game->sprites.width, &game->sprites.height);
	return (1);
}

int	boy_died (t_game *game)
{
	game->sprites.boy_lose = malloc(sizeof(void *) * (4 + 1));
	if (!game->sprites.boy_lose)
		return (print_error("Error: Memory allocation failed (boy_lose)\n"), 0);
	game->sprites.boy_lose[4] = NULL;
	game->sprites.boy_lose[0] = mlx_xpm_file_to_image(game->mlx, "textures/death_1.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.boy_lose[1] = mlx_xpm_file_to_image(game->mlx, "textures/death_2.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.boy_lose[2] = mlx_xpm_file_to_image(game->mlx, "textures/death_3.xpm",
														&game->sprites.width, &game->sprites.height);
	game->sprites.boy_lose[3] = mlx_xpm_file_to_image(game->mlx, "textures/death_4.xpm",
														&game->sprites.width, &game->sprites.height);
	return (1);
}
