/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdavi-al <pdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 01:12:48 by cobli             #+#    #+#             */
/*   Updated: 2023/07/18 02:12:37 by pdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define SIZE 1000
# define MAX_ITERATIONS 300
# define PALLETS 5
# define ZOOM_OUT 1.25
# define ZOOM_IN 0.8
# define MOVE_STEP 0.1
# define TEXT_START_Y 250
# define TEXT_OFFSET 20
# define DESTROY_NOTIFY 17
# define DIMMING_FACTOR 0.2
# define TEXT_COLOR 0xCCCCCC

typedef double		t_float;

typedef enum e_movement
{
	UP_MOVE,
	DOWN_MOVE,
	LEFT_MOVE,
	RIGHT_MOVE,
}					t_movement;

typedef enum e_frac_type
{
	MANDELBROT,
	JULIA,
	BURNING_SHIP,
	TRICORN,
	MANDELBOX,
}					t_frac_type;

typedef struct s_limit
{
	t_float			x_min;
	t_float			x_max;
	t_float			y_min;
	t_float			y_max;
}					t_limit;

typedef struct s_img_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img_data;

typedef struct s_fractol
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	t_img_data		img;
	t_limit			limits;
	t_frac_type		type;
	t_float			cr;
	t_float			ci;
	unsigned char	current_color;
	int				colors[PALLETS][MAX_ITERATIONS];
	bool			help_is_active;
}					t_fractol;

int					mandelbrot(t_float real, t_float imag);
int					julia(t_float z_real, t_float z_imag, t_fractol *f);
void				julia_shift(int x, int y, t_fractol *f);
int					burning_ship(t_float cr, t_float ci);
int					tricorn(t_float real, t_float imag);
int					mandelbox(t_float cr, t_float ci);
void				parse_julia_factor(t_fractol *fractol, char **argv);

void				shift_color(t_fractol *fractol, int color);
int					darken_color(int cor);
void				create_palettes(t_fractol *fractol);

void				reset_view(t_fractol *fractol);
void				error_message(void);
void				clean_exit(t_fractol *fractol, int status);
void				show_help(t_fractol *fractol);
void				shift_frac(t_fractol *fractol, int frac);

void				chose_fractal(t_fractol *fractol, int argc, char **argv);
void				init_fractol(t_fractol *fractol, t_frac_type type,
						char *title);

void				my_mlx_pixel_put(t_fractol *fractol, int x, int y,
						int color);
void				my_mlx_pixel_shade(t_fractol *fractol, int x, int y);

void				move(t_fractol *fractol, t_movement movement);
void				render(t_fractol *f);
void				zoom(t_fractol *f, t_float zoom);
t_float				normalize(t_float value, t_float min, t_float max);

int					key_hook_handle(int keycode, t_fractol *fractol);
int					mouse_hook_handle(int mouse_keycode, int x, int y,
						t_fractol *fractol);
int					close_hook_handle(t_fractol *fractol);

#endif
