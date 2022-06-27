/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 07:03:35 by ghelman           #+#    #+#             */
/*   Updated: 2022/01/13 07:03:35 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADIX_H
# define RADIX_H

typedef struct s_radixified_integer
{
	int	digit;
	int	rest;
}		t_radixified_integer;

t_radixified_integer	radixify_integer(int divident, int base);
int						print_decimal_integer(int integer);

#endif
