/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:30:11 by sminot            #+#    #+#             */
/*   Updated: 2024/12/19 16:16:36 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <limits.h>

int	check_arg(int ac, char **av)
{
	size_t	i;
	char	c;

	while (ac--)
	{
		if (av[ac + 1][0] == '\0')
			return (-1);
		i = -1;
		while (av[ac + 1][++i])
		{
			c = av[ac + 1][i];
			if (ft_isdigit(c) != 1)
				if (i != 0 || (i == 0 && c != '-' && c != '+'))
					return (-1);
		}
	}
	return (0);
}

int	fill_tab(int ac, char **av, int **tab)
{
	long int	atoi_error;
	long int	atoi_result;

	if (check_arg(ac, av) == -1)
		return (-1);
	atoi_error = (long int)INT_MAX + 1;
	while (ac--)
	{
		atoi_result = ft_atoi(av[ac + 1]);
		if (atoi_result == atoi_error)
			return (-1);
		tab[0][ac] = (int)atoi_result;
	}
	return (0);
}

void	afficher(int *tab, int ac)
{
	for (int i = 0; i < ac; i++)
	{
		ft_printf("%d ", tab[i]);
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	int	*tab;

	if (--ac == 0)
		return (1);
	tab = ft_calloc(ac - 1, sizeof(int));
	if (!tab)
		return ((int)putstr_fd("Error\n", 2));
	if (fill_tab(ac, av, &tab) == -1)
		return ((int)putstr_fd("Error\n", 2));
	sort_tab(ac, &tab);
	afficher(tab, ac);
	free(tab);
	return (0);
}
