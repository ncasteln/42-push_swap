/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:14:55 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/23 17:22:38 by ncasteln         ###   ########.fr       */
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
	int		big;
	int		small;
	t_clist *head;

	big = get_biggest_node(a)->n;
	small = get_smallest_node(a)->n;
	head = *a;
	if (big == head->next->n)
	{
		if (small == head->n)
		{
			clst_swap(a, 'a');
			clst_rotate(a, 'a');
		}
		else
			clst_rev_rotate(a, 'a');
	}
	else if (big == head->n)
	{
		if (small == head->next->n)
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

void	sort_five(t_clist **a, t_clist **b) // remember 4 --- ???
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
		while (*b)
			clst_pop_push(b, a, 'a');
		i++;
	}
}





// int		are_consecutive(int	top, int mid, int down)
// {
// 	if (mid + 1 == top && mid - 1 == down)
// 		return (2);
// 	if (mid + 1 == top)
// 		return (1);
// 	if (mid - 1 == down || mid + 1 == down)
// 		return (1);
// 	return (0);
// }

// void	sort_five(t_clist **a, t_clist **b) // rmember case of 4
// {
// 	int		id;
// 	int		i;
// 	t_clist	*head;

// 	head = *a;
// 	i = 5;
// 	id = 0;
// 	while (i > 0)
// 	{
// 		printf("[%d] [%d] [%d]\n", head->n, head->next->n, head->next->next->n);
// 		if (are_consecutive(head->n, head->next->n, head->next->next->n))
// 		{
// 			id = are_consecutive(head->n, head->next->n, head->next->next->n);
// 			head = head->next;
// 			break;
// 		}
// 		head = head->next;
// 		i--;
// 	}
// 	printf("Head is [%d]\n", head->n);
// 	printf("i is [%d]\n", i);
// 	if (id == 2)
// 	{
// 		move_to_top(head, a, 'a');
// 		clst_pop_push(a, b, 'b');
// 		clst_pop_push(a, b, 'b');
// 		if ((*b)->n < (*b)->next->n)
// 			clst_swap(b, 'b');
// 		if (!is_sorted(*a))
// 			sort_three(a);
// 		clst_pop_push(b, a, 'a');
// 		clst_pop_push(b, a, 'a');
// 		while (!is_sorted(*a))
// 			clst_rotate(a, 'a');
// 	}
// 	else
// 	{
// 		if (clst_size(*a) > 4)
// 		{
// 			move_to_top(get_smallest_node(a), a, 'a');
// 			clst_pop_push(a, b, 'b');
// 		}
// 		move_to_top(get_biggest_node(a), a, 'a');
// 		clst_pop_push(a, b, 'b');
// 		sort_three(a);
// 		clst_pop_push(b, a, 'a');
// 		clst_rotate(a, 'a');
// 		clst_pop_push(b, a, 'a');
// 	}
// 	// (void) b;
// }
