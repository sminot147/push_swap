/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:49:26 by sminot            #+#    #+#             */
/*   Updated: 2025/01/06 23:26:12 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	free_all(t_stack *a, t_stack *b, int ac)
{
	int	i;

	if (a->value)
		free(a->value);
	if (b->value)
		free(b->value);
	if (b->nb_action)
	{
		i = -1;
		while (++i < ac && b->nb_action[i])
			free(b->nb_action[i]);
		free(b->nb_action);
	}
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min_index(int *tab, int nb_value)
{
	int	min;
	int	min_index;
	int	i;

	min = INT_MAX;
	i = -1;
	while (++i <= nb_value)
	{
		if (tab[i] <= min)
		{
			min = tab[i];
			min_index = i;
		}
	}
	return (min_index);
}

int	max_index(int *tab, int nb_value)
{
	int	max;
	int	max_index;
	int	i;

	max = INT_MIN;
	i = -1;
	while (++i <= nb_value)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			max_index = i;
		}
	}
	return (max_index);
}
