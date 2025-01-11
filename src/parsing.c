/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:07:25 by sminot            #+#    #+#             */
/*   Updated: 2025/01/11 08:34:41 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	check_arg(int ac, char **av)
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

static int	twice(int *value, int ac)
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

static int	fill_tab(int ac, char **av, t_stack *a)
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
	a->nb_value_max = ac;
	return (0);
}

static int	creat_nb_action(t_stack *b, int ac)
{
	int	i;

	i = -1;
	b->nb_action = ft_calloc(ac, sizeof(int *));
	if (b->nb_action == NULL)
		return (-1);
	while (++i < ac)
	{
		b->nb_action[i] = ft_calloc(9, sizeof(int));
		if (b->nb_action[i] == NULL)
			return (-1);
	}
	return (1);
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
	if (creat_nb_action(b, ac) == -1)
	{
		free (a->value);
		free (b->value);
		return (-1);
	}
	if (fill_tab(ac, av, a) == -1 || twice(a->value, ac) == -1)
	{
		free_all(a, b, ac);
		return (-1);
	}
	a->top = ac -1;
	b->top = -1;
	return (0);
}
