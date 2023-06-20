/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:31:13 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/20 11:36:27 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	clst_push(t_clist **lst, t_clist *new_node)
{
	t_clist	*last;

	if (!new_node)
		return ; // error??
	if (*lst) // if there is at least one item
	{
		last = clst_last(*lst);
		last->next = new_node; // works only with the first because of NULL
		new_node->next = *lst;
		*lst = new_node;
	}
	else
		*lst = new_node;
}

static t_clist	*clst_pop(t_clist **lst)
{
	t_clist *popped;

	popped = *lst;
	if (*lst)
	{
		if (clst_size(*lst) == 1)
			*lst = NULL;
		else
		{
			clst_last(*lst)->next = (*lst)->next;
			*lst = (*lst)->next;
			popped->next = popped;
		}
	}
	return (popped);
}

void	clst_pop_push(t_clist **src, t_clist **dst, char *name)
{
	if (clst_size(*src) > 0)
	{
		clst_push(dst, clst_pop(src));
		ft_putstr_fd(name, 1);
	}
}

void	clst_swap(t_clist **lst, char *name)
{
	int	temp;

	if (clst_size(*lst) > 1)
	{
		temp = (*lst)->n;
		(*lst)->n = (*lst)->next->n;
		(*lst)->next->n = temp;
		ft_putstr_fd(name, 1);
	}
}

void	clst_ss(t_clist **a, t_clist **b)
{
	clst_swap(a, "sa");
	clst_swap(b, "sb");
}

void	clst_rotate(t_clist **lst, char *name)
{
	if (clst_size(*lst) > 1) // --- not explicit in subject
	{
		*lst = (*lst)->next;
		ft_putstr_fd(name, 1);
	}
}

void	clst_rr(t_clist **a, t_clist **b)
{
	clst_rotate(a, "ra");
	clst_rotate(b, "rb");
}

void	clst_rev_rotate(t_clist **lst, char *name)
{
	if (clst_size(*lst) > 1) // --- not explicit in subject
	{
		*lst = clst_last(*lst);
		ft_putstr_fd(name, 1);
	}
}

void	clst_rrr(t_clist **a, t_clist **b)
{
	clst_rev_rotate(a, "rra");
	clst_rev_rotate(b, "rrb");
}
