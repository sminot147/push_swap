/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:05:13 by sminot            #+#    #+#             */
/*   Updated: 2024/12/21 17:06:57 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

typedef struct stack
{
	int	top;
	int	*value;
	int	nb_max_value;
}	t_stack;

//bubble_sort_tab.c
void	bubble_sort(int ac, t_stack a, t_stack a_bis);

//swap.c
void	sa(t_stack a);
void	sb(t_stack b);
void	ss(t_stack a, t_stack b);

//rotate.c
void	ra(t_stack a);

//utils.c
void	free_all(t_stack a, t_stack b);

#endif