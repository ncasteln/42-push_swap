/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:54:58 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/26 12:19:45 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	store_index(int i, int n, t_clist **lst)
{
	int		j;
	t_clist	*head;

	head = *lst;
	j = 0;
	while (j < clst_size(*lst))
	{
		if (head->n == n)
		{
			if (head->n < 0)
				head->i = (i * -1);
			else
				head->i = i;
		}
		head = head->next;
		j++;
	}
}

static void	set_neg_indexes(t_clist *lst)
{
	int		i;
	int		j;
	int		n_neg;
	int		small_n;
	int		small_i;

	i = count_pos_neg(lst, '-');
	while (i > 0)
	{
		small_n = 0;
		small_i = i;
		j = clst_size(lst);
		n_neg = count_pos_neg(lst, '-');
		while ((j-- > 0) && (n_neg > 0))
		{
			if ((lst->n < small_n) && !is_already_set(lst, lst->n))
			{
				small_n = lst->n;
				n_neg--;
			}
			lst = lst->next;
		}
		store_index(small_i, small_n, &lst);
		i--;
	}
}

static void	set_pos_indexes(t_clist *lst)
{
	int		i;
	int		j;
	int		n;
	int		big_n;
	int		big_i;

	i = count_pos_neg(lst, '+');
	while (i > 0)
	{
		big_n = 0;
		big_i = i;
		n = count_pos_neg(lst, '+');
		j = clst_size(lst);
		while ((j-- > 0) && (n > 0))
		{
			if ((lst->n > big_n) && !is_already_set(lst, lst->n))
			{
				big_n = lst->n;
				n--;
			}
			lst = lst->next;
		}
		store_index(big_i, big_n, &lst);
		i--;
	}
}

static void	translate_to_pos(t_clist **lst)
{
	int		i;
	int		smallest;
	t_clist	*head;

	i = 0;
	head = *lst;
	smallest = (get_smallest_node(lst)->i) * -1;
	while (i < clst_size(*lst))
	{
		head->i += smallest;
		head = head->next;
		i++;
	}
}

void	set_indexes(t_clist **lst)
{
	set_pos_indexes(*lst);
	set_neg_indexes(*lst);
	translate_to_pos(lst);
}
