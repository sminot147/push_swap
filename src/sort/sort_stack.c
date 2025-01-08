/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:34:44 by sminot            #+#    #+#             */
/*   Updated: 2025/01/08 16:17:45 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort(t_stack *a, t_stack *b)
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

void	sort_the_best_nb(t_stack *a, t_stack *b, int nb_to_sort)
{
	int	i;

	i = 3;
	//print_stacks(a, b);
	while (b->nb_action[nb_to_sort][++i] != b->nb_action[nb_to_sort][8])
		;
	if (i == 4)
		sort_with_rr(a, b, nb_to_sort);
	if (i == 5)
		sort_with_rrr(a, b, nb_to_sort);
	if (i == 6)
		sort_with_ra_rrb(a, b, nb_to_sort);
	if (i == 7)
		sort_with_rra_rb(a, b, nb_to_sort);
	pa(a, b);
}

void	sort(t_stack *a, t_stack *b)
{
	int	i;

	while (b->top != -1)
	{
		i = futur_index_nb(a, b->value[b->top]);
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
