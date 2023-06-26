/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:31:13 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/26 12:24:32 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	clst_push(t_clist **lst, t_clist *new_node)
{
	t_clist	*last;

	if (*lst)
	{
		last = clst_last(*lst);
		last->next = new_node;
		new_node->next = *lst;
		*lst = new_node;
	}
	else
		*lst = new_node;
}

void	clst_pop_push(t_clist **src, t_clist **dst, char lst_name)
{
	t_clist	*popped;

	popped = *src;
	if (*src)
	{
		if (clst_size(*src) == 1)
			*src = NULL;
		else
		{
			clst_last(*src)->next = (*src)->next;
			*src = (*src)->next;
			popped->next = popped;
		}
	}
	if (popped)
	{
		clst_push(dst, popped);
		ft_printf("p%c\n", lst_name);
	}
}

void	clst_swap(t_clist **lst, char lst_name)
{
	t_clist	*temp;

	temp = NULL;
	if (clst_size(*lst) > 1)
	{
		temp = (*lst)->next;
		(*lst)->next = (*lst)->next->next;
		temp->next = *lst;
		clst_last(*lst)->next = temp;
		*lst = clst_last(*lst);
		if (lst_name == 'a' || lst_name == 'b')
			ft_printf("s%c\n", lst_name);
	}
}

void	clst_rotate(t_clist **lst, char lst_name)
{
	if (clst_size(*lst) > 1)
	{
		*lst = (*lst)->next;
		if (lst_name == 'a' || lst_name == 'b')
			ft_printf("r%c\n", lst_name);
	}
}

void	clst_rev_rotate(t_clist **lst, char lst_name)
{
	if (clst_size(*lst) > 1)
	{
		*lst = clst_last(*lst);
		if (lst_name == 'a' || lst_name == 'b')
			ft_printf("rr%c\n", lst_name);
	}
}
