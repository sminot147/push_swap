/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:19:33 by sminot            #+#    #+#             */
/*   Updated: 2024/12/22 13:19:45 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	putstr_fd("pa\n", 1);
	if (b->top == -1)
		return ;
	++a->top;
	a->value[a->top] = b->value[b->top];
	--b->top;
}

void	pb(t_stack *a, t_stack *b)
{
	putstr_fd("pb\n", 1);
	if (a->top == -1)
		return ;
	++b->top;
	b->value[b->top] = a->value[a->top];
	--a->top;
}
