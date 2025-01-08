/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:48:36 by sminot            #+#    #+#             */
/*   Updated: 2025/01/08 18:58:37 by sminot           ###   ########.fr       */
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

int	futur_index_nb(t_stack *a, int nb)
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

//nb_action[][0] : nb of ra		nb_action[][4] : nb action with rr ra et rb
//nb_action[][1] : nb of rra	nb_action[][5] : nb action with rrr rra et rrb
//nb_action[][2] : nb of rb		nb_action[][6] : nb action with ra et rrb
//nb_action[][3] : nb of rrb	nb_action[][7] : nb action with rra et rb
//nb_action[][8] : min of nb_action + ajustement for middle
void	calc_nb_action(t_stack *a, t_stack *b)
{
	int	i;
	int	temp;

	i = -1;
	while (++i <= b->top)
	{
		temp = futur_index_nb(a, b->value[i]);
		b->nb_action[i][0] = a->top - temp + 1;
		b->nb_action[i][1] = temp;
		b->nb_action[i][2] = b->top - i;
		b->nb_action[i][3] = i + 1;
		b->nb_action[i][4] = max(b->nb_action[i][0], b->nb_action[i][2]);
		b->nb_action[i][5] = max(b->nb_action[i][1], b->nb_action[i][3]);
		b->nb_action[i][6] = b->nb_action[i][0] + b->nb_action[i][3];
		b->nb_action[i][7] = b->nb_action[i][1] + b->nb_action[i][2];
		b->nb_action[i][8] = min(min(b->nb_action[i][4], b->nb_action[i][5]),
				min(b->nb_action[i][6], b->nb_action[i][7]));
		if (a->nb_value_max / 4 < temp && temp < (a->nb_value_max / 4 * 3))
			b->nb_action[i][8] -= min(temp / 50, (a->top - temp) / 50);
	}
}
