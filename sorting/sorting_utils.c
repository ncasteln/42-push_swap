/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:08:31 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/26 10:09:24 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_clist	*get_biggest_node(t_clist **lst)
{
	t_clist	*head;
	t_clist	*biggest;

	head = *lst;
	biggest = clst_last(*lst);
	while (head->next != *lst)
	{
		if (biggest->n < head->n)
			biggest = head;
		head = head->next;
	}
	return (biggest);
}

t_clist	*get_smallest_node(t_clist **lst)
{
	t_clist	*head;
	t_clist	*smallest;

	head = *lst;
	smallest = clst_last(*lst);
	while (head->next != *lst)
	{
		if (head->n < smallest->n)
			smallest = head;
		head = head->next;
	}
	return (smallest);
}

int	get_dist_ud(int n, t_clist *lst, char direction)
{
	t_clist	*head;
	int		counter;

	head = lst;
	counter = 0;
	while (head->next != lst)
	{
		if (head->n == n)
			break ;
		head = head->next;
		counter++;
	}
	if (direction == 'u')
		return (counter);
	return (clst_size(lst) - (counter));
}

int	move_to_top_best_rotation(t_clist *node, t_clist **lst, char lst_name)
{
	int		dist;
	char	direction;

	direction = 'u';
	dist = get_dist_ud(node->n, *lst, 'u');
	if (get_dist_ud(node->n, *lst, 'u') > get_dist_ud(node->n, *lst, 'd'))
	{
		direction = 'd';
		dist = get_dist_ud(node->n, *lst, 'd');
	}
	while (dist > 0)
	{
		if (is_sorted(*lst))
			return (1);
		if (direction == 'u')
			clst_rotate(lst, lst_name);
		else if (direction == 'd')
			clst_rev_rotate(lst, lst_name);
		dist--;
	}
	return (0);
}

int	is_sorted(t_clist *lst)
{
	int		i;
	t_clist	*head;
	int		counter;

	head = lst;
	counter = 0;
	i = 0;
	while (i < (clst_size(lst) - 1))
	{
		if (head->n < head->next->n)
			counter++;
		head = head->next;
		i++;
	}
	if ((clst_size(lst) - 1) == counter)
		return (1);
	return (0);
}
