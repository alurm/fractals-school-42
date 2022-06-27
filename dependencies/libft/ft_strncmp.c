/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:15 by ghelman           #+#    #+#             */
/*   Updated: 2021/11/15 17:17:15 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s, const char *t, size_t cap)
{
	size_t				i;
	const unsigned char	*us = (const unsigned char *)s;
	const unsigned char	*ut = (const unsigned char *)t;

	i = 0;
	while (i < cap && us[i] && ut[i])
	{
		if (us[i] != ut[i])
			return ((us[i] > ut[i]) - 1 * (us[i] < ut[i]));
		i++;
	}
	if (i < cap && us[i] != ut[i])
		return ((us[i] > ut[i]) - 1 * (us[i] < ut[i]));
	return (0);
}
