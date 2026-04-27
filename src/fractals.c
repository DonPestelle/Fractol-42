/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pestell2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:39:40 by pestell2          #+#    #+#             */
/*   Updated: 2026/04/27 10:41:47 by pestell2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Iteration for Mandelbrot: z_{n+1} = z_n^2 + c, start z=0. */
int	mandelbrot_iter(t_complex c)
{
	int			it;
	t_complex	z;

	it = 0;
	z = cpx_make(0.0, 0.0);
	while (it < MAX_IT && cpx_abs2(z) <= 4.0)
	{
		z = cpx_add(cpx_sqr(z), c);
		it++;
	}
	return (it);
}

int	burning_ship_iter(t_complex c)
{
	int			it;
	t_complex	z;

	it = 0;
	z = cpx_make(0.0, 0.0);
	while (it < MAX_IT && cpx_abs2(z) <= 4.0)
	{
		z = cpx_make(fabs(z.r), fabs(z.i));
		z = cpx_add(cpx_sqr(z), c);
		it++;
	}
	return (it);
}

/* Iteration for Julia: z_{n+1} = z_n^2 + c, start z=pixel. */
int	julia_iter(t_complex z, t_complex c)
{
	int	it;

	it = 0;
	while (it < MAX_IT && cpx_abs2(z) <= 4.0)
	{
		z = cpx_add(cpx_sqr(z), c);
		it++;
	}
	return (it);
}
