/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghelman <ghelman@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 06:47:09 by ghelman           #+#    #+#             */
/*   Updated: 2022/01/13 06:47:09 by ghelman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "char.h"
#include <stdlib.h>

int	write_reverse_character_vector(t_character_vector v)
{
	int	i;

	i = v.consumed;
	while (i--)
	{
		if (write_one(1, v.it[i]) == -1)
			return (-1);
	}
	return (v.consumed);
}

int	write_character_vector(t_character_vector vector)
{
	int	written;

	written = 0;
	while (written < vector.consumed)
	{
		if (write_one(1, vector.it[written]) == -1)
			return (-1);
		written++;
	}
	return (written);
}

void	widen_character_vector(t_character_vector *vector)
{
	char	*old_it;
	int		new_available;

	old_it = vector->it;
	if (vector->available == 0)
		new_available = 1;
	else
	{
		new_available = vector->available * 2;
		if (new_available < vector->available)
		{
			free(old_it);
			return ;
		}
	}
	vector->it = malloc(new_available);
	if (vector->it == NULL)
	{
		free(old_it);
		return ;
	}
	memory_copy(vector->it, old_it, vector->available);
	vector->available = new_available;
	free(old_it);
}

void	initialize_vector(t_character_vector *vector)
{
	vector->it = NULL;
	vector->available = 0;
	vector->consumed = 0;
}

t_character_vector	*vector_add_character(t_character_vector *v, char c)
{
	if (v->consumed == v->available)
	{
		widen_character_vector(v);
		if (v->it == NULL)
			return (NULL);
	}
	v->it[v->consumed++] = c;
	return (v);
}
