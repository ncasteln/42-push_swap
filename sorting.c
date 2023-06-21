/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:14:55 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/21 12:34:24 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	is_worst_case(t_clist *lst)
{
	t_clist *head;
	int		counter;

	head = lst;
	counter = 0;
	while ((head->next != lst) && (head->n > head->next->n))
	{
		head = head->next;
		counter++;
	}
	counter++;
	if (clst_size(lst) == counter)
		return (1);
	return (0);
}

int	is_sorted(t_clist *lst, int size)
{
	t_clist *head;
	int		counter;

	head = lst;
	counter = 0;
	while ((head->next != lst) && (head->n < head->next->n))
	{
		head = head->next;
		counter++;
	}
	counter++;
	printf("size [%d]\n", size);
	printf("counter [%d]\n", counter);
	if (size == counter)
	{
		printf("[ SORTED ]\n");
		return (1);
	}
	return (0);
}

int	sort_two(t_clist **a)
{
	if ((*a)->n > (*a)->next->n)
		clst_swap(a, 'a');
	return (0);
}

int	sort_three(t_clist **a)
{
	if (get_biggest_node(a)->n == (*a)->n)
	{
		if (is_worst_case(*a))
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
	return (0);
}

int	get_right_pos(int n, t_clist *lst) // two different list
{
	int		pos;
	t_clist	*head;

	pos = 1;
	head = lst;
	while (head->next != lst)
	{
		if (n > head->n && n < head->next->n)
			return (pos);
		pos++;
		head = head->next;
	}
	if (n > head->n && n > head->next->n)
		return (pos);
	return (0);
}

int	sort_five(t_clist **a, t_clist **b, int size)
{
	move_to_top(get_biggest_node(a), a, 'a');
	printf("%d", size);
	if (*b)
		printf("%d", (*b)->n);
	return (0);
}

int	get_best_sort(int size, t_clist **a, t_clist **b)
{
	if (size == 2)
		return (sort_two(a));
	if (size == 3)
		return (sort_three(a));
	// if (size == 4)
	// 	return (sort_four(a));
	if (size >= 5)
		return (sort_five(a, b, size));
	return (1);
	printf("%p\n", b);
}

