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

// Optional: math.h not used.
// Optional: complex.h not used.
// Optional: check ft_printf return value.
// Optional: naming.
//   draw_mandelbrot: draws on whole image.
//   draw_square: draws on whole image.
//   draw_pixel: draws on whole image.
//   display: copies whole image to whole window.

// Optional: fix image->pixel_size /= 8; 
int	main(int argc, char **argv)
{
	t_data	*data;

	data = &(t_data){.x = &(t_x){.window = &(t_x_window){.width = 500,},
		.image = &(t_x_image){.view = &(t_view){.width = &(t_range){
		.min = 0,}, .height = &(t_range){.min = 0,},}},},
		.mandelbrot = &(t_mandelbrot){.type = fractal_mandelbrot,
		.iterations = 20, .frame_only = 1, .draw_on_change = 1,
		.funny_colors = 0, .view = &(t_view){.width = &(t_range){.min = -2,
		.max = 0.47,}, .height = &(t_range){.min = -1.12, .max = 1.12,},},
		.julia_options = &(t_julia_options){.c = (t_complex){.x = 0, .y = 1,}},
	},};
	handle_arguments(data, argc, argv);
	if (data->exit_code != 0)
		return (data->exit_code);
	fill_data(data);
	rest(data);
	return (data->exit_code);
}

void	after_connecting(
	t_data *data,
	t_x_image *i,
	void *c,
	t_x_window *w
) {
	usage();
	i->bytes
		= mlx_get_data_addr(i->handle, &i->pixel_size, &i->line_size,
			&i->is_big_endian);
	i->pixel_size /= 8;
	draw_mandelbrot(data);
	mlx_put_image_to_window(c, w->handle, i->handle, 0, 0);
	mlx_hook(w->handle, DestroyNotify, 0, mlx_loop_end, c);
	mlx_hook(w->handle, KeyPress, KeyPressMask, dispatch_x_key, data);
	mlx_hook(w->handle, ButtonPress, ButtonPressMask, dispatch_x_button, data);
	mlx_loop(c);
}

void	try(
	t_data *data,
	t_x_image *i,
	void *c,
	t_x_window *w
) {
	data->x->connection = mlx_init();
	c = data->x->connection;
	if (!c)
		return ;
	w->handle = mlx_new_window(c, w->width, w->height, "Fractol.");
	if (!w->handle)
		return ;
	i->handle = mlx_new_image(c, w->width, w->height);
	if (!i->handle)
		return ;
	after_connecting(data, i, c, w);
}

void	rest(t_data *data)
{
	try(data, data->x->image, data->x->connection, data->x->window);
	if (data->x->image->handle)
		mlx_destroy_image(data->x->connection, data->x->image->handle);
	if (data->x->window->handle)
		mlx_destroy_window(data->x->connection, data->x->window->handle);
	if (data->x->connection)
		free(data->x->connection);
}
