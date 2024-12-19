/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:51:02 by sminot            #+#    #+#             */
/*   Updated: 2024/12/19 16:23:31 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	afficher(int *tab, int ac);

void	sort_tab(int ac, int **tab)
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
			if (tab[0][j] > tab[0][j + 1])
			{
				temp = tab[0][j + 1];
				tab[0][j + 1] = tab[0][j];
				tab[0][j] = temp;
				ft_printf("sa\n");
			}
			ft_printf("ra\n");
		}
		while (i + 1 < ac && ac - j++)
			ft_printf("ra\n", i);
	}
}
