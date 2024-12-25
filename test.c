/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oayyoub <oayyoub@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:52:40 by oayyoub           #+#    #+#             */
/*   Updated: 2024/12/25 09:31:51 by oayyoub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <X11/keysym.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define WIN_TITLE "GTA VI"
#define RUN_SPRITES 8

typedef struct s_data
{
	void	*mlx_connection;
	void	*mlx_window;
	void	*run_sprites[RUN_SPRITES];
	int		sprite_width;
	int		sprite_height;
	int		current_frame;
}	t_data;

// int	close_window(t_data *data)
// {
// 	if (data->mlx_window)
// 		mlx_destroy_window(data->mlx_connection, data->mlx_window);
// 	if (data->mlx_connection)
// 	{
// 		mlx_destroy_display(data->mlx_connection);
// 		free(data->mlx_connection);
// 	}
// 	printf("Bye\n");
// 	exit(0);
// 	return (0);
// }

// Function to handle the close event
int	close_window(t_data *data)
{
	for (int i = 0; i < RUN_SPRITES; i++)
		if (data->run_sprites[i])
			mlx_destroy_image(data->mlx_connection, data->run_sprites[i]);
	if (data->mlx_window)
		mlx_destroy_window(data->mlx_connection, data->mlx_window);
	if (data->mlx_connection)
	{
		mlx_destroy_display(data->mlx_connection);
		free(data->mlx_connection);
	}
	printf("Bye\n");
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		printf("the (ESC) key has been pressed\n");
		close_window(data);
	}
	printf("the %c key has been pressed\n", keycode);
	return (0);
}

void delay_ms()
{
    int start_time;
    int delay_time;

	delay_time = 675000000;
	start_time = 0;
	while (start_time < delay_time)
		start_time++;
}

int	render(t_data *data)
{
	if (data->run_sprites[data->current_frame])
	{
		// Clear the window
		mlx_clear_window(data->mlx_connection, data->mlx_window);
		// Draw the current frame of the sprite animation
		int x = (WIN_WIDTH - data->sprite_width) / 2;
		int y = (WIN_HEIGHT - data->sprite_height) / 2;
		mlx_put_image_to_window(data->mlx_connection, data->mlx_window, data->run_sprites[data->current_frame], x, y);
		// Update the frame for animation
		data->current_frame = (data->current_frame + 1) % RUN_SPRITES;
	}
	delay_ms(); // delay for smooth animation
	// usleep(150000);
	return (0);
}

int main(int ac, char **av)
{
    t_data  data;
	char	*sprite_paths[RUN_SPRITES] = {
		"sprites/run/RUN_sprite_1.xpm",
		"sprites/run/RUN_sprite_2.xpm",
		"sprites/run/RUN_sprite_3.xpm",
		"sprites/run/RUN_sprite_4.xpm",
		"sprites/run/RUN_sprite_5.xpm",
		"sprites/run/RUN_sprite_6.xpm",
		"sprites/run/RUN_sprite_7.xpm",
		"sprites/run/RUN_sprite_8.xpm"
	};

    data.mlx_connection = mlx_init();
	// Initialize MiniLibX
    if (!data.mlx_connection)
    {
		write(2, "Error: Failed to initialize MLX\n", 34);
		return (1);
    }

    // Create a window
    data.mlx_window = mlx_new_window(data.mlx_connection, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!data.mlx_window)
	{
		write(2, "Error: Failed to create window\n", 32);
		mlx_destroy_display(data.mlx_connection);
		free(data.mlx_connection);
		return (1);
	}

	// Create an image for drawing
	data.current_frame = 0;
	for (int i = 0; i < RUN_SPRITES; i++)
	{
		data.run_sprites[i] = mlx_xpm_file_to_image(data.mlx_connection, sprite_paths[i], &data.sprite_width, &data.sprite_height);
		if (!data.run_sprites[i])
		{
			write(2, "Error: Failed to load sprite\n", 29);
			close_window(&data);
		}
	}

	/*--------------------close event handling--------------------------------*/
	// Handle window close event (e.g., clicking the close button)
	mlx_hook(data.mlx_window, 17, 0, close_window, &data);

	// Handle key press events (e.g., ESC key)
	mlx_key_hook(data.mlx_window, handle_keypress, &data);

	// Render loop
	mlx_loop_hook(data.mlx_connection, render, &data); 
	/*------------------------------------------------------------------------*/

	// Start the MLX event loop
	mlx_loop(data.mlx_connection);

	return (0);
}
