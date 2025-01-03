/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:49:26 by sminot            #+#    #+#             */
/*   Updated: 2025/01/03 15:39:18 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	free_all(t_stack a, t_stack b)
{
	if (a.value)
		free(a.value);
	if (b.value)
		free(b.value);
}

int	index_of_max(t_stack *a)
{
	int	max;
	int	index_of_max;
	int	i;

	max = INT_MIN;
	i = -1;
	while (++i <= a->top)
	{
		if (a->value[i] > max)
		{
			max = a->value[i];
			index_of_max = i;
		}
	}
	return (index_of_max);
}

int	index_of_min(t_stack *a)
{
	int	min;
	int	index_of_min;
	int	i;

	min = INT_MAX;
	i = -1;
	while (++i <= a->top)
	{
		if (a->value[i] < min)
		{
			min = a->value[i];
			index_of_min = i;
		}
	}
	return (index_of_min);
}

int	where_should_b_top_be(t_stack *a, t_stack *b)
{
	int	i;
	int	val_before_i;
	int	val_i;

	i = -1;
	while (++i <= a->top)
	{
		if (i != 0)
			val_before_i = a->value[i - 1];
		else
			val_before_i = a->value[a->top];
		val_i = a->value[i];
		if (i != index_of_max(a) && val_before_i > b->value[b->top] &&
			b->value[b->top] > val_i)
			return (i);
	}
	if (b->value[b->top] < a->value[0])
		return (index_of_min(a) + 1);
	return (index_of_max(a));
}
