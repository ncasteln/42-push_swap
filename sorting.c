/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:14:55 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/22 12:07:19 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_two(t_clist **a)
{
	if ((*a)->n > (*a)->next->n)
		clst_swap(a, 'a');
}

void	sort_three(t_clist **a, int size) //  remove size ???
{
	if (get_biggest_node(a)->n == (*a)->n)
	{
		if (is_rev_sorted(*a, size))
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

void	sort_five(t_clist **a, t_clist **b, int size) // maybe optimize push first the 2nd biggest && remove size
{
	if (clst_size(*a) > 4)
	{
		move_to_top(get_smallest_node(a), a, 'a');
		clst_pop_push(a, b, 'b');
	}
	move_to_top(get_biggest_node(a), a, 'a');
	clst_pop_push(a, b, 'b');
	sort_three(a, size);
	clst_pop_push(b, a, 'a');
	clst_rotate(a, 'a');
	clst_pop_push(b, a, 'a');
}

void	sort_hundred(t_clist **a, t_clist **b)
{
	int		i;
	int		n_times;
	int		r;
	t_clist	*head_a;

	r = 0;
	i = 0;
	head_a = *a;
	n_times = highest_set(get_biggest_node(a)->n);
	while (i <= n_times)
	{
		// ft_putstr_fd("\n[ New Iter ]\n\n", 1);
		while (head_a->next != *a)
		{
			if (!(is_set(head_a->n, i)))
			{
				r = move_to_top(head_a, a, 'a');
				clst_pop_push(a, b, 'b');
				while (r > 0)
				{
					clst_rev_rotate(a, 'a');
					r--;
				}
				head_a = *a;
			}
			else
				head_a = head_a->next;
		}
		if (!(is_set(head_a->n, i)))
		{
			r = move_to_top(head_a, a, 'a');
			clst_pop_push(a, b, 'b');
			while (r > 0)
			{
				clst_rev_rotate(a, 'a');
				r--;
			}
		}
		while (clst_size(*b))
			clst_pop_push(b, a, 'a');
		head_a = *a;
		// ft_putstr_fd("\n[ b is empty ]\n\n", 1);
		// clst_print(*a, 'A');
		// clst_print(*b, 'B');

		i++;
	}
}

void	find_best_sort(t_clist **a, t_clist **b, int size)
{
	if (size == 2)
		sort_two(a);
	if (size == 3)
		sort_three(a, size);
	if (size == 4 || size == 5)
		sort_five(a, b, size);
	if (size > 5)
		sort_hundred(a, b);
}

