#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

#define KEY_Q 12
#define KEY_W 13
#define KEY_E 14
#define KEY_R 15
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_ESC 53

#define X_EXIT 17
#define X_release 3
#define X_press 2

typedef struct	s_form
{
	int		x;
	int		y;
	char	str[3];
}		t_form;

void init_form(t_form *a)
{
	a->x = 0;
	a->y = 0;
	a->str[0] = 'a';
	a->str[1] = 'b';
	a->str[2] = '\0';
}

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
