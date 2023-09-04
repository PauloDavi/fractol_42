/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:21:48 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/07/18 01:44:56 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static inline int	calc_iter(t_float zr, t_float zi, t_fractol *fractol)
{
	if (fractol->type == MANDELBROT)
		return (mandelbrot(zr, zi));
	else if (fractol->type == JULIA)
		return (julia(zr, zi, fractol));
	else if (fractol->type == BURNING_SHIP)
		return (burning_ship(zr, zi));
	else if (fractol->type == TRICORN)
		return (tricorn(zr, zi));
	return (mandelbox(zr, zi));
}

void	render(t_fractol *f)
{
	int		x;
	int		y;
	int		iter;
	t_float	zr[SIZE];
	t_float	zi;

	mlx_clear_window(f->mlx, f->win);
	x = -1;
	while (++x < SIZE)
		zr[x] = normalize(x, f->limits.x_min, f->limits.x_max);
	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		zi = normalize(y, f->limits.y_max, f->limits.y_min);
		while (++x < SIZE)
		{
			iter = calc_iter(zr[x], -zi, f) - 1;
			my_mlx_pixel_put(f, x, y, f->colors[f->current_color][iter]);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
