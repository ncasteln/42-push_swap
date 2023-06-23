/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:14:55 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/23 11:21:21 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_two(t_clist **a)
{
	if ((*a)->n > (*a)->next->n)
		clst_swap(a, 'a');
}

void	sort_three(t_clist **a)
{
	if (get_biggest_node(a)->n == (*a)->n)
	{
		if (is_rev_sorted(*a))
		{
			clst_swap(a, 'a');
			clst_rev_rotate(a, 'a');
		}
		else
			clst_rotate(a, 'a');
	}
	if (get_biggest_node(a)->n == (*a)->next->n)
		clst_rev_rotate(a, 'a');
	if ((*a)->n > (*a)->next->n)
		clst_swap(a, 'a');
}

void	sort_five(t_clist **a, t_clist **b)
{
	if (clst_size(*a) > 4)
	{
		move_to_top_best_rotation(get_smallest_node(a), a, 'a');
		clst_pop_push(a, b, 'b');
	}
	move_to_top_best_rotation(get_biggest_node(a), a, 'a');
	clst_pop_push(a, b, 'b');
	sort_three(a);
	clst_pop_push(b, a, 'a');
	clst_rotate(a, 'a');
	clst_pop_push(b, a, 'a');
}

void	sort_six_and_more(t_clist **a, t_clist **b)
{
	int	i;
	int	j;
	int	n_times;
	int	size;


	i = 0;
	size = clst_size(*a);
	n_times = highest_set(get_biggest_node(a)->i);
	while (i <= n_times)
	{
		j = 0;
		while (j < size)
		{
			if (!is_set((*a)->i, i))
				clst_pop_push(a, b, 'b');
			else
				clst_rotate(a, 'a');
			j++;
		}
		while (*b)
			clst_pop_push(b, a, 'a');
		i++;
	}
}
