/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pestell2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:38:06 by pestell2          #+#    #+#             */
/*   Updated: 2025/08/24 19:48:11 by pestell2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Reads optional sign. Returns pointer after sign and sets sign value. */
static const char	*read_sign(const char *s, int *sign)
{
	*sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			*sign = -1;
		s++;
	}
	return (s);
}

/* Parses consecutive digits into a double accumulator. */
static const char	*read_uint(const char *s, double *acc)
{
	while (*s >= '0' && *s <= '9')
	{
		*acc = *acc * 10.0 + (double)(*s - '0');
		s++;
	}
	return (s);
}

/* Parses fractional digits after a dot. */
static const char	*read_frac(const char *s, double *frac, double *scale)
{
	while (*s >= '0' && *s <= '9')
	{
		*scale *= 10.0;
		*frac = *frac * 10.0 + (double)(*s - '0');
		s++;
	}
	return (s);
}

/* Converts string to double. Returns 1 on success, 0 otherwise. */
int	str_to_double(const char *s, double *out)
{
	int		sign;
	double	intp;
	double	frac;
	double	scale;

	intp = 0.0;
	frac = 0.0;
	scale = 1.0;
	s = read_sign(s, &sign);
	if (!((*s >= '0' && *s <= '9') || *s == '.'))
		return (0);
	s = read_uint(s, &intp);
	if (*s == '.')
	{
		s++;
		s = read_frac(s, &frac, &scale);
	}
	if (*s != 0)
		return (0);
	*out = sign * (intp + frac / scale);
	return (1);
}
