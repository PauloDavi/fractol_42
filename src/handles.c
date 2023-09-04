/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:19:45 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/07/18 02:08:29 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

static void	handle_keys(int keycode, t_fractol *fractol)
{
	if (keycode >= KEY_1 && keycode <= KEY_5)
		shift_frac(fractol, keycode - KEY_1);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move(fractol, UP_MOVE);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move(fractol, DOWN_MOVE);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move(fractol, RIGHT_MOVE);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move(fractol, LEFT_MOVE);
	else if (keycode == KEY_Z)
		zoom(fractol, ZOOM_IN);
	else if (keycode == KEY_X)
		zoom(fractol, ZOOM_OUT);
	else if (keycode == KEY_R)
		reset_view(fractol);
	else if (keycode == KEY_SPACE)
		shift_color(fractol, -1);
	else if (keycode == KEY_H)
		show_help(fractol);
}

int	key_hook_handle(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ESCAPE)
		clean_exit(fractol, EXIT_SUCCESS);
	if (!fractol->help_is_active)
		handle_keys(keycode, fractol);
	else if (keycode == KEY_H)
	{
		fractol->help_is_active = false;
		render(fractol);
	}
	return (0);
}

int	close_hook_handle(t_fractol *fractol)
{
	clean_exit(fractol, EXIT_SUCCESS);
	return (0);
}

int	mouse_hook_handle(int mouse_keycode, int x, int y, t_fractol *f)
{
	t_float	zr;
	t_float	zi;
	t_float	offset_x;
	t_float	offset_y;

	if (mouse_keycode == 4 || mouse_keycode == 5)
	{
		zr = normalize(x, f->limits.x_min, f->limits.x_max);
		zi = normalize(y, f->limits.y_max, f->limits.y_min);
		offset_x = zr - (f->limits.x_max + f->limits.x_min) / 2;
		offset_y = zi - (f->limits.y_max + f->limits.y_min) / 2;
		f->limits.x_max += offset_x;
		f->limits.x_min += offset_x;
		f->limits.y_max += offset_y;
		f->limits.y_min += offset_y;
		if (mouse_keycode == 4)
			zoom(f, ZOOM_IN);
		else if (mouse_keycode == 5)
			zoom(f, ZOOM_OUT);
	}
	else if (f->type == JULIA)
		julia_shift(x, y, f);
	return (0);
}
