/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:58:00 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/07/15 22:58:03 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline int	burning_ship(t_float real, t_float imag)
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
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		if (zr < 0)
			zr *= -1.0;
		if (zi < 0)
			zi *= -1.0;
		tmp = 2 * zr * zi + imag;
		zr = zr * zr - zi * zi + real;
		zi = tmp;
		n++;
	}
	return (n);
}
