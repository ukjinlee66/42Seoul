/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 18:55:40 by youlee            #+#    #+#             */
/*   Updated: 2020/06/15 15:04:04 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_hook(t_game *game)
{
	return (exit_game(game, EXIT_SUCCESS));
}

int		key_press(int code, t_game *game)
{
	if (code == KEY_W || code == KEY_FORWARD)
		game->move.x = 1;
	else if (code == KEY_S || code == KEY_BACKWARD)
		game->move.y = 1;
	if (code == KEY_A)
		game->x_move.x = 1;
	else if (code == KEY_D)
		game->y_move.y = 1;
	if (code == KEY_Q || code == KEY_LEFT)
		game->rotate.x = 1;
	else if (code == KEY_E || code == KEY_RIGHT)
		game->rotate.y = 1;
	return (0);
}

int		key_release(int code, t_game *game)
{
	if (code == KEY_W || code == KEY_FORWARD)
		game->move.x = 0;
	else if (code == KEY_S || code == KEY_BACKWARD)
		game->move.y = 0;
	else if (code == KEY_A)
		game->x_move.x = 0;
	else if (code == KEY_D)
		game->y_move.y = 0;
	else if (code == KEY_Q || code == KEY_LEFT)
		game->rotate.x = 0;
	else if (code == KEY_E || code == KEY_RIGHT)
		game->rotate.y = 0;
	else if (code == KEY_ESC)
		return (exit_game(game, EXIT_SUCCESS));
	return (0);
}

int		main_loop(t_game *game)
{
	static int		update = 1;
	static int		last_opt = 0x00000111;

	if (game->move.x || game->move.y)
		update = move_camera(game, (game->move.x) ? 0 : 1);
	if (game->x_move.x || game->x_move.y)
		update = move_perp_camera(game, (game->x_move.x) ? 0 : 1);
	if (game->rotate.x || game->rotate.y)
		update = rotate_camera(game, (game->rotate.x) ? 0 : 1);
	if (last_opt != game.options)
	{
		update = 1;
		last_opt = game->options;
	}
	if (update)
	{
		if (game->to_kill > 0)
			check_quest(game);
		MAP(game->camera.pos, game->config) = 'A';
		update_screen(game);
		update_window(game);
	}
	return (0);
}
