/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:14:55 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/20 17:12:47 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	to_top(t_clist *lst, int n)
{
	t_clist	*head;
	int		counter;

	head = lst;
	counter = 0;
	while (head->next != lst)
	{
		if (head->n == n)
			return (counter);
		head = head->next;
		counter++;
	}
	return (-1);
}

int	to_bottom(t_clist *lst, int n)
{
	t_clist	*head;
	int		counter;

	head = lst;
	while (head->next != lst)
	{
		if (head->n == n)
			break;
		head = head->next;
	}
	counter = 0;
	while (head->next != lst)
	{
		counter++;
		head = head->next;
	}
	return (counter);
}

int	biggest(t_clist *lst)
{
	t_clist *head;
	int		biggest;

	head = lst;
	biggest = clst_last(lst)->n;
	while (head->next != lst)
	{
		if (biggest < head->n)
			biggest = head->n;
		head = head->next;
	}
	return (biggest);
}

int	get_smallest(t_clist *lst)
{
	t_clist *head;
	int		smallest;

	head = lst;
	smallest = clst_last(lst)->n;
	while (head->next != lst)
	{
		if (head->n < smallest)
			smallest = head->n;
		head = head->next;
	}
	return (smallest);
}

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
		clst_swap(a, "sa");
	return (0);
}

int	sort_three(t_clist **a)
{
	if (biggest(*a) == (*a)->n)
	{
		if (is_worst_case(*a))
		{
			clst_swap(a, "sa");
			clst_rev_rotate(a, "rra");
		}
		else
			clst_rotate(a, "ra");
	}
	if (biggest(*a) == (*a)->next->n)
		clst_rev_rotate(a, "rra");
	if ((*a)->n > (*a)->next->n)
		clst_swap(a, "sa");
	return (0);
}

int	sort_five(t_clist **a, t_clist **b, int size)
{
	item	i;

	i = 0;
	clst_pop_push(a, b, "pb");
	clst_pop_push(a, b, "pb");
	sort_three(a);
	// if ((*b)->n < (*b)->next->n)
	// 	clst_swap(b, "sb");
	// while (!is_sorted(*a, size))
	// {
	// 	clst_print(*a, 'A');
	// 	clst_print(*b, 'B');
	// }
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
	if (size == 5)
		return (sort_five(a, b, size));
	return (1);
	printf("%p\n", b);
}

