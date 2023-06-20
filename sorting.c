/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:14:55 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/20 13:35:49 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	get_biggest(t_clist *lst)
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
	{
		printf("is the worst case!\n");
		return (1);
	}
	return (0);
}

int	is_sorted(t_clist *lst)
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
	if (clst_size(lst) == counter)
	{
		printf("is Sorted!\n");
		return (1);
	}
	printf("NOT Sorted!\n");
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
	if (get_biggest(*a) == (*a)->n)
	{
		if (is_worst_case(*a))
		{
			clst_swap(a, "sa");
			clst_rev_rotate(a, "rra");
		}
		else
			clst_rotate(a, "ra");
	}
	if (get_biggest(*a) == (*a)->next->n)
		clst_rev_rotate(a, "rra");
	if ((*a)->n > (*a)->next->n)
		clst_swap(a, "sa");
	return (0);
}

int	get_best_sort(int argc, t_clist **a, t_clist **b)
{
	if (argc == 3)
		return (sort_two(a));
	if (argc >= 4)
		return (sort_three(a));
	return (1);
	printf("%p\n", b);
}

