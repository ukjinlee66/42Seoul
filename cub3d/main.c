/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:03:39 by youlee            #+#    #+#             */
/*   Updated: 2020/06/12 19:03:40 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_error(t_game *game, char const *str)
{
	if (str)
		write(STDOUT_FILENO, str, ft_strlen(str));
	exit_game(game, EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int 	main(int ac, char **av)
{
	t_game	game;
	int		save_op;

	save_op = (ac >= 2 && !ft_strcmp(av[1], "-save"));
	if (ac < (2 + save_op))
		return (exit_error(&game, "Error:\nno map specified.\n"));
	init_game(&game, save_op);
	if (!parse_config(&game.config, argv[1 + save_op]))
		return (exit_error(&game, "Error:\ninvalid map.\n"));
	if (!finish_init(&game))
		return (EXIT_FAILURE);
	mlx_hook(game.window.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.window.win, X_EVENT_KEY_RELEASE, 0, &ket_release, &game);
	mlx_hook(game.window.win, X_EVENT_EXIT, 0, &exit_hook, &game);
	mlx_loop_hook(game.window.ptr, &main_loop, &game);
	mlx_loop(game.window.ptr);
	return (EXIT_SUCCESS);
}
