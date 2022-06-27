/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:15 by ghelman           #+#    #+#             */
/*   Updated: 2021/11/15 17:17:15 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_strndup(const char *s, size_t cap)
{
	char	*t;
	size_t	i;

	t = malloc(cap + 1);
	if (t == NULL)
		return (NULL);
	i = 0;
	while (i < cap)
	{
		t[i] = s[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

static char	*ft_strdupcap(const char *s, size_t cap)
{
	size_t	i;

	i = 0;
	while (s[i] && cap)
	{
		cap--;
		i++;
	}
	return (ft_strndup(s, i));
}

char	*ft_substr(char const *str, unsigned int at, size_t max)
{
	size_t	cap;

	cap = ft_strlen(str);
	if (cap < at)
		return (ft_calloc(1, 1));
	str += at;
	return (ft_strdupcap(str, max));
}
