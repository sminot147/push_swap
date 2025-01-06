/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:48:36 by sminot            #+#    #+#             */
/*   Updated: 2025/01/06 23:03:12 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	index_min_action(t_stack *b)
{
	int	min;
	int	index_of_min;
	int	i;

	min = INT_MAX;
	i = -1;
	while (++i <= b->top)
	{
		if (b->nb_action[i][8] < min)
		{
			min = b->nb_action[i][8];
			index_of_min = i;
		}
	}
	return (index_of_min);
}

int	index_should_nb_be(t_stack *a, int nb)
{
	int	i;
	int	val_before_i;
	int	val_i;
	int	max_ind;

	i = -1;
	max_ind = max_index(a->value, a->top);
	while (++i <= a->top)
	{
		if (i != 0)
			val_before_i = a->value[i - 1];
		else
			val_before_i = a->value[a->top];
		val_i = a->value[i];
		if (i != max_ind && val_before_i > nb && nb > val_i)
			return (i);
	}
	if (nb < a->value[0])
		return (min_index(a->value, a->top) + 1);
	return (max_ind);
}
