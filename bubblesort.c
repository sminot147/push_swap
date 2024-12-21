/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:51:02 by sminot            #+#    #+#             */
/*   Updated: 2024/12/21 17:12:10 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int ac, t_stack a, t_stack a_bis)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < ac)
	{
		j = -1;
		while (++j < ac - 1 - i)
		{
			if (a.value[j] > a.value[j + 1])
			{
				temp = a.value[j + 1];
				a.value[j + 1] = a.value[j];
				a.value[j] = temp;
				sa(a_bis);
			}
			ra(a_bis);
		}
		while (i + 1 < ac && ac - j++)
			ra(a_bis);
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
void	bubble_sort(int ac, t_stack a, t_stack a_bis)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < ac)
	{
		j = -1;
		while (++j < ac - 1 - i)
		{
			if (a.value[j] > a.value[j + 1])
			{
				temp = a.value[j + 1];
				a.value[j + 1] = a.value[j];
				a.value[j] = temp;
				print("sa")
			}
			print("ra")
		}
		while (i + 1 < ac && ac - j++)
			print("ra")
	}
}
*/