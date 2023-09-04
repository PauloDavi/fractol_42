/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:58:10 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/07/16 01:34:52 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_shift(int x, int y, t_fractol *f)
{
	f->cr = f->limits.x_min + (double)x * (f->limits.x_max - f->limits.x_min)
		/ SIZE;
	f->ci = f->limits.y_max + (double)y * (f->limits.y_min - f->limits.y_max)
		/ SIZE;
	render(f);
}

inline int	julia(t_float zr, t_float zi, t_fractol *f)
{
	int		n;
	double	tmp;

	n = 0;
	while (n < MAX_ITERATIONS)
	{
		if ((zi * zi + zr * zr) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->ci;
		zr = zr * zr - zi * zi + f->cr;
		zi = tmp;
		n++;
	}
	return (n);
}
