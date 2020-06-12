/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 20:06:06 by youlee            #+#    #+#             */
/*   Updated: 2020/06/12 20:09:56 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

typedef struct		s_camera
{
	t_pos			pos;
	t_pos			dir;
	t_pos			x_dir;
	t_pos			plane;
}					t_camera;

typedef struct		s_sprite
{
	t_pos			pos;
	t_tex			*tex;
	double			dist;
	struct s_sprite *next;
	struct s_sprite *sorted;
}					t_sprite;


