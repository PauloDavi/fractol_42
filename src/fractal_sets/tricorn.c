/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:58:29 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/07/15 22:58:29 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline int	tricorn(t_float real, t_float imag)
{
	int		n;
	t_float	zr;
	t_float	zi;
	t_float	tmp;

	zr = real;
	zi = imag;
	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = -2 * zr * zi + imag;
		zr = zr * zr - zi * zi + real;
		zi = tmp;
		n++;
	}
	return (n);
}
