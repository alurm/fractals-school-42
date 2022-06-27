/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 06:57:42 by ghelman           #+#    #+#             */
/*   Updated: 2022/01/13 06:57:56 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"
#include "vector.h"
#include <unistd.h>

void	memory_copy(char *to, char *from, size_t size)
{
	while (size--)
		to[size] = from[size];
}

int	write_one(int descriptor, char character)
{
	int	written;

	written = 0;
	while (written == 0)
		written = write(descriptor, &character, 1);
	return (written);
}

int	string_length(char *string)
{
	int	result;

	result = 0;
	while (string[result])
	{
		result++;
	}
	return (result);
}

int	print_string(char *string)
{
	t_character_vector	v;

	v.it = string;
	v.consumed = string_length(string);
	return (write_character_vector(v));
}

int	print_string_printf(char *string)
{
	if (string == NULL)
		return (print_string("(null)"));
	return (print_string(string));
}
