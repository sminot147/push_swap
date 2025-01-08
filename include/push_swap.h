/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:05:13 by sminot            #+#    #+#             */
/*   Updated: 2025/01/08 15:56:58 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"

//nb_action[][0] : nb of ra		nb_action[][4] : nb action with rr ra et rb
//nb_action[][1] : nb of rra	nb_action[][5] : nb action with rrr rra et rrb
//nb_action[][2] : nb of rb		nb_action[][6] : nb action with ra et rrb
//nb_action[][3] : nb of rrb	nb_action[][7] : nb action with rra et rb
//nb_action[][8] : min of nb_action
typedef struct stack
{
	int	top;
	int	*value;
	int	**nb_action;
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
void	sort(t_stack *a, t_stack *b);

//sort_utils.c
int		futur_index_nb(t_stack *a, int nb);
int		index_min_action(t_stack *b);
void	calc_nb_action(t_stack *a, t_stack *b);

//sort_with.c
void	sort_with_rr(t_stack *a, t_stack *b, int nb_to_sort);
void	sort_with_rrr(t_stack *a, t_stack *b, int nb_to_sort);
void	sort_with_ra_rrb(t_stack *a, t_stack *b, int nb_to_sort);
void	sort_with_rra_rb(t_stack *a, t_stack *b, int nb_to_sort);

/*------------------------  Utils  -------------------------------------------*/

//utils.c
void	free_all(t_stack *a, t_stack *b, int ac);
int		min(int a, int b);
int		max(int a, int b);
int		min_index(int *tab, int nb_value);
int		max_index(int *tab, int nb_value);

/*------------------------  Parsing  -----------------------------------------*/
//parsing.c
int		creat_stack(t_stack *a, t_stack *b, int ac, char **av);





















void	print_stacks(t_stack *a, t_stack *b); //a delete!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#endif