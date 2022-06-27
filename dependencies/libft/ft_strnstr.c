/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:15 by ghelman           #+#    #+#             */
/*   Updated: 2021/11/15 17:17:15 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_strnstr(const char *big, const char *lil, size_t cap)
{
	size_t	i;
	size_t	lilcap;

	if (*lil == '\0')
		return ((char *)big);
	i = 0;
	lilcap = ft_strlen(lil);
	if (lilcap > cap)
		return (NULL);
	while (i <= cap - lilcap && big[i])
	{
		if (ft_strncmp(big + i, lil, ft_min(lilcap, cap - i)) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
