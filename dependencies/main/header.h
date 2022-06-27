/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 06:37:49 by ghelman           #+#    #+#             */
/*   Updated: 2022/06/27 07:09:54 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

// Optional: separate for different headers.
# include <mlx/mlx.h>
# include <libft/libft.h>
# include <printf/formatted_print.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>

typedef struct s_range {
	double	min;
	double	max;
}	t_range;

typedef struct s_view {
	t_range	*width;
	t_range	*height;
}	t_view;

typedef struct s_x_image {
	void	*handle;
	char	*bytes;
	int		pixel_size;
	int		line_size;
	int		is_big_endian;
	t_view	*view;
}	t_x_image;

typedef struct s_x_window {
	void	*handle;
	int		width;
	int		height;
}	t_x_window;

typedef struct s_x {
	void		*connection;
	t_x_image	*image;
	t_x_window	*window;
}	t_x;

enum e_fractal {
	fractal_julia,
	fractal_mandelbrot,
};

typedef struct s_pixel {
	int	x;
	int	y;
	int	color;
}	t_pixel;

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_complex {
	double	x;
	double	y;
}	t_complex;

// Optional: create union u_fractal_options and use it.

typedef struct s_julia_options {
	t_complex	c;
}	t_julia_options;

// Optional: rename t_mandelbrot to t_fractal.
typedef struct s_mandelbrot {
	int				iterations;
	bool			draw_on_change;
	bool			frame_only;
	bool			funny_colors;
	enum e_fractal	type;
	t_view			*view;
	t_julia_options	*julia_options;
}	t_mandelbrot;

typedef struct s_data {
	t_x				*x;
	t_mandelbrot	*mandelbrot;
	int				exit_code;
}	t_data;

void		draw_and_display_mandelbrot(t_data *data);
void		view_multiply(t_view *v, double by);
void		_draw_pixel(t_x_image *image, t_pixel *pixel);
void		draw_pixel(t_x *x, t_pixel *pixel);
void		draw_square(t_x *x, t_point *point, t_point *dimensions, int color);
double		range_size(t_range *range);
void		range_shift(t_range *range, double by);
t_complex	convert_point_between_views(
				t_view *from,
				t_view *to,
				t_complex point
				);
t_complex	mandelbrot_z_next(t_data *data, t_complex z, t_complex point);
int			mandelbrot_how_many_iterations_passed(
				t_data *data,
				t_complex point,
				int max_iterations
				);
int			mandelbrot_color(t_data *data, t_complex point);
void		draw_mandelbrot(t_data *data);
int			dispatch_x_button(int button, int x, int y, t_data *data);
void		toggle(bool *b);
void		view_multiply(t_view *v, double by);
void		usage(void);
int			dispatch_x_key(int key, t_data *data);
void		draw_and_display_mandelbrot(t_data *data);
int			main(int argc, char **argv);
void		rest(t_data *data);
void		command_usage(void);
void		dispatch_x_button_left(t_data *data, t_mandelbrot *m, int x, int y);
void		dispatch_x_button_right(
				t_data *data,
				t_mandelbrot *m,
				int x,
				int y
				);
void		dispatch_x_button_down(t_data *data);
void		handle_arguments(t_data *data, int argc, char **argv);
void		fill_data(t_data *data);

// External.

void		free(void *pointer);

#endif
