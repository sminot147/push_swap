/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:55:05 by sminot            #+#    #+#             */
/*   Updated: 2024/12/21 17:04:54 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack a)
{
	int	temp;
	int	i;

	temp = a.value[a.top];
	i = -1;
	while (++i < a.top)
		a.value[a.top - 1 - i] = a.value[a.top - i];
	a.value[0] = temp;
	putstr_fd("ra\n", 1);
}

