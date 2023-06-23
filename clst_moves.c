/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:31:13 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/23 12:42:10 by ncasteln         ###   ########.fr       */
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

void	clst_pop_push(t_clist **src, t_clist **dst, char lst_name)
{
	if (clst_size(*src) > 0)
	{
		clst_push(dst, clst_pop(src));
		ft_putchar_fd('p', 1);
		ft_putchar_fd(lst_name, 1);
		ft_putchar_fd('\n', 1);
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
		ft_putchar_fd('s', 1);
		if (lst_name == 'a' || lst_name == 'b')
			ft_putchar_fd(lst_name, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	clst_ss(t_clist **a, t_clist **b)
{
	clst_swap(a, ' ');
	clst_swap(b, ' ');
	ft_putstr_fd("s\n", 1);
}

void	clst_rotate(t_clist **lst, char lst_name)
{
	if (clst_size(*lst) > 1) // --- not explicit in subject
	{
		*lst = (*lst)->next;
		ft_putchar_fd('r', 1);
		if (lst_name == 'a' || lst_name == 'b')
			ft_putchar_fd(lst_name, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	clst_d_rotate(t_clist **a, t_clist **b)
{
	clst_rotate(a, ' ');
	clst_rotate(b, ' ');
	ft_putstr_fd("r\n", 1);
}

void	clst_rev_rotate(t_clist **lst, char lst_name)
{
	if (clst_size(*lst) > 1) // --- not explicit in subject
	{
		*lst = clst_last(*lst);
		ft_putstr_fd("rr", 1);
		if (lst_name == 'a' || lst_name == 'b')
			ft_putchar_fd(lst_name, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	clst_dr_rotate(t_clist **a, t_clist **b)
{
	clst_rev_rotate(a, ' ');
	clst_rev_rotate(b, ' ');
	ft_putstr_fd("r\n", 1);
}
