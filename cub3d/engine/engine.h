/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 20:06:06 by youlee            #+#    #+#             */
/*   Updated: 2020/06/15 15:22:40 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "../cub3d.h"
# include <math.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_MOUSE_PRESS	4
# define X_EVENT_MOUSE_RELEASE	5
# define X_EVENT_MOUSE_MOVE		6
# define X_EVENT_EXIT			17

# define FLAG_UI				0x00000010
# define FLAG_SAVE				0x00000001

# define BSET_RATIO				1.7777777778

typedef struct		s_camera
{
	t_pos			pos;
	t_pos			dir;
	t_pos			x_dir;
	t_pos			plane;
}					t_camera;

typedef struct		s_raysult
{
	int				column;
	int				row;
	double			dist;
	int				dir;
	int				side;
	int				height;
	t_pos			ray_pos;
	t_pos			ray_dir;
	t_pos			map_pos;
	t_pos			side_dist;
	t_pos			delta_dist;
	t_pos			step;
	double			wall_x;
	t_pos			floor_wall;
	t_pos			c_floor;
}					t_raysult;

typedef struct		s_sprite_draw
{
	int				sp_screen;
	t_pos			pos;
	t_pos			transform;
	t_pos			spr_s;
	t_pos			draw_x;
	t_pos			draw_y;
	t_pos			tex_pos;
	int				fact;
	int				draw_y_org;
}					t_sprite_draw;

typedef struct		s_sprite
{
	t_pos			pos;
	t_tex			*tex;
	double			dist;
	struct s_sprite *next;
	struct s_sprite *sorted;
}					t_sprite;

#endif
