/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:21:34 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/07/17 21:41:41 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline void	my_mlx_pixel_put(t_fractol *f, int x, int y, int color)
{
	char	*pixel;

	pixel = f->img.addr + (y * f->img.line_len + x * (f->img.bpp / 8));
	*(int *)pixel = color;
}

inline void	my_mlx_pixel_shade(t_fractol *f, int x, int y)
{
	char	*pixel;

	pixel = f->img.addr + (y * f->img.line_len + x * (f->img.bpp / 8));
	*(unsigned int *)pixel = darken_color(*(unsigned int *)pixel);
}
