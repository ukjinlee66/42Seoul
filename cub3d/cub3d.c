#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

int	key_press(int code, t_form *form)
{
	if (code == KEY_W)
		printf("str : %s\n", form->str);
	else if (code == KEY_A)
		printf("x : %d y : %d\n", form->x, form->y);
	else if (code == KEY_ESC)
		exit(0);
	else
	{
		printf("'W' key: Print string\n");
		printf("'A' key: Print location\n");
		printf("'ESC' key: Exit this program\n");
	}
	return (0);
}

int main(void)
{
	void	*mlx;
	void	*win;
	t_form	f;

	init_form(&f);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "second test");
	mlx_hook(win, X_press, 0, &key_press, &f);
	mlx_loop(mlx);
}
