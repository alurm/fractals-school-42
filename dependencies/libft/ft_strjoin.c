/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:15 by ghelman           #+#    #+#             */
/*   Updated: 2021/11/15 17:17:16 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s3;
	const size_t	s1_cap = ft_strlen(s1);
	const size_t	s2_cap = ft_strlen(s2);
	const size_t	s3_cap = s1_cap + s2_cap;

	if (s3_cap < s1_cap || s3_cap + 1 < s3_cap)
		return (NULL);
	s3 = malloc(s3_cap + 1);
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, s1, s3_cap + 1);
	ft_strlcpy(s3 + s1_cap, s2, s3_cap - s1_cap + 1);
	return (s3);
}
