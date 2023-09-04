/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 01:46:14 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/09/04 20:39:04 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void	parse_julia_factor(t_fractol *fractol, char **argv)
{
	fractol->cr = ft_atof(argv[2]);
	fractol->ci = ft_atof(argv[3]);
	if (fractol->cr == -42 || fractol->ci == -42)
		error_message();
}
