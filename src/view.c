/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pestell2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:38:28 by pestell2          #+#    #+#             */
/*   Updated: 2025/08/24 19:38:37 by pestell2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Default viewport fits Mandelbrot nicely. */
void	view_init(t_view *v)
{
	v->min_r = -2.0;
	v->max_r = 1.0;
	v->min_i = -1.2;
	v->max_i = 1.2;
}

/* Zooms around cursor position. factor < 1 zoom in, > 1 zoom out. */
void	view_zoom_at(t_view *v, double f, int x, int y)
{
	double	pr;
	double	pi;
	double	rr;
	double	ri;

	pr = v->min_r + (double)x * (v->max_r - v->min_r) / (double)(W - 1);
	pi = v->max_i - (double)y * (v->max_i - v->min_i) / (double)(H - 1);
	rr = (v->max_r - v->min_r) * f;
	ri = (v->max_i - v->min_i) * f;
	v->min_r = pr - rr * 0.5;
	v->max_r = pr + rr * 0.5;
	v->min_i = pi - ri * 0.5;
	v->max_i = pi + ri * 0.5;
}
