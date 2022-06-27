/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:15 by ghelman           #+#    #+#             */
/*   Updated: 2021/11/15 17:17:16 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_cins(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_skip(const char *str, const char *set)
{
	size_t	res;

	res = 0;
	while (ft_cins(str[res], set))
		res++;
	return (res);
}

static size_t	cutoff(const char *end, const char *set, size_t cap)
{
	size_t	res;

	res = 0;
	while (res < cap)
	{
		end--;
		if (!ft_cins(*end, set))
			break ;
		res++;
	}
	return (res);
}

char	*ft_strtrim(const char *str, const char *set)
{
	size_t		cap;
	const char	*end;
	size_t		skipped;
	char		*res;

	cap = ft_strlen(str);
	end = str + cap;
	skipped = ft_skip(str, set);
	cap -= skipped;
	cap -= cutoff(end, set, cap);
	res = malloc(cap + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, str + skipped, cap + 1);
	return (res);
}
