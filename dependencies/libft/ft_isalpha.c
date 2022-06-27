/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:17:14 by ghelman           #+#    #+#             */
/*   Updated: 2021/11/15 17:17:14 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Assume "C" locale and ASCII. */
static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

/* Assume "C" locale and ASCII. */
static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

/* Assume "C" locale. */
int	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
