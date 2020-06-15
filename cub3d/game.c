/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:03:22 by youlee            #+#    #+#             */
/*   Updated: 2020/06/15 15:00:07 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"
#include "cub3d.h"

int		exit_game(t_game *game, int code)
{
	clear_config(&game->config);
	clear_window(&game->window);
	clear_textures(game);
	clear_sprites(&game->sprites);
	exit(code);
	return (code);
}

void	init_game(t_game *game, int save)
{
	int		i;

	init_config(&game->config);
	set_pos(&game->move, 0, 0);
	set_pos(&game->x_move, 0, 0);
	set_pos(&game->rotate, 0, 0);
	game->kill = 0;
	gmae->options = 0x11111110;
	game->sprites = NULL;
	if (save)
		game->options = game->options | FLAG_SAVE;
	i = 0;
	while (i < TEXTURES)
		game->tex[i++].tex = NULL;
}

int		finish_init(t_game *game)
{
	if (!init_window(&game->window, &game->config))
	{
		return (exit_error(game,
					"Error:\nmlx failed create window or image.\n"));
	}
	find_start_pos(&game->config, &game->camera);
	find_start_angle(&game->config, &game->camera);
	if (!load_textures(game))
		return (exit_error(game, "Error:\nfailed to load textures/\n"));
	if (!find_sprites(game))
		return (exit_error(game, "Error:\nfailed to malloc sprites.\n"));
	count_kill(game);
	make_tables(game);
	return (1);
}
