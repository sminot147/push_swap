/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:05:13 by sminot            #+#    #+#             */
/*   Updated: 2024/12/21 18:15:23 by sminot           ###   ########.fr       */
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
void	rb(t_stack b);
void	rr(t_stack a, t_stack b);

//reverse_rotate.c
void	rra(t_stack a);
void	rrb(t_stack b);
void	rrr(t_stack a, t_stack b);

//utils.c
void	free_all(t_stack a, t_stack b);

#endif