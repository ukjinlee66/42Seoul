/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 20:05:59 by youlee            #+#    #+#             */
/*   Updated: 2020/06/13 19:52:12 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void		find_start(t_config *config, t_camera *camera)
{
	int		stop;

	stop = 0;
	camera->pos.y = 0;
	while (!stop && camera->pos.y < config->rows)
	{
		camera->pos.x = 0;
		while (!stop && camera->pos.x < config->columns)
		{
			if (ft_in_set(MAP(camera->pos, *config), DIRECTIONS))
			{
				stop = 1;
				break;
			}
			(camera->pos.x)++;
		}
		if (!stop)
			(camera->pos.y)++;
	}
	camera->pos.x += .5;
	camera->pos.y += .5;
}

void		find_start_angle(t_config 
