/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 06:37:59 by ghelman           #+#    #+#             */
/*   Updated: 2022/06/27 07:19:01 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main/header.h>

t_complex	convert_point_between_views(
	t_view *from,
	t_view *to,
	t_complex point
)
{
	double	width_factor;
	double	height_factor;

	width_factor = range_size(to->width) / range_size(from->width);
	height_factor = range_size(to->height) / range_size(from->height);
	return ((t_complex)
		{
			.x = to->width->min + point.x * width_factor,
			.y = to->height->min + point.y * height_factor,
		});
}

// M = { c in C such that as n approaches to infinity Zn != infinity } where
// z(0) = c
// z(n+1) = z(n) * z(n) + c

// let a = z.x and b = z.y, then
// z^2 =
// (a + bi)^2 =
// (a + bi)(a + bi) =
// a^2 + abi + abi + (bi)^2 =
// a^2 + abi + abi - b^2 =
// (a^2 - b^2) + (2ab)i
t_complex	mandelbrot_z_next(t_data *data, t_complex z, t_complex point)
{
	if (data->mandelbrot->type == fractal_julia)
	{
		point = data->mandelbrot->julia_options->c;
	}
	return ((t_complex)
		{
			.x = (z.x * z.x) - (z.y * z.y) + point.x,
			.y = 2 * z.x * z.y + point.y,
		});
}

int	mandelbrot_how_many_iterations_passed(
	t_data *data,
	t_complex point,
	int max_iterations
) {
	t_complex	z;
	int			current_iteration;

	current_iteration = 0;
	z = point;
	while (current_iteration < max_iterations)
	{
		if (z.x * z.x + z.y * z.y > 4)
			break ;
		z = mandelbrot_z_next(data, z, point);
		current_iteration++;
	}
	return (current_iteration);
}

int	mandelbrot_color(t_data *data, t_complex point)
{
	t_mandelbrot	*m;
	int				color;
	int				how_many_iterations_passed;
	double			ratio;

	m = data->mandelbrot;
	how_many_iterations_passed
		= mandelbrot_how_many_iterations_passed(data, point, m->iterations);
	if (m->frame_only && how_many_iterations_passed == m->iterations)
		color = 0;
	else
	{
		ratio = (double)how_many_iterations_passed / m->iterations;
		if (m->funny_colors)
			color = 0x00BAAAAD * ratio;
		else
			color = 0xFF * ratio;
	}
	return (color);
}

// Optional: how does this work with doubles? IEEE? C standard?
void	draw_mandelbrot(t_data *data)
{
	t_complex	i_point;

	i_point = (t_complex){
		.x = 0,
		.y = 0,
	};
	while (i_point.y < range_size(data->x->image->view->height))
	{
		while (i_point.x < range_size(data->x->image->view->width))
		{
			draw_pixel(data->x,
				&(t_pixel){
				.x = i_point.x, .y = i_point.y, .color = mandelbrot_color(
					data, convert_point_between_views(data->x->image->view,
						data->mandelbrot->view,
						i_point
						)
					),
			}
				);
			i_point.x++;
		}
		i_point.x = 0;
		i_point.y++;
	}
}
