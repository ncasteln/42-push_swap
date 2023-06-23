/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 07:28:28 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/23 12:14:23 by ncasteln         ###   ########.fr       */
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
	new_node->i = 0;
	new_node->next = new_node;
	return (new_node);
}

int	clst_size(t_clist *lst) // check an empty list
{
	int		len;
	t_clist	*head;

	len = 0;
	if (lst)
	{
		head = lst;
		while (head->next != lst)
		{
			head = head->next;
			len++;
		}
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
	if (*lst)
	{
		clst_last(*lst)->next = new_node;
		new_node->next = *lst;
	}
	else
		*lst = new_node;
}

void	clst_clear(t_clist **lst)
{
	t_clist	*temp;
	t_clist	*cpy;

	if (!(*lst))
		return ;
	cpy = *lst;
	while (cpy->next != *lst)
	{
		temp = cpy;
		cpy = cpy->next;
		free(temp);
	}
	free(cpy);
}

void	clst_print(t_clist *lst, char lst_name)
{
	t_clist	*head;

	printf("[ %c ] \n", lst_name);
	// ft_putstr_fd("[  ", 1);
	// ft_putchar_fd(lst_name, 1);
	// ft_putstr_fd("  ]", 1);
	// ft_putchar_fd('\n', 1);
	head = NULL;
	if (clst_size(lst))
	{
		head = lst;
		while (head && head->next != lst)
		{
			printf("%d   [%d]\n", head->n, head->i);
			// print_bits(head->n);
			head = head->next;
		}
		printf("%d   [%d]\n", head->n, head->i);
		// print_bits(head->n);
	}
	else
		printf("(empty list)\n");
		// ft_putstr_fd("(empty list)\n", 1);
}
