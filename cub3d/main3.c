#include "mlx.h"
#include <stdio.h>

int main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		i_width;
	int		i_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "img_test");
	img = mlx_xpm_file_to_image(mlx, "textures/wall2.xpm", &i_width, &i_height);
	mlx_put_image_to_window(mlx, win, img, 500, 500);
	mlx_loop(mlx);
	return (0);
}
