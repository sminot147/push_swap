/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:30:11 by sminot            #+#    #+#             */
/*   Updated: 2025/01/03 16:35:58 by sminot           ###   ########.fr       */
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

int	twice(int	*value, int ac)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ac)
	{
		j = -1;
		while (++j < i)
			if (value[i] == value[j])
				return (-1);
	}
	return (0);
}

int	fill_tab(int ac, char **av, t_stack *a)
{
	long int	atoi_error;
	long int	atoi_result;
	int			i;

	atoi_error = (long int)INT_MAX + 1;
	i = -1;
	while (++i < ac)
	{
		atoi_result = ft_atoi(av[ac - i]);
		if (atoi_result == atoi_error)
			return (-1);
		a->value[i] = (int)atoi_result;
	}
	return (0);
}

int	creat_stack(t_stack *a, t_stack *b, int ac, char **av)
{
	if (check_arg(ac, av) == -1)
		return (-1);
	a->value = ft_calloc(ac, sizeof(int));
	if (!a->value)
		return (-1);
	b->value = ft_calloc(ac, sizeof(int));
	if (!b->value)
	{
		free(a->value);
		return (-1);
	}
	if (fill_tab(ac, av, a) == -1 || twice(a->value, ac) == -1)
	{
		free_all(*a, *b);
		return (-1);
	}
	a->nb_max_value = ac;
	a->top = ac -1;
	b->nb_max_value = ac;
	b->top = -1;
	return (0);
}

#include <stdio.h>

void	print_stacks(t_stack *a, t_stack *b)
{
	int i;

	ft_printf("\nVoici l'etat des piles : \n");
	ft_printf("a\tb\n");

	for (i = 0; i < a->nb_max_value || i < b->nb_max_value; i++)
	{
		if (i <= a->top)
			ft_printf("%d\t", a->value[a->top - i]);
		else
			ft_printf("\t");
		if (i <= b->top)
			ft_printf("%d\n", b->value[b-> top - i]);
		else if (i < a->top)
			ft_printf("\n");
	}
	ft_printf("\n");
}




int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (--ac == 0)
		return (1);
	if (creat_stack(&a, &b, ac, av) == -1)
		return ((int)putstr_fd("Error\n", 2));
	empty_a_and_sort_last_three(&a, &b);
	//print_stacks(&a, &b);
	stupid_sort(&a, &b);
	//print_stacks(&a, &b);
	free_all(a, b);
	return (0);
}
