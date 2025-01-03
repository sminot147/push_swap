/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:34:44 by sminot            #+#    #+#             */
/*   Updated: 2025/01/03 16:42:27 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_a_and_sort_last_three(t_stack *a, t_stack *b)
{
	while (a->top >= 3)
		pb(a, b);
	if (index_of_max(a) == 2)
		ra(a);
	else if (index_of_max(a) == 1)
		rra(a);
	if (index_of_min(a) != a->top)
		sa(a);
}

void	stupid_sort(t_stack *a, t_stack *b)
{
	int	i;

	while (b->top != -1)
	{
		i = where_should_b_top_be(a, b);
		if (a->top - i > i)
			while (--i >= 0)
				rra(a);
		else
			while (i++ <= a->top)
				ra(a);
		pa(a, b);
	}
	i = index_of_max(a);
	if (a->top - i > i)
		while (--i >= 0)
			rra(a);
	else
		while (i++ <= a->top)
			ra(a);
}
