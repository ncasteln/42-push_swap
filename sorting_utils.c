/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:08:31 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/24 12:07:23 by ncasteln         ###   ########.fr       */
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
	t_clist *smallest;

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

/* Moves the node to the top/bottom of the list, returning the number of rotation */
int	move_to_top(t_clist *node, t_clist **lst, char lst_name)
{
	int	dist;
	int	r;

	dist = get_dist_upward(node->n, *lst);
	r = dist;
	// printf("NUMBER { %d } move to top\n", node->n);
	while (dist > 0)
	{
		clst_rotate(lst, lst_name);
		dist--;
	}
	return (r);
}

/* Moves the node to the top/bottom of the list, upward or downward based on
the shoretest distance from the top. When the dist is same, use normal
rotation (shift up) */
int	move_to_top_best_rotation(t_clist *node, t_clist **lst, char lst_name)
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

/* Given a list, returns the correct position in which the node of another
list should be, as an index */
int	get_right_pos(int n, t_clist *lst)
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

/* Check if the list is sorted in one of two direction descending or ascending */
int	is_sorted(t_clist *lst)
{
	int		i;
	t_clist *head;
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

int	is_rev_sorted(t_clist *lst)
{
	int		i;
	t_clist *head;
	int		counter;

	head = lst;
	counter = 0;
	i = 0;
	while (i < (clst_size(lst) - 1))
	{
		if (head->n > head->next->n)
			counter++;
		head = head->next;
		i++;
	}
	if ((clst_size(lst) - 1) == counter)
		return (1);
	return (0);
}

