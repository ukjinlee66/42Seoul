/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee </var/mail/youlee>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 20:07:09 by youlee            #+#    #+#             */
/*   Updated: 2020/06/11 20:19:23 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		exit_game(t_game *game, int code)
{

}

void	init_game(t_game *game, int save)
{
	int		i;

	set_pos(&game->move, 0, 0);
	set_pos(&game->x_move, 0, 0);
	set_pos(&game->rotate, 0, 0);
	game
