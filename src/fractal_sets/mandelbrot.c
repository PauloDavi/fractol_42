/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:58:23 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/07/18 01:49:25 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline int	mandelbrot(t_float real, t_float imag)
{
	int		n;
	t_float	zr;
	t_float	zi;
	t_float	tmp;

	zr = 0;
	zi = 0;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		n++;
		tmp = 2 * zr * zi + imag;
		zr = zr * zr - zi * zi + real;
		zi = tmp;
		if ((zr * zr + zi * zi) > 4.0)
			break ;
	}
	return (n);
}
