/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:15 by ghelman           #+#    #+#             */
/*   Updated: 2021/11/15 17:17:15 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *sv, const void *tv, size_t cap)
{
	const unsigned char	*us = sv;
	const unsigned char	*ut = tv;
	size_t				i;

	if (cap == 0)
		return (0);
	i = 0;
	while (i < cap)
	{
		if (us[i] != ut[i])
		{
			if (us[i] > ut[i])
				return (us[i] - ut[i]);
			else
				return (-(ut[i] - us[i]));
		}
		i++;
	}
	return (0);
}
