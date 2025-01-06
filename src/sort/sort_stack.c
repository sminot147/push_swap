/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:34:44 by sminot            #+#    #+#             */
/*   Updated: 2025/01/06 23:30:45 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_a_and_sort_last_three(t_stack *a, t_stack *b)
{
	while (a->top >= 3)
		pb(a, b);
	if (max_index(a->value, a->top) == 2)
		ra(a);
	else if (max_index(a->value, a->top) == 1)
		rra(a);
	if (min_index(a->value, a->top) != a->top)
		sa(a);
}

//nb_action[][0] : nb of ra		nb_action[][4] : nb action with rr ra et rb
//nb_action[][1] : nb of rra	nb_action[][5] : nb action with rrr rra et rrb
//nb_action[][2] : nb of rb		nb_action[][6] : nb action with ra et rrb
//nb_action[][3] : nb of rrb	nb_action[][7] : nb action with rra et rb
//nb_action[][8] : min of nb_action
void	calc_nb_action(t_stack *a, t_stack *b)
{
	int	i;
	int	temp;

	i = -1;
	while (++i <= b->top)
	{
		temp = index_should_nb_be(a, b->value[i]);
		b->nb_action[i][0] = a->top - temp + 1;
		b->nb_action[i][1] = temp;
		b->nb_action[i][2] = b->top - i;
		b->nb_action[i][3] = i + 1;
		b->nb_action[i][4] = max(b->nb_action[i][0], b->nb_action[i][2]);
		b->nb_action[i][5] = max(b->nb_action[i][1], b->nb_action[i][3]);
		b->nb_action[i][6] = b->nb_action[i][0] + b->nb_action[i][3];
		b->nb_action[i][7] = b->nb_action[i][1] + b->nb_action[i][2];
		b->nb_action[i][8] = min(b->nb_action[i][4], );
	}
}

void	sort(t_stack *a, t_stack *b)
{
	int	i;

	while (b->top != -1)
	{
		i = index_should_nb_be(a, b->value[b->top]);
		calc_nb_action(a, b);
		print_stacks(a, b);
		if (a->top - i >= i)
			while (--i >= 0)
				rra(a);
		else
			while (i++ <= a->top)
				ra(a);
		pa(a, b);
	}
	i = max_index(a->value, a->top);
	if (a->top - i > i)
		while (--i >= 0)
			rra(a);
	else
		while (i++ <= a->top)
			ra(a);
}
