/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:14 by ghelman           #+#    #+#             */
/*   Updated: 2021/11/15 17:17:14 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t cap)
{
	size_t	i;

	i = 0;
	while (i + 1 < cap && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (cap != 0)
		dst[i] = '\0';
	return (i + ft_strlen(src + i));
}
