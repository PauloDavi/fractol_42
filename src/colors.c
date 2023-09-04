/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:19:39 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/07/18 01:40:07 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	interpol(int color1, int color2, float ratio)
{
	int	r;
	int	g;
	int	b;

	r = ((color1 >> 16) & 0xFF) + (int)((((color2 >> 16) & 0xFF)
				- ((color1 >> 16) & 0xFF)) * ratio);
	g = ((color1 >> 8) & 0xFF) + (int)((((color2 >> 8) & 0xFF)
				- ((color1 >> 8) & 0xFF)) * ratio);
	b = (color1 & 0xFF) + (int)(((color2 & 0xFF) - (color1 & 0xFF)) * ratio);
	return ((r << 16) | (g << 8) | b);
}

static void	create_palette(t_fractol *fractol, int pallet, int quant,
		int cols[])
{
	int		interval;
	int		coli;
	float	ratio;
	int		i;

	interval = (MAX_ITERATIONS - 1) / (quant - 1);
	i = -1;
	while (++i < MAX_ITERATIONS)
	{
		coli = i / interval;
		ratio = (i % interval) / (float)interval;
		fractol->colors[pallet][i] = interpol(cols[coli], cols[coli + 1],
				ratio);
	}
	fractol->colors[pallet][i - 1] = 0;
}

void	create_palettes(t_fractol *fractol)
{
	create_palette(fractol, 0, 5,
		(int []){0x000000, 0x0000FF, 0x00FF00, 0xFF0000, 0xFFFFFF});
	create_palette(fractol, 1, 5,
		(int []){0xFF0000, 0xFFFF00, 0x00FF00, 0x00FFFF, 0x0000FF});
	create_palette(fractol, 2, 5,
		(int []){0x7F1637, 0x047878, 0xFFB733, 0xF57336, 0xC22121});
	create_palette(fractol, 3, 5,
		(int []){0x0D1C33, 0x17373C, 0x2B6832, 0x4F9300, 0xA1D700});
	create_palette(fractol, 4, 5,
		(int []){0x002F2F, 0x046380, 0xEFECCA, 0xA7A37E, 0xE6E2AF});
}

void	shift_color(t_fractol *fractol, int color)
{
	if (color != -1)
		fractol->current_color = color;
	else
	{
		if (fractol->current_color == 4)
			fractol->current_color = 0;
		else
			fractol->current_color++;
	}
	render(fractol);
}

inline int	darken_color(int cor)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	red = ((cor >> 16) & 0xFF) * DIMMING_FACTOR;
	green = ((cor >> 8) & 0xFF) * DIMMING_FACTOR;
	blue = (cor & 0xFF) * DIMMING_FACTOR;
	return ((0xFF << 24) | (red << 16) | (green << 8) | blue);
}
