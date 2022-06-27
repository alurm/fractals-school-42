/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 06:49:10 by ghelman           #+#    #+#             */
/*   Updated: 2022/01/13 06:49:10 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_character_vector
{
	char	*it;
	int		available;
	int		consumed;
}		t_character_vector;

void				initialize_vector(t_character_vector *v);
t_character_vector	*vector_add_character(t_character_vector *v, char c);
void				widen_character_vector(t_character_vector *v);
int					write_character_vector(t_character_vector v);
int					write_reverse_character_vector(t_character_vector v);

#endif
