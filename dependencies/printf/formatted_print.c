/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatted_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 12:09:29 by ghelman           #+#    #+#             */
/*   Updated: 2022/01/09 12:14:15 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "formatted_print.h"
#include "vector.h"
#include "char.h"
#include "hexadecimal.h"
#include "radix.h"
#include <stdarg.h>
#include <stdlib.h>

int	print_decimal_natural(unsigned int natural)
{
	t_character_vector	v;
	int					to_write;

	if (natural == 0)
		return (write_one(1, '0'));
	initialize_vector(&v);
	while (natural != 0)
	{
		vector_add_character(&v, natural % 10 + '0');
		natural /= 10;
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

int	print_address(void *address)
{
	unsigned long	natural;

	natural = (unsigned long int)address;
	if (write_one(1, '0') == -1)
		return (-1);
	if (write_one(1, 'x') == -1)
		return (-1);
	return (2 + lowercase_print_hexadecimal_long(natural));
}

int	dispatch_specifier(char character, va_list arguments)
{
	if (character == 'c')
		return (write_one(1, va_arg(arguments, int)));
	else if (character == 's')
		return (print_string_printf(va_arg(arguments, char *)));
	else if (character == 'u')
		return (print_decimal_natural(va_arg(arguments, unsigned int)));
	else if (character == 'd' || character == 'i')
		return (print_decimal_integer(va_arg(arguments, int)));
	else if (character == 'x')
		return (lowercase_print_hexadecimal(va_arg(arguments, unsigned int)));
	else if (character == 'X')
		return (uppercase_print_hexadecimal(va_arg(arguments, unsigned int)));
	else if (character == '%')
		return (write_one(1, '%'));
	else if (character == 'p')
		return (print_address(va_arg(arguments, void *)));
	else
		return (write_one(1, character));
}

int	ft_vprintf(const char *format, va_list arguments)
{
	int		total_written;
	int		written_now;
	char	character;

	total_written = 0;
	while (*format)
	{
		written_now = 0;
		character = *format;
		if (character != '%')
			written_now = write_one(1, character);
		else
		{
			character = *(++format);
			written_now = dispatch_specifier(character, arguments);
		}
		if (written_now == -1)
			return (-1);
		format++;
		total_written += written_now;
	}
	return (total_written);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		result;

	va_start(arguments, format);
	result = ft_vprintf(format, arguments);
	va_end(arguments);
	return (result);
}
