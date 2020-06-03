#include "mlx.h"

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int i;
	int j;

	i = 50;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "first_test");
	while (i < 250)
	{
		j = 50;
		while (j < 250)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0255000000);
			j++;
		}
		i++;
	}
	mlx_loop(mlx_ptr);
}
