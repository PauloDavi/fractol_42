/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:21:42 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/07/18 01:22:20 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_fractol *fractol, t_movement movement)
{
	t_float	step;
	int		multiply;

	multiply = 1;
	step = (fractol->limits.y_max - fractol->limits.y_min) * MOVE_STEP;
	if (movement == DOWN_MOVE || movement == LEFT_MOVE)
		multiply = -1;
	if (movement == UP_MOVE || movement == DOWN_MOVE)
	{
		fractol->limits.y_min += multiply * step;
		fractol->limits.y_max += multiply * step;
	}
	else if (movement == RIGHT_MOVE || movement == LEFT_MOVE)
	{
		fractol->limits.x_min += multiply * step;
		fractol->limits.x_max += multiply * step;
	}
	render(fractol);
}

void	zoom(t_fractol *f, t_float zoom)
{
	t_float	center_r;
	t_float	center_i;

	center_r = f->limits.x_min - f->limits.x_max;
	center_i = f->limits.y_max - f->limits.y_min;
	f->limits.x_max += (center_r - zoom * center_r) / 2;
	f->limits.x_min = f->limits.x_max + zoom * center_r;
	f->limits.y_min += (center_i - zoom * center_i) / 2;
	f->limits.y_max = f->limits.y_min + zoom * center_i;
	render(f);
}

void	reset_view(t_fractol *fractol)
{
	int		mult;
	t_float	offset;

	offset = 0;
	mult = 1;
	if (fractol->type == MANDELBROT)
	{
		fractol->limits.x_min = -2.0;
		fractol->limits.x_max = 1.0;
		fractol->limits.y_min = -1.5;
		fractol->limits.y_max = 1.5;
	}
	else
	{
		if (fractol->type == MANDELBOX)
			mult = 2;
		else if (fractol->type == BURNING_SHIP)
			offset = -0.5;
		fractol->limits.x_min = (mult * -2.0) + offset;
		fractol->limits.x_max = (mult * 2.0) + offset;
		fractol->limits.y_min = (mult * -2.0) - offset;
		fractol->limits.y_max = (mult * 2.0) - offset;
	}
	render(fractol);
}
