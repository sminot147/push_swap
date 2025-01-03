/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:05:13 by sminot            #+#    #+#             */
/*   Updated: 2025/01/03 15:01:28 by sminot           ###   ########.fr       */
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

/*------------------------ Action -------------------------------------------*/

//swap.c
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

//rotate.c
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

//reverse_rotate.c
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

//push.c
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

/*------------------------  Sort  -------------------------------------------*/

//sort_stack.c
void	start_sort(t_stack *a, t_stack *b);
void	stupid_sort(t_stack *a, t_stack *b);

/*------------------------  Utils  -------------------------------------------*/

//utils.c
void	free_all(t_stack a, t_stack b);
int		index_of_max(t_stack *a);
int		index_of_min(t_stack *a);
int		where_should_b_top_be(t_stack *a, t_stack *b);

//bubble_sort_tab.c
void	empty_a_and_sort_last_three(t_stack *a, t_stack *b);
















void	print_stacks(t_stack *a, t_stack *b); //a delete!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#endif