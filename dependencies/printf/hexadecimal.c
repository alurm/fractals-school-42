/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 07:06:52 by ghelman           #+#    #+#             */
/*   Updated: 2022/01/13 07:06:52 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "char.h"
#include <stdlib.h>

int	lowercase_print_hexadecimal_long(unsigned long n)
{
	t_character_vector	v;
	int					to_write;
	const char			set[] = "0123456789abcdef";

	if (n == 0)
		return (write_one(1, '0'));
	initialize_vector(&v);
	while (n != 0)
	{
		vector_add_character(&v, set[n % 16]);
		n /= 16;
	}
	to_write = v.consumed;
	if (write_reverse_character_vector(v) == -1)
	{
		free(v.it);
		return (-1);
	}
	free(v.it);
	return (to_write);
}

int	lowercase_print_hexadecimal(unsigned int n)
{
	t_character_vector	v;
	int					to_write;
	const char			set[] = "0123456789abcdef";

	if (n == 0)
		return (write_one(1, '0'));
	initialize_vector(&v);
	while (n != 0)
	{
		vector_add_character(&v, set[n % 16]);
		n /= 16;
	}
	to_write = v.consumed;
	if (write_reverse_character_vector(v) == -1)
	{
		free(v.it);
		return (-1);
	}
	free(v.it);
	return (to_write);
}

int	uppercase_print_hexadecimal(unsigned int n)
{
	t_character_vector	v;
	int					to_write;
	const char			set[] = "0123456789ABCDEF";

	if (n == 0)
		return (write_one(1, '0'));
	initialize_vector(&v);
	while (n != 0)
	{
		vector_add_character(&v, set[n % 16]);
		n /= 16;
	}
	to_write = v.consumed;
	if (write_reverse_character_vector(v) == -1)
	{
		free(v.it);
		return (-1);
	}
	free(v.it);
	return (to_write);
}
