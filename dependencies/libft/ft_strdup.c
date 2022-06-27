/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:15 by ghelman           #+#    #+#             */
/*   Updated: 2021/11/15 17:17:15 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*t;
	size_t	i;
	size_t	cap;

	cap = ft_strlen(s);
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
