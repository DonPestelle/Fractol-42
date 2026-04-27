/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pestell2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:41:43 by pestell2          #+#    #+#             */
/*   Updated: 2026/04/27 10:41:03 by pestell2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define W 1280
# define H 960
# define MAX_IT 50

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct s_img
{
	void		*img;
	char		*pixels;
	int			bpp;
	int			line;
	int			endian;
}				t_img;

typedef struct s_view
{
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
}				t_view;

typedef enum e_type
{
	F_MANDELBROT,
	F_JULIA,
	F_BURNING_SHIP,
}				t_type;

typedef struct s_app
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_view		vp;
	t_type		type;
	t_complex	julia_c;
	int			shift;
}				t_app;

/* complex ops */
t_complex		cpx_make(double r, double i);
t_complex		cpx_add(t_complex a, t_complex b);
t_complex		cpx_sqr(t_complex z);
double			cpx_abs2(t_complex z);
/* parse */
int				parse_args(int ac, char **av, t_app *app);
void			print_usage(void);

/* parse_utils */
int				str_to_double(const char *s, double *out);

/* view */
void			view_init(t_view *v);
void			view_zoom_at(t_view *v, double factor, int x, int y);

/* image + render */
void			img_putpx(t_img *img, int x, int y, int color);
t_complex		screen_to_complex(t_view *v, int x, int y);
void			render(t_app *app);

/* fractals + color */
int				mandelbrot_iter(t_complex c);
int				julia_iter(t_complex z0, t_complex c);
int				colorize(int it);
int 				burning_ship_iter(t_complex c);

/* hooks */
int				close_win(t_app *app);
int				key_press(int key, t_app *app);
int				mouse_hook(int button, int x, int y, t_app *app);

#endif
