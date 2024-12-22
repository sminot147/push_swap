/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:55:05 by sminot            #+#    #+#             */
/*   Updated: 2024/12/22 15:59:44 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int	temp;
	int	i;

	if (a->top > 0)
	{
		temp = a->value[a->top];
		i = -1;
		while (++i < a->top)
			a->value[a->top - i] = a->value[a->top - 1 - i];
		a->value[0] = temp;
	}
	putstr_fd("ra\n", 1);
}

void	rb(t_stack *b)
{
	int	temp;
	int	i;

	if (b->top > 0)
	{
		temp = b->value[b->top];
		i = -1;
		while (++i < b->top)
			b->value[b->top - i] = b->value[b->top - 1 - i];
		b->value[0] = temp;
	}
	putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	if (a->top > 0)
	{
		temp = a->value[a->top];
		i = -1;
		while (++i < a->top)
			a->value[a->top - i] = a->value[a->top - 1 - i];
		a->value[0] = temp;
	}
	if (b->top > 0)
	{
		temp = b->value[b->top];
		i = -1;
		while (++i < b->top)
			b->value[b->top - i] = b->value[b->top - 1 - i];
		b->value[0] = temp;
	}
	putstr_fd("rr\n", 1);
}
