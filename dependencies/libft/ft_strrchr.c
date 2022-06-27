/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:15 by ghelman           #+#    #+#             */
/*   Updated: 2021/11/15 17:17:15 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int i)
{
	size_t		cap;
	const char	c = i;
	size_t		count;

	cap = ft_strlen(str);
	count = 0;
	while (count < cap)
	{
		if (str[cap - count] == c)
			return ((char *)(str + cap - count));
		count++;
	}
	if (str[cap - count] == c)
		return ((char *)(str + cap - count));
	return (NULL);
}
