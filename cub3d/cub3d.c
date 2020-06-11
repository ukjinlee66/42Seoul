#include "cub3d.h"

int	key_press(int code, t_game *game)
{
	if (code == KEY_W || code == KEY_FORWARD)
		game->move.x = 1;
	else if (code == KEY_S || code == KEY_BACKWARD)
		game->move.y = 1;
	if (code == KEY_A)
		game->x_move.x = 1;
	else if (code == KEY_D)
		game->y_move.y = 1;
	if (code == KEY_Q || code == KEY_LEFT)
		game->rotate.x = 1;
	else if(code == KEY_E || code == KEY_RIGHT)
		game->rotate.y = 1;
	return (0);
}

int key_release(int code, t_game *game)
{
	if (code == KEY_W || code == KEY_FORWARD)
		game->move.x = 0;
	else if (code == KEY_S || code == KEY_BACKWARD)
		game->move.y = 0;
	else if (code == KEY_A)
		game->x_move.x = 0;
	else if (code == KEY_D)
		game->y_move.y = 0;
	else if (code == KEY_Q || code == KEY_LEFT)
		game->rotate.x = 0;
	else if (code == KEY_E || code == KEY_RIGHT)
		game->rotate.y = 0;
	else if (code == KEY_ESC)
		return (exit_game(game, EXIT_SUCCESS));
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
