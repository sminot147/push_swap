/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:19:33 by sminot            #+#    #+#             */
/*   Updated: 2024/12/21 18:29:13 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack a, t_stack b)
{
	if (a.top == -1)
	{
		putstr_fd("impossible action\n", 2);
		return (void);
	}
	++b.top;
	b.value[b.top] = a.value[a.top];
	--a.top;
	putstr_fd("pa\n", 1);
}

void	pb(t_stack a, t_stack b)
{
	if (b.top == -1)
	{
		putstr_fd("impossible action\n", 2);
		return (void);
	}
	++a.top;
	a.value[a.top] = b.value[b.top];
	--b.top;
	putstr_fd("pa\n", 1);
}
