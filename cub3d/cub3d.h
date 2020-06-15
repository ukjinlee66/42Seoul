/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:03:08 by youlee            #+#    #+#             */
/*   Updated: 2020/06/15 14:44:25 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "Libft/libft.h"
#include "engine/engine.h"
#include "config.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "mlx.h"

/*
 ** **key code**
*/
# define LEFT_CLICK		1
# define RIGHT_CLICK	2
# define MIDDLE_CLICK	3
# define SCROLL_UP		4
# define SCROLL_DOWN	5

# define KEY_1			18
# define KEY_2			19
# define KEY_3			20
# define KEY_4			21
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_I			34
# define KEY_O			31
# define KEY_P			35
# define KEY_J			38
# define KEY_K			40
# define KEY_L			37
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_FORWARD 	126
# define KEY_BACKWARD	125
# define KEY_TAB		48
# define KEY_MAJ		257
# define KEY_ESC		53
# define KEY_TAB		48

/*
 ** struct **
*/

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_str
{
	char			*content;
	struct s_str	*next;
}					t_str;

typedef struct		s_img
{
	void			*img;
	void			*ptr;
	int				bpp;
	int				size_l;
	int				endian;
}					t_img;

typedef struct		s_win
{
	void			*win;
	void			*ptr;
	t_img			screen;
	t_pos			size;
	t_pos			half;
	double			ratio;
}					t_win;

typedef struct		s_tex
{
	char			*path;
	void			*tex;
	void			*ptr;
	t_pos			start;
	t_pos			end;
	int				width;
	int				height;
	int				bpp;
	int				size_l;
	int				endian;
}					t_tex;

typedef	struct		s_game
{
	t_config		config;
	t_camera		camera;
	t_win			window;
	t_pos			move;
	t_pos			x_move;
	t_pos			rotate;
	t_tex			tex[TEXTURES];
	int				options;
	int				to_kill;
	int				kill;
	double			camera_x[2000];
	double			depth[2000];
	double			sf_dist[1080];
	double			cos[2];
	double			sin[2];
}					t_game;

#endif
