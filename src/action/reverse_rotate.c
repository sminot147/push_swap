/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:10:07 by sminot            #+#    #+#             */
/*   Updated: 2025/01/08 17:51:30 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->top > 0)
	{
		temp = a->value[0];
		i = -1;
		while (++i < a->top)
			a->value[i] = a->value[i + 1];
		a->value[a->top] = temp;
	}
	putstr_fd("rra\n", 1);
}

void	rrb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->top > 0)
	{
		temp = b->value[0];
		i = -1;
		while (++i < b->top)
			b->value[i] = b->value[i + 1];
		b->value[b->top] = temp;
	}
	putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	if (a->top > 0)
	{
		temp = a->value[0];
		i = -1;
		while (++i < a->top)
			a->value[i] = a->value[i + 1];
		a->value[a->top] = temp;
	}
	if (b->top > 0)
	{
		temp = b->value[0];
		i = -1;
		while (++i < b->top)
			b->value[i] = b->value[i + 1];
		b->value[b->top] = temp;
	}
	putstr_fd("rrr\n", 1);
}
