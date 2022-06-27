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

void	dispatch_x_button_up(t_data *data)
{
	view_multiply(data->mandelbrot->view, 2);
	if (data->mandelbrot->draw_on_change)
		draw_and_display_mandelbrot(data);
}

int	dispatch_x_button(int button, int x, int y, t_data *data)
{
	t_mandelbrot	*m;

	enum e_buttons
	{
		left = Button1,
		middle = Button2,
		right = Button3,
		down = Button4,
		up = Button5,
	};
	m = data->mandelbrot;
	if (button == left)
		dispatch_x_button_left(data, m, x, y);
	else if (button == right)
		dispatch_x_button_right(data, m, x, y);
	else if (button == down)
		dispatch_x_button_down(data);
	else if (button == up)
		dispatch_x_button_up(data);
	return (0);
}

void	toggle(bool *b)
{
	if (*b == 1)
		*b = 0;
	else
		*b = 1;
}

void	range_center_multiply(t_range *range, double by)
{
	double	side_change;
	double	old_size;
	double	new_size;

	old_size = range_size(range);
	new_size = by * old_size;
	side_change = (old_size - new_size) / 2;
	range->min += side_change;
	range->max -= side_change;
}

void	view_multiply(t_view *v, double by)
{
	range_center_multiply(v->height, by);
	range_center_multiply(v->width, by);
}
