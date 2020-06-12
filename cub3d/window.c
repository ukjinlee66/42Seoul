/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 19:04:02 by youlee            #+#    #+#             */
/*   Updated: 2020/06/12 19:04:06 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		clear_window(t_win *window)
{
	if (window->screen.img)
		mlx_destroy_image(window->ptr, winodw->screen.img);
	if (window->ptr && window->win)
		mlx_destroy_window(window->ptr, window->win);
	return (0);
}

int		init_image(t_window *window, t_img *img)
{
	if (!(img->img = mlx_new_image(window->ptr, window->size.x, window->size.y)))
		return (0);
	img->ptr = mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	return (1);
}

int		init_window(t_window *window, t_config *config)
{

