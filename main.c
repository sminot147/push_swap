/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:30:11 by sminot            #+#    #+#             */
/*   Updated: 2025/01/08 16:18:04 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;
	int j;

	ft_printf("\nVoici l'etat des piles : \n");
	ft_printf("a\tb\tnb_action\n");
	for (i = 0; i <= a->top || i<= b->top; i++)
	{
		if (i <= a->top)
			ft_printf("%d\t", a->value[a->top - i]);
		else
			ft_printf("\t");
		if (i <= b->top)
		{
			ft_printf("%d\t", b->value[b-> top - i]);
			for (j = 0; j <= 8; j++)
				ft_printf("%i ", b->nb_action[b->top - i][j]);
			ft_printf("\n");
		}
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
	start_sort(&a, &b);
	//print_stacks(&a, &b);
	sort(&a, &b);
	//print_stacks(&a, &b);
	free_all(&a, &b, ac);
	return (0);
}
