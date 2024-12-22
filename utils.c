/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:49:26 by sminot            #+#    #+#             */
/*   Updated: 2024/12/22 16:01:15 by sminot           ###   ########.fr       */
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
