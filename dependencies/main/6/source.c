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

void	draw_and_display_mandelbrot(t_data *data)
{
	draw_mandelbrot(data);
	mlx_put_image_to_window(
		data->x->connection,
		data->x->window->handle,
		data->x->image->handle,
		0,
		0
		);
}

void	command_usage(void)
{
	ft_printf(
		"[u]sage: show usage\n"
		"[m]andelbrot: show mandelbrot\n"
		"[j]ulia" " "
		"[optional x part after decimal point]" " "
		"[optional y part after decimal point]: show julia\n"
		);
}

// Input: -9876.
// Output: -0.9876.
double	integer_to_proper_fraction(int integer)
{
	int	length;

	length = ft_len_dec(integer);
	if (integer < 0)
		length--;
	return ((double)integer / ft_power10(length));
}

void	handle_arguments(t_data *data, int argc, char **argv)
{
	if (argc < 2 || (argv[1][0] != 'm' && argv[1][0] != 'j'))
	{
		command_usage();
		data->exit_code = 1;
		return ;
	}
	if (argv[1][0] == 'j')
	{
		data->mandelbrot->type = fractal_julia;
		if (argc > 2)
		{
			data->mandelbrot->julia_options->c.x
				= integer_to_proper_fraction(ft_atoi(argv[2]));
			if (argc > 3)
				data->mandelbrot->julia_options->c.y
					= integer_to_proper_fraction(ft_atoi(argv[3]));
		}
	}
	else if (argv[1][0] == 'm')
		data->mandelbrot->type = fractal_mandelbrot;
}

void	fill_data(t_data *data)
{
	data->x->window->height
		= data->x->window->width * (
			range_size(data->mandelbrot->view->height)
			/ range_size(data->mandelbrot->view->width)
			)
		;
	data->x->image->view->width->max = data->x->window->width;
	data->x->image->view->height->max = data->x->window->height;
}
