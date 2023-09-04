/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:21:53 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/07/18 02:13:10 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	clean_exit(t_fractol *fractol, int status)
{
	if (fractol->img.img)
		mlx_destroy_image(fractol->mlx, fractol->img.img);
	if (fractol->win)
		mlx_destroy_window(fractol->mlx, fractol->win);
	if (fractol->mlx)
		mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(status);
}

void	init_fractol(t_fractol *f, t_frac_type type, char *title)
{
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		exit(EXIT_FAILURE);
	f->win = mlx_new_window(f->mlx, SIZE, SIZE, title);
	if (f->win == NULL)
		clean_exit(f, EXIT_FAILURE);
	f->img.img = mlx_new_image(f->mlx, SIZE, SIZE);
	if (f->img.img == NULL)
		clean_exit(f, EXIT_FAILURE);
	f->type = type;
	f->current_color = 0;
	f->help_is_active = false;
	f->cr = -0.4;
	f->ci = -0.6;
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp, &f->img.line_len,
			&f->img.endian);
	create_palettes(f);
	reset_view(f);
}

void	chose_fractal(t_fractol *fractol, int argc, char **argv)
{
	char	*type;

	type = argv[1];
	if (argc == 2)
	{
		if (!ft_strncmp(type, "mandelbrot", ft_strlen(type)))
			init_fractol(fractol, MANDELBROT, "Mandelbrot Set");
		else if (!ft_strncmp(type, "burning_ship", ft_strlen(type)))
			init_fractol(fractol, BURNING_SHIP, "BurningShip Set");
		else if (!ft_strncmp(type, "tricorn", ft_strlen(type)))
			init_fractol(fractol, TRICORN, "Tricorn Set");
		else if (!ft_strncmp(type, "mandelbox", ft_strlen(type)))
			init_fractol(fractol, MANDELBOX, "MandelBox Set");
		else
			error_message();
	}
	else if (!ft_strncmp(type, "julia", ft_strlen(type)))
	{
		init_fractol(fractol, JULIA, "Julia Set");
		parse_julia_factor(fractol, argv);
	}
	else
		error_message();
}

void	shift_frac(t_fractol *fractol, int frac)
{
	fractol->type = frac;
	render(fractol);
}
