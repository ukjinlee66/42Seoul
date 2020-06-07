#include <stdio.h>
#include "mlx.h"
typedef struct	s_img
{
	void	*ptr;
	int		*data;
	int		width;
	int		height;
	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

int main()
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		cnt_h;
	int		cnt_w;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img.ptr = mlx_xpm_file_to_image(mlx, "textures/wall1.xpm", &img.width, &img.height);
	img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.size_l, &img.endian);

	cnt_h = -1;
	while (++cnt_h < img.height)
	{
		cnt_w = -1;
		while (++cnt_w < img.width / 2)
		{
			if (cnt_w % 2)
				img.data[cnt_h * img.width + cnt_w] = 0xFFFFFF;
			else
				img.data[cnt_h * img.width + cnt_w] = 0xFF0000;
		}
	}
	mlx_put_image_to_window(mlx, win, img.ptr, 50, 50);
	mlx_loop(mlx);
	return (0);
}
