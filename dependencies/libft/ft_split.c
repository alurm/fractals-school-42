/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:15 by ghelman           #+#    #+#             */
/*   Updated: 2021/11/15 17:17:16 by ghelman          ###   ########.fr       */
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

static size_t	ft_skip(const char *str, char sep, int inword)
{
	size_t	res;

	res = 0;
	while (str[res])
	{
		if (inword)
		{
			if (str[res] == sep)
				break ;
		}
		else
		{
			if (str[res] != sep)
				break ;
		}
		res++;
	}
	return (res);
}

static size_t	ft_count_words(const char *str, char sep)
{
	size_t	res;
	size_t	skipped;
	size_t	prev;

	res = 0;
	prev = 1;
	while (1)
	{
		skipped = ft_skip(str, sep, res % 2);
		if (skipped == 0 && prev == 0)
		{
			res--;
			break ;
		}
		str += skipped;
		prev = skipped;
		res++;
	}
	res /= 2;
	return (res);
}

static int	ft_fill_tab(char **res, const char *str, char sep, size_t words)
{
	size_t	i;
	size_t	cap;
	size_t	j;

	i = 0;
	while (i < words)
	{
		str += ft_skip(str, sep, 0);
		cap = ft_skip(str, sep, 1);
		res[i] = ft_strndup(str, cap);
		if (res[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(res[i]);
				j++;
			}
			return (0);
		}
		str += cap;
		i++;
	}
	res[i] = NULL;
	return (1);
}

char	**ft_split(const char *str, char sep)
{
	size_t		words;
	char		**res;

	words = ft_count_words(str, sep);
	res = malloc(sizeof(*res) * (words + 1));
	if (res == NULL)
		return (NULL);
	if (!ft_fill_tab(res, str, sep, words))
	{
		free(res);
		return (NULL);
	}
	return (res);
}
