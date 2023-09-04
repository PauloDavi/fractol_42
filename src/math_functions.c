/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 01:21:44 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/07/18 01:41:47 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline t_float	normalize(t_float value, t_float min, t_float max)
{
	t_float	normalized;
	t_float	scaled;

	normalized = value / (SIZE - 1);
	scaled = (normalized * (max - min)) + min;
	return (scaled);
}
