/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pestell2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:38:50 by pestell2          #+#    #+#             */
/*   Updated: 2026/04/27 10:54:54 by pestell2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Writes a 32-bit color into the MLX image buffer. */
void	img_putpx(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->pixels + (y * img->line + x * (img->bpp / 8));
	*(unsigned int *)dst = (unsigned int)color;
}

/* Maps a screen pixel to a point in the complex plane. */
t_complex	screen_to_complex(t_view *v, int x, int y)
{
	t_complex	z;
	double		r;
	double		i;

	r = v->min_r + (double)x * (v->max_r - v->min_r) / (double)(W - 1);
	i = v->max_i - (double)y * (v->max_i - v->min_i) / (double)(H - 1);
	z.r = r;
	z.i = i;
	return (z);
}
