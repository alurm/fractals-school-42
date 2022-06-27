/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:15 by ghelman           #+#    #+#             */
/*   Updated: 2021/11/15 17:17:16 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_mb_put_minus(int n, char *s);

char	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	size_t	rem;
	size_t	i;
	size_t	inserted;

	len = ft_len_dec(n);
	res = malloc(len + 1);
	if (res == NULL)
		return (NULL);
	inserted = 0;
	inserted += ft_mb_put_minus(n, res);
	i = 0;
	while (i + inserted < len)
	{
		rem = n % 10 * (n > 0) - (n < 0) * (n % 10);
		res[len - i - 1] = rem + '0';
		n /= 10;
		i++;
	}
	res[len] = '\0';
	return (res);
}

size_t	ft_len_dec(int n)
{
	size_t	res;

	res = 1;
	if (n < 0)
	{
		res++;
		while (n < -9)
		{
			n /= 10;
			res++;
		}
	}
	else
	{
		while (n > 9)
		{
			n /= 10;
			res++;
		}
	}
	return (res);
}

size_t	ft_mb_put_minus(int n, char *s)
{
	if (n < 0)
	{
		*s = '-';
		return (1);
	}
	return (0);
}
