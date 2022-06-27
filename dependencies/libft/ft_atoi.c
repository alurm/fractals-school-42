/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:15 by ghelman           #+#    #+#             */
/*   Updated: 2021/11/15 17:17:15 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"
#include <limits.h>

/* Assume "C" locale. */
static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v');
}

static int	ft_skip_sign(const char **sp)
{
	const char	c = **sp;

	if (c == '+' || c == '-')
	{
		(*sp)++;
		if (c == '-')
			return (1);
	}
	return (0);
}

static long	ft_atol_nat_sign(const char *s, int neg)
{
	long	limit;
	long	limit_digit;
	long	res;
	int		digit;

	limit = neg * LONG_MIN + !neg * LONG_MAX;
	limit_digit = limit % 10;
	limit /= 10;
	res = 0;
	while (ft_isdigit(*s))
	{
		digit = *s - '0';
		if ((!neg * (res > limit) + neg * (res < limit))
			|| (res == limit && digit == limit_digit))
		{
			if (neg)
				return (LONG_MIN);
			return (LONG_MAX);
		}
		res *= 10;
		res += digit;
		s++;
	}
	return (res * -(neg * 2 - 1));
}

static long	ft_atol(const char *s)
{
	int	neg;

	while (ft_isspace(*s))
		s++;
	neg = ft_skip_sign(&s);
	return (ft_atol_nat_sign(s, neg));
}

int	ft_atoi(const char *s)
{
	return (ft_atol(s));
}
