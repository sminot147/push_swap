/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:10:40 by sminot            #+#    #+#             */
/*   Updated: 2024/12/21 16:41:56 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack a)
{
	int	temp;

	if (a.top < 2)
	{
		putstr_fd("impossible action\n", 2);
		return ;
	}
	temp = a.value[a.top];
	a.value[a.top] = a.value[a.top - 1];
	a.value[a.top - 1] = temp;
	putstr_fd("sa\n", 1);
}

void	sb(t_stack b)
{
	int	temp;

	if (b.top < 2)
	{
		putstr_fd("impossible action\n", 2);
		return ;
	}
	temp = b.value[b.top];
	b.value[b.top] = b.value[b.top - 1];
	b.value[b.top - 1] = temp;
	putstr_fd("sb\n", 1);
}

void	ss(t_stack a, t_stack b)
{
	int	temp;

	if (a.top < 2 || b.top < 2)
	{
		putstr_fd("impossible action\n", 2);
		return ;
	}
	temp = a.value[a.top];
	a.value[a.top] = a.value[a.top - 1];
	a.value[a.top - 1] = temp;
	temp = b.value[b.top];
	b.value[b.top] = b.value[b.top - 1];
	b.value[b.top - 1] = temp;
	putstr_fd("ss\n", 1);
}
