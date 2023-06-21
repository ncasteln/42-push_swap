/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:08:31 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/21 12:59:04 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

/* Return the biggest/smalles number of the list  */
t_clist	*get_biggest_node(t_clist **lst)
{
	t_clist *head;
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
	t_clist *head;
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

/* Get the distance of an element from the top of the list,
upward and downward. */
int	get_dist_upward(int n, t_clist *lst)
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
	return (counter);
}

int	get_dist_downward(int n, t_clist *lst)
{
	t_clist	*head;
	int		pos;

	head = lst;
	pos = 0;
	while (head->next != lst)
	{
		if (head->n == n)
			break;
		head = head->next;
		pos++;
	}
	return (clst_size(lst) - (pos));
}

/* Moves the node to the top/bottom of the list, upward or downward based on
the shoretest distance from the top. When the dist is same, use normal
rotation (shift up) */
void	move_to_top(t_clist *node, t_clist **lst, char lst_name)
{
	int		dist;
	char	direction;

	dist = get_dist_upward(node->n, *lst);
	direction = 'u';
	if (get_dist_upward(node->n, *lst) > get_dist_downward(node->n, *lst))
	{
		dist = get_dist_downward(node->n, *lst);
		direction = 'd';
	}
	printf("NUMBER { %d } ", node->n);
	printf("dist_upward is [%d] and dist_down is [%d]", get_dist_upward(node->n, *lst), get_dist_downward(node->n, *lst));
	printf(" --- shift [%c]\n", direction);
	while (dist > 0)
	{
		if (direction == 'u')
			clst_rotate(lst, lst_name);
		else
			clst_rev_rotate(lst, lst_name);
		dist--;
	}
}
