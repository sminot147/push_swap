/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 14:34:44 by sminot            #+#    #+#             */
/*   Updated: 2024/12/22 16:26:30 by sminot           ###   ########.fr       */
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
	if (index_of_min(a) == 1)
		sa(a);
}
