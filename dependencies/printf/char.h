/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 06:57:45 by ghelman           #+#    #+#             */
/*   Updated: 2022/01/13 06:57:56 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_H
# define CHAR_H

# include <stddef.h>

void	memory_copy(char *to, char *from, size_t size);
int		write_one(int descriptor, char character);
int		string_length(char *string);
int		print_string(char *string);
int		print_string_printf(char *string);

#endif
