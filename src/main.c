/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:19:32 by pdavi-al          #+#    #+#             */
/*   Updated: 2023/07/18 01:30:20 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc != 2 && argc != 4)
		error_message();
	chose_fractal(&fractol, argc, argv);
	mlx_key_hook(fractol.win, key_hook_handle, &fractol);
	mlx_mouse_hook(fractol.win, mouse_hook_handle, &fractol);
	mlx_hook(fractol.win, DESTROY_NOTIFY, 0, close_hook_handle, &fractol);
	mlx_loop(fractol.mlx);
	return (EXIT_SUCCESS);
}
