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

// Optional: do not ignore is_big_endian.
void	_draw_pixel(t_x_image *image, t_pixel *pixel)
{
	const char	*line_bytes = image->bytes + pixel->y * image->line_size;
	const char	*at = line_bytes + pixel->x * image->pixel_size;

	*(unsigned int *)at = pixel->color;
}

void	draw_pixel(t_x *x, t_pixel *pixel)
{
	if (
		pixel->x >= 0
		&& pixel->x < x->window->width
		&& pixel->y >= 0
		&& pixel->y < x->window->height
	)
		_draw_pixel(x->image, pixel);
}

void	draw_square(t_x *x, t_point *point, t_point *dimensions, int color)
{
	t_point	*current;

	current = &(t_point)
	{
		.x = point->x,
		.y = point->y,
	};
	while (current->y < point->y + dimensions->y)
	{
		while (current->x < point->x + dimensions->x)
		{
			draw_pixel(x, &(t_pixel)
			{
				.x = current->x,
				.y = current->y,
				.color = color,
			});
			current->x++;
		}
		current->x = point->x;
		current->y++;
	}
}

double	range_size(t_range *range)
{
	return (range->max - range->min);
}

void	range_shift(t_range *range, double by)
{
	range->min += by;
	range->max += by;
}
