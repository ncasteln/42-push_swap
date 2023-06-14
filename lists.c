/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:28:28 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/14 13:13:20 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_clist	*clst_newnode(int n)
{
	t_clist	*new_node;

	new_node = malloc(sizeof(t_clist));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = new_node;
	return (new_node);
}

int	clst_size(t_clist *lst) // ----- OPTIONAL??? - could pass argc
{
	int	len;
	t_clist	*head;

	len = 0;
	if (lst)
	{
		head = lst;
		while (head->next != lst)
		{
			len++;
			head = head->next;
		}
		if (head->next == lst)
			len++;
	}
	return (len);
}

t_clist	*clst_last(t_clist *lst)
{
	t_clist	*head;

	head = lst;
	while (head && head->next != lst)
		head = head->next;
	return (head);
}

void	clst_append(t_clist **lst, t_clist *new_node)
{
	if (*lst) // if there is at least one item
	{
		clst_last(*lst)->next = new_node;
		new_node->next = *lst;
	}
	else
		*lst = new_node;
}

void	clst_push(t_clist **lst, t_clist *new_node)
{
	t_clist	*last;

	if (*lst) // if there is at least one item
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
		printf("(new list created) \n\n");
		*lst = new_node;
	}
}

t_clist	*clst_pop(t_clist **lst)
{
	t_clist *popped;

	popped = *lst;
	clst_last(*lst)->next = (*lst)->next;
	*lst = (*lst)->next;
	popped->next = popped;
	return (popped);
}

void	clst_swap(t_clist **lst)
{
	int	temp;

	temp = (*lst)->n;
	(*lst)->n = (*lst)->next->n;
	(*lst)->next->n = temp;
}

void	clst_rotate(t_clist **lst)
{
	*lst = (*lst)->next;
}

void	clst_rev_rotate(t_clist **lst)
{
	*lst = clst_last(*lst);
}

void	print_clst(t_clist *lst)
{
	t_clist	*head;

	head = NULL;
	if (clst_size(lst))
	{
		printf("size = [%d] - last = [%d]\n", clst_size(lst), clst_last(lst)->n);
		head = lst;
		while (head && head->next != lst)
		{
			printf("head->next [%p] && lst [%p] - [%d]\n", head->next, lst, head->n);
			// printf("[%d %p]\n", head->n, head->next);
			// printf("%d  ", head->n);
			head = head->next;
		}
		printf("head->next [%p] && lst [%p] - [%d]\n", head->next, lst, head->n);
		// printf("[%d %p]\n", head->n, head->next);
		// printf("%d\n", head->n);
	}
	else
		printf("(empty list)\n");
}
