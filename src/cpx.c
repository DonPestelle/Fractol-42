/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pestell2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:45:09 by pestell2          #+#    #+#             */
/*   Updated: 2025/08/24 19:45:18 by pestell2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Basic complex operations used by fractal iterations. */
t_complex	cpx_make(double r, double i)
{
	t_complex	z;

	z.r = r;
	z.i = i;
	return (z);
}

t_complex	cpx_add(t_complex a, t_complex b)
{
	return (cpx_make(a.r + b.r, a.i + b.i));
}

t_complex	cpx_sqr(t_complex z)
{
	return (cpx_make(z.r * z.r - z.i * z.i, 2.0 * z.r * z.i));
}

double	cpx_abs2(t_complex z)
{
	return (z.r * z.r + z.i * z.i);
}
