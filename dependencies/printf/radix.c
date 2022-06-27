/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 07:03:35 by ghelman           #+#    #+#             */
/*   Updated: 2022/01/13 07:03:35 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "radix.h"
#include "vector.h"
#include "char.h"
#include <stdlib.h>

t_radixified_integer	radixify_integer(int divident, int base)
{
	t_radixified_integer	result;

	result.digit = divident % base;
	result.rest = divident / base;
	if (divident >= 0 && result.digit < 0)
	{
		result.rest++;
		result.digit -= divident;
	}
	if (result.digit < 0)
		result.digit = -result.digit;
	return (result);
}

int	print_decimal_integer(int integer)
{
	t_character_vector		v;
	t_radixified_integer	r;

	if (integer == 0)
		return (write_one(1, '0'));
	if (integer < 0)
	{
		if (write_one(1, '-') == -1)
			return (-1);
	}
	initialize_vector(&v);
	r = radixify_integer(integer, 10);
	while (r.rest != 0 || r.digit != 0)
	{
		vector_add_character(&v, r.digit + '0');
		r = radixify_integer(r.rest, 10);
	}
	if (write_reverse_character_vector(v) == -1)
	{
		free(v.it);
		return (-1);
	}
	free(v.it);
	return (v.consumed + (integer < 0));
}
