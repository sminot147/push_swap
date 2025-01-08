/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_with.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:44:46 by sminot            #+#    #+#             */
/*   Updated: 2025/01/08 15:56:13 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_with_rr(t_stack *a, t_stack *b, int nb_to_sort)
{
	int	nb_rr;
	int	nb_ra;
	int	nb_rb;

	nb_rr = min(b->nb_action[nb_to_sort][0], b->nb_action[nb_to_sort][2]);
	nb_ra = b->nb_action[nb_to_sort][0] - nb_rr;
	nb_rb = b->nb_action[nb_to_sort][2] - nb_rr;
	while (nb_rr--)
		rr(a, b);
	while (nb_ra--)
		ra(a);
	while (nb_rb--)
		rb(b);
}

void	sort_with_rrr(t_stack *a, t_stack *b, int nb_to_sort)
{
	int	nb_rrr;
	int	nb_rra;
	int	nb_rrb;

	nb_rrr = min(b->nb_action[nb_to_sort][1], b->nb_action[nb_to_sort][3]);
	nb_rra = b->nb_action[nb_to_sort][1] - nb_rrr;
	nb_rrb = b->nb_action[nb_to_sort][3] - nb_rrr;
	while (nb_rrr--)
		rrr(a, b);
	while (nb_rra--)
		rra(a);
	while (nb_rrb--)
		rrb(b);
}

void	sort_with_ra_rrb(t_stack *a, t_stack *b, int nb_to_sort)
{
	int	nb_ra;
	int	nb_rrb;

	nb_ra = b->nb_action[nb_to_sort][0];
	nb_rrb = b->nb_action[nb_to_sort][3];
	while (nb_ra--)
		ra(a);
	while (nb_rrb--)
		rrb(b);
}

void	sort_with_rra_rb(t_stack *a, t_stack *b, int nb_to_sort)
{
	int	nb_rra;
	int	nb_rb;

	nb_rra = b->nb_action[nb_to_sort][1];
	nb_rb = b->nb_action[nb_to_sort][2];
	while (nb_rra--)
		rra(a);
	while (nb_rb--)
		rb(b);
}
