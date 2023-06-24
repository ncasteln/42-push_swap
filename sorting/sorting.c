/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:14:55 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/24 18:00:32 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_clist **a)
{
	if ((*a)->n > (*a)->next->n)
		clst_swap(a, 'a');
}

void	sort_three(t_clist **a)
{
	t_clist *head;

	head = *a;
	if (get_biggest_node(a)->n == head->next->n)
	{
		if (get_smallest_node(a)->n == head->n)
		{
			clst_swap(a, 'a');
			clst_rotate(a, 'a');
		}
		else
			clst_rev_rotate(a, 'a');
	}
	else if (get_biggest_node(a)->n == head->n)
	{
		if (get_smallest_node(a)->n == head->next->n)
			clst_rotate(a, 'a');
		else
		{
			clst_swap(a, 'a');
			clst_rev_rotate(a, 'a');
		}
	}
	else
		clst_swap(a, 'a');
}

void	sort_five(t_clist **a, t_clist **b)
{
	move_to_top_best_rotation(get_smallest_node(a), a, 'a');
	clst_pop_push(a, b, 'b');
	move_to_top_best_rotation(get_smallest_node(a), a, 'a');
	clst_pop_push(a, b, 'b');
	if ((*b)->n < (*b)->next->n)
		clst_swap(b, 'b');
	if (!is_sorted(*a))
		sort_three(a);
	clst_pop_push(b, a, 'a');
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
		// clst_print(*a, 'A');
		// clst_print(*b, 'B');
		while (*b)
			clst_pop_push(b, a, 'a');
		i++;
	}
}

// void	insertion_sort(t_clist **a, t_clist **b)
// {
// 	t_clist *head_a;

// 	head_a = *a;
// 	while (*a)
// 	{
// 		move_to_top_best_rotation(get_smallest_node(a), a, 'a');
// 		clst_pop_push(a, b, 'b');
// 	}
// 	while (*b)
// 		clst_pop_push(b, a, 'a');
// }
