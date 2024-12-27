/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_input_output_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:22:15 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/27 09:31:13 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void delay_ms(int delay_time)
{
	int	start_time;

	start_time = 0;
	while (start_time < delay_time)
		start_time++;
}

void	stream (t_game *game, void **frames, int i, t_cord cord)
{
	if (!frames || !frames[i])
        return;
	mlx_put_image_to_window(game->mlx, game->win, frames[i], cord.x * 64, cord.y * 64);
	delay_ms(90000000);
	i++;
}
