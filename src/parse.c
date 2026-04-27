/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pestell2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:36:35 by pestell2          #+#    #+#             */
/*   Updated: 2026/04/27 10:44:18 by pestell2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Simple string equal. */
static int	str_eq(const char *a, const char *b)
{
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}
	return (*a == 0 && *b == 0);
}

/* CLI: ./fractol mandelbrot | ./fractol julia <re> <im> */
int	parse_args(int ac, char **av, t_app *app)
{
	double	re;
	double	im;

	if (ac == 2 && str_eq(av[1], "mandelbrot"))
	{
		app->type = F_MANDELBROT;
		return (1);
	}
	if (ac == 4 && str_eq(av[1], "julia") && str_to_double(av[2], &re)
		&& str_to_double(av[3], &im))
	{
		app->type = F_JULIA;
		app->julia_c.r = re;
		app->julia_c.i = im;
		return (1);
	}
	if (ac == 2 && str_eq(av[1], "burning_ship"))
	{
    		app->type = F_BURNING_SHIP;
    		return (1);
	}
	return (0);
}

/* Usage text, as required by the subject. */
void	print_usage(void)
{
	write(1, "Usage:\n", 7);
	write(1, "  ./fractol mandelbrot\n", 23);
	write(1, "  ./fractol julia <re> <im>\n", 28);
	write(1, "  ./fractol burning_ship\n", 25);
}
