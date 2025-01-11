/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:34:44 by sminot            #+#    #+#             */
/*   Updated: 2025/01/11 08:33:42 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	start_sort(t_stack *a, t_stack *b)
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

static void	sort_the_best_nb(t_stack *a, t_stack *b, int index)
{
	int	i;
	int	min_action;

	i = 3;
	min_action = min(min(b->nb_action[index][4], b->nb_action[index][5]),
			min(b->nb_action[index][6], b->nb_action[index][7]));
	while (b->nb_action[index][++i] != min_action)
		;
	if (i == 4)
		sort_with_rr(a, b, index);
	if (i == 5)
		sort_with_rrr(a, b, index);
	if (i == 6)
		sort_with_ra_rrb(a, b, index);
	if (i == 7)
		sort_with_rra_rb(a, b, index);
	pa(a, b);
}

void	sort(t_stack *a, t_stack *b)
{
	int	i;

	start_sort(a, b);
	while (b->top != -1)
	{
		calc_nb_action(a, b);
		sort_the_best_nb(a, b, index_min_action(b));
	}
	i = max_index(a->value, a->top);
	if (a->top - i > i)
		while (--i >= 0)
			rra(a);
	else
		while (i++ <= a->top)
			ra(a);
}
