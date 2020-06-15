/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlee <youlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:03:48 by youlee            #+#    #+#             */
/*   Updated: 2020/06/15 14:08:27 by youlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"

int main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "dd");
	img = mlx_xpm_file_to_image(mlx, "./textures/dd.xpm", &width, &height);
	mlx_put_image_to_window(mlx, win, img, 100, 100);
	mlx_loop(mlx);
	return (0);
}
