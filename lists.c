/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:28:28 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/14 10:39:36 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_list	*clst_newnode(int n)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	return (new_node);
}

int	clst_size(t_list *lst)
{
	int	len;
	t_list	*head;

	len = 0;
	head = lst;
	while (head->next && head->next != lst)
	{
		len++;
		head = head->next;
	}
	len++;
	return (len);
}

t_list	*clst_last(t_list *lst)
{
	t_list	*head;

	head = lst;
	if (head->next)
	{
		while (head->next != lst)
			head = head->next;
		return (head);
	}
	return (lst);
}

void	clst_append(t_list **lst, t_list *new_node)
{
	t_list	*last;

	if (*lst)
	{
		last = clst_last(*lst);
		last->next = new_node;
		new_node->next = *lst;
	}
	else
		*lst = new_node;
}

void	clst_push(t_list **lst, t_list *new_node)
{
	t_list	*last;

	printf("Address of lst [%p]\n", lst);
	if (*lst) // when there is at least one node - **lst exist but *lst not
	{
		last = clst_last(*lst);
		printf("The last node is [%d]\n", last->n);
		last->next = new_node; // works only with the first because of NULL
		printf("But now, the last node is [%d]\n", last->next->n);
		new_node->next = *lst;
		*lst = new_node;
		printf("Now lst starts from [%d], the new element\n", (*lst)->n);
		printf("__ PUSHED __ \n\n");
	}
	else
	{
		printf("__ NEW LIST __ \n\n");
		*lst = new_node;
	}
}

t_list	*clst_pop(t_list **lst)
{
	t_list *popped;

	popped = *lst;
	clst_last(*lst)->next = (*lst)->next;
	*lst = (*lst)->next;
	return (popped);
}

// void	clst_swap(t_list **lst)
// {

// }

void	clst_rotate(t_list **lst)
{
	*lst = (*lst)->next;
}

void	clst_rev_rotate(t_list **lst)
{
	*lst = clst_last(*lst);
}

void	print_clst(t_list *lst)
{
	t_list	*head;

	head = lst;
	while (head->next && head->next != lst)
	{
		printf("%d ", head->n);
		head = head->next;
	}
	printf("%d\n", head->n);
}
