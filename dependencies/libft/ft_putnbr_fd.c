/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:16 by ghelman           #+#    #+#             */
/*   Updated: 2021/11/15 17:17:16 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power10(size_t n)
{
	int	res;

	res = 1;
	while (n)
	{
		res *= 10;
		n--;
	}
	return (res);
}

void	ft_putnbr_fd(int n, int fd)
{
	const int	sign = (n > 0) * 2 - 1;
	int			div;

	if (n < 0)
		ft_putchar_fd('-', fd);
	div = ft_power10(ft_len_dec(n) - 1 - (n < 0));
	while (div)
	{
		ft_putchar_fd((n / div) % 10 * sign + '0', fd);
		div /= 10;
	}
}
