/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:14 by ghelman           #+#    #+#             */
/*   Updated: 2021/11/15 17:17:14 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dstv, const void *srcv, size_t cap)
{
	char		*dst;
	const char	*src;
	size_t		i;

	if (cap == 0)
		return (dstv);
	dst = dstv;
	src = srcv;
	i = 0;
	while (i < cap)
	{
		if (srcv > dstv)
			dst[i] = src[i];
		else
			dst[cap - i - 1] = src[cap - i - 1];
		i++;
	}
	return (dstv);
}
