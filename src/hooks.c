/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pestell2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:40:17 by pestell2          #+#    #+#             */
/*   Updated: 2025/08/25 10:15:59 by pestell2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Clean exit  (Linux MiniLibX). */
int	close_win(t_app *app)
{
	if (app->img.img)
		mlx_destroy_image(app->mlx, app->img.img);
	if (app->win)
		mlx_destroy_window(app->mlx, app->win);
	if (app->mlx)
	{
		mlx_destroy_display(app->mlx);
		free(app->mlx);
	}
	exit(0);
	return (0);
}

/* Applies a small pan step in the requested direction. */
static void	handle_pan(int key, t_app *app)
{
	double	dx;
	double	dy;

	dx = (app->vp.max_r - app->vp.min_r) * 0.05;
	dy = (app->vp.max_i - app->vp.min_i) * 0.05;
	if (key == XK_Left)
	{
		app->vp.min_r -= dx;
		app->vp.max_r -= dx;
	}
	else if (key == XK_Right)
	{
		app->vp.min_r += dx;
		app->vp.max_r += dx;
	}
	else if (key == XK_Up)
	{
		app->vp.min_i += dy;
		app->vp.max_i += dy;
	}
	else if (key == XK_Down)
	{
		app->vp.min_i -= dy;
		app->vp.max_i -= dy;
	}
}

/* ESC closes, arrows pan, space shifts palette. */
int	key_press(int key, t_app *app)
{
	if (key == XK_Escape)
		return (close_win(app), 0);
	if (key == XK_Left || key == XK_Right || key == XK_Up || key == XK_Down)
		handle_pan(key, app);
	else if (key == XK_space)
		app->shift += 1;
	render(app);
	return (0);
}

/* Mouse wheel zoom (mandatory). */
int	mouse_hook(int button, int x, int y, t_app *app)
{
	if (button == 4)
		view_zoom_at(&app->vp, 0.8, x, y);
	else if (button == 5)
		view_zoom_at(&app->vp, 1.25, x, y);
	render(app);
	return (0);
}
