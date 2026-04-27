/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pestell2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:36:15 by pestell2          #+#    #+#             */
/*   Updated: 2025/08/24 19:37:30 by pestell2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Initializes MLX, parses CLI, sets viewport and hooks. */
int	main(int ac, char **av)
{
	t_app	app;

	app.mlx = mlx_init();
	if (!app.mlx)
		return (1);
	view_init(&app.vp);
	app.shift = 0;
	if (!parse_args(ac, av, &app))
	{
		print_usage();
		return (0);
	}
	app.win = mlx_new_window(app.mlx, W, H, "fractol");
	if (!app.win)
		return (1);
	app.img.img = mlx_new_image(app.mlx, W, H);
	app.img.pixels = mlx_get_data_addr(app.img.img, &app.img.bpp, &app.img.line,
			&app.img.endian);
	render(&app);
	mlx_hook(app.win, DestroyNotify, 0, (int (*)(void *))close_win, &app);
	mlx_key_hook(app.win, key_press, &app);
	mlx_mouse_hook(app.win, mouse_hook, &app);
	mlx_loop(app.mlx);
	return (0);
}
