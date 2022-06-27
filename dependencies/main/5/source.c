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

void	usage(void)
{
	ft_printf(
		"[u]sage: print usage\n"
		"[i]n: increase iterations\n"
		"[o]ut: decrease iterations\n"
		"[d]raw: toggle draw on change\n"
		"[f]rame: toggle showing only frame\n"
		"funny [c]olors: enable funny colors\n"
		"[r]edraw: redraw\n"
		"[p]rint: print adjustable settings and their values for reproduction\n"
		"[m]andelbrot: see mandelbrot\n"
		"[j]ulia: see julia\n"
		"<left><right><up><down>: controls"
		"<equals>: zoom in\n"
		"<minus>: zoom out\n"
		"<escape>: quit cleanly\n"
		"<left mouse>: center view at this point\n"
		"<right mouse>: select this point for julia\n"
		);
}

void	dispatch_x_key_p(t_data *data)
{
	ft_printf("iterations = %d;\n", data->mandelbrot->iterations);
	ft_printf("frame_only = %d;\n", data->mandelbrot->frame_only);
	ft_printf("draw_on_change = %d;\n", data->mandelbrot->draw_on_change);
}

void	decrement_not_below_one(int *integer)
{
	if (*integer > 1)
		(*integer)--;
}

void	dispatch_x_key_2(int key, t_data *data, t_mandelbrot *m)
{
	if (key == XK_o)
		decrement_not_below_one(&data->mandelbrot->iterations);
	else if (key == XK_f)
		toggle(&data->mandelbrot->frame_only);
	else if (key == XK_r)
		draw_and_display_mandelbrot(data);
	else if (key == XK_equal)
		view_multiply(data->mandelbrot->view, 0.5);
	else if (key == XK_minus)
		view_multiply(data->mandelbrot->view, 2);
	else if (key == XK_Left)
		range_shift(m->view->width, -range_size(m->view->width) * 0.1);
	else if (key == XK_Right)
		range_shift(m->view->width, range_size(m->view->width) * 0.1);
	else if (key == XK_Up)
		range_shift(m->view->height, -range_size(m->view->height) * 0.1);
	else if (key == XK_Down)
		range_shift(m->view->height, range_size(m->view->height) * 0.1);
}

// Optional: XK_p: print here %f (not implemented in ft_printf sadly).
//   julia_options->c for reproducing fractal.
//   also print view.
//   Print bytes instead?
// Optional: XK_equals: how to handle shift key for plus sign?
// Optional: fix occasional useless redrawing (on XK_p, for example).
int	dispatch_x_key(int key, t_data *data)
{
	t_mandelbrot	*m;

	m = data->mandelbrot;
	if (key == XK_u)
		usage();
	else if (key == XK_Escape)
		mlx_loop_end(data->x->connection);
	else if (key == XK_p)
		dispatch_x_key_p(data);
	else if (key == XK_j)
		m->type = fractal_julia;
	else if (key == XK_m)
		m->type = fractal_mandelbrot;
	else if (key == XK_c)
		toggle(&m->funny_colors);
	else if (key == XK_d)
		toggle(&m->draw_on_change);
	else if (key == XK_i)
		data->mandelbrot->iterations++;
	else
		dispatch_x_key_2(key, data, m);
	if (m->draw_on_change)
		draw_and_display_mandelbrot(data);
	return (0);
}
