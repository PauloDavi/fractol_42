/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:19:52 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/07/18 01:56:11 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_info(t_fractol *fractol, int index, char *left_text,
		char *right_text)
{
	mlx_string_put(fractol->mlx, fractol->win, SIZE * 0.25, TEXT_START_Y
		+ ((index + 4) * TEXT_OFFSET), TEXT_COLOR, left_text);
	mlx_string_put(fractol->mlx, fractol->win, SIZE * 0.6, TEXT_START_Y
		+ ((index + 4) * TEXT_OFFSET), TEXT_COLOR, right_text);
}

void	put_text(t_fractol *f)
{
	mlx_string_put(f->mlx, f->win, (SIZE / 2) - 50, TEXT_START_Y, TEXT_COLOR,
		"Manual - fractol");
	print_info(f, 1, "Move:", "WASD | UP,DOWN,LEFT,RIGHT");
	print_info(f, 2, "Zoom In:", "Mouse Wheel Up | z");
	print_info(f, 3, "Zoom Out:", "Mouse Wheel Down | x");
	print_info(f, 4, "Shift Julia Parameter:", "Any Mouse Click");
	print_info(f, 5, "Shift Color:", "SPACE");
	print_info(f, 6, "Select Color:", "1 to 5");
	print_info(f, 7, "Toggle Help Window:", "h");
	print_info(f, 8, "Reset View:", "r");
	print_info(f, 9, "Close:", "ESC");
}

void	show_help(t_fractol *fractol)
{
	int	x;
	int	y;

	fractol->help_is_active = true;
	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			my_mlx_pixel_shade(fractol, x, y);
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
	put_text(fractol);
}

void	error_message(void)
{
	write(1, "Usage: ./fractol <NAME>\n", 24);
	write(1, "Available Fractals:\n", 20);
	write(1, "---> mandelbrot\n", 16);
	write(1, "---> julia <real part> <imaginary part>\n", 40);
	write(1, "---> burning_ship\n", 18);
	write(1, "---> tricorn\n", 13);
	write(1, "---> mandelbox\n", 15);
	exit(EXIT_FAILURE);
}
