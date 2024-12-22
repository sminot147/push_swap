/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:57:03 by sminot            #+#    #+#             */
/*   Updated: 2024/12/22 15:59:24 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	temp;

	if (a->top > 0)
	{
		temp = a->value[a->top];
		a->value[a->top] = a->value[a->top - 1];
		a->value[a->top - 1] = temp;
	}
	putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	int	temp;

	if (b->top > 0)
	{
		temp = b->value[b->top];
		b->value[b->top] = b->value[b->top - 1];
		b->value[b->top - 1] = temp;
	}
	putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	int	temp;

	if (a->top > 0)
	{
		temp = a->value[a->top];
		a->value[a->top] = a->value[a->top - 1];
		a->value[a->top - 1] = temp;
	}
	if (b->top > 0)
	{
		temp = b->value[b->top];
		b->value[b->top] = b->value[b->top - 1];
		b->value[b->top - 1] = temp;
	}
	putstr_fd("ss\n", 1);
}
