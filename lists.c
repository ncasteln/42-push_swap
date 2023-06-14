/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:28:28 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/14 09:48:21 by ncasteln         ###   ########.fr       */
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
	t_list	*head;

	head = *lst;
	if (*lst)
	{
		while (head->next != *lst)
			head = head->next;
		head->next = new_node;
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

void	print_list(t_list *lst)
{
	t_list	*head;

	head = lst;
	printf("__ PRINT LIST __\n");
	while (head->next && head->next != lst)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
	printf("%d\n", head->n);
}
