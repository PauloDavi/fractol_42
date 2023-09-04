/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:58:17 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/07/18 01:42:08 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_float	box_fold(t_float value)
{
	if (value > 1)
		value = 2 - value;
	else if (value < -1)
		value = -2 - value;
	return (value);
}

static t_float	ball_fold(t_float c, t_float mag)
{
	if (mag < c * c)
		mag = mag / (c * c);
	else if (mag < 1)
		mag = 1 / mag;
	return (mag);
}

inline int	mandelbox(t_float real, t_float imag)
{
	int		n;
	t_float	zr;
	t_float	zi;
	t_float	mag;

	zr = real;
	zi = imag;
	mag = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		zr = box_fold(zr);
		zi = box_fold(zi);
		mag = zr * zr + zi * zi;
		if (mag > 16)
			break ;
		zr = zr * 2 * ball_fold(-0.5, mag) + real;
		zi = zi * 2 * ball_fold(-0.5, mag) + imag;
		n++;
	}
	return (n);
}
