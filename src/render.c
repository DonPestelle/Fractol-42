/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pestell2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:39:11 by pestell2          #+#    #+#             */
/*   Updated: 2026/04/27 10:43:09 by pestell2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Renders one horizontal line to keep functions short. */
static void	render_line(t_app *app, int y)
{
	int			x;
	int			it;
	t_complex	z;

	x = 0;
	while (x < W)
	{
		z = screen_to_complex(&app->vp, x, y);
		if (app->type == F_MANDELBROT)
    			it = mandelbrot_iter(z);
		else if (app->type == F_JULIA)
    			it = julia_iter(z, app->julia_c);
		else 
    			it = burning_ship_iter(z);
		img_putpx(&app->img, x, y, colorize(it + app->shift));
		x++;
	}
}

/* Full frame render: iterate lines and push image to window. */
void	render(t_app *app)
{
	int	y;

	y = 0;
	while (y < H)
	{
		render_line(app, y);
		y++;
	}
	mlx_put_image_to_window(app->mlx, app->win, app->img.img, 0, 0);
}
