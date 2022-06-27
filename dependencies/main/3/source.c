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

void	center_range_on(t_range *old, double x)
{
	const double	size = range_size(old);

	old->min = x - size / 2;
	old->max = x + size / 2;
}

void	center_view_on(t_view *old, t_complex point)
{
	center_range_on(old->width, point.x);
	center_range_on(old->height, point.y);
}

void	dispatch_x_button_left(t_data *data, t_mandelbrot *m, int x, int y)
{
	const t_complex	m_new
		= convert_point_between_views(
			data->x->image->view,
			m->view,
			(t_complex){
			.x = x,
			.y = y,
		}
			);

	center_view_on(m->view, m_new);
	if (m->draw_on_change)
		draw_and_display_mandelbrot(data);
}

void	dispatch_x_button_right(t_data *data, t_mandelbrot *m, int x, int y)
{
	data->mandelbrot->julia_options->c
		= convert_point_between_views(
			data->x->image->view,
			m->view,
			(t_complex){
			.x = x,
			.y = y,
		}
			);
	data->mandelbrot->type = fractal_julia;
	if (data->mandelbrot->draw_on_change)
		draw_and_display_mandelbrot(data);
}

void	dispatch_x_button_down(t_data *data)
{
	view_multiply(data->mandelbrot->view, 0.5);
	if (data->mandelbrot->draw_on_change)
		draw_and_display_mandelbrot(data);
}
