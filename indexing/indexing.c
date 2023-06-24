/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:54:58 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/24 13:03:29 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_already_set(t_clist *lst, int n)
{
	t_clist *head;
	int		size;

	head = lst;
	size = clst_size(lst);
	while (size > 0)
	{
		if ((head->n == n) && (head->i > 0))
		{
			return (1);
		}
		head = head->next;
		size--;
	}
	return (0);
}

static int	count_pos_neg(t_clist *lst, char sign)
{
	t_clist *head; // remove head and save size ??
	int		i;
	int		counter;

	head = lst;
	i = 0;
	counter = 0;
	while (i < clst_size(lst))
	{
		if (sign == '+' && head->n > 0)
			counter++;
		else if (sign == '-' && head->n < 0)
			counter++;
		head = head->next;
		i++;
	}
	return (counter);
}

static void	store_index(int i, int n, t_clist **lst)
{
	int	j;
	t_clist	*head;

	head = *lst;
	j = 0;
	while (j < clst_size(*lst))
	{
		if (head->n == n)
			head->i = i;
		head = head->next;
		j++;
	}
}

static void	set_neg_indexes(t_clist **lst)
{
	int		i;
	int		j;
	int		n_neg;
	int		small_n;
	int		small_i;
	t_clist *head;

	i = count_pos_neg(*lst, '-'); // only difference
	while (i > 0)
	{
		small_n = 0;
		small_i = i;
		head = *lst;
		j = clst_size(*lst); // only difference
		n_neg = count_pos_neg(*lst, '-'); // only difference
		while (j > 0 && n_neg > 0)
		{
			if ((head->n < small_n) && !is_already_set(*lst, head->n)) // only difference
			{
				small_n = head->n;
				n_neg--;
			}
			head = head->next;
			j--;
		}
		store_index(small_i, small_n, lst);
		i--;
	}

	i = 0;
	head = *lst;
	while (i < clst_size(*lst))
	{
		if (head->n < 0)
			head->i *= -1;
		head = head->next;
		i++;
	}
}

static void	set_pos_indexes(t_clist **lst)
{
	int		i;
	int		j;
	int		n_pos;
	int		big_n;
	int		big_i;
	t_clist *head;

	i = count_pos_neg(*lst, '+');
	while (i > 0)
	{
		big_n = 0;
		big_i = i;
		head = *lst;
		j = clst_size(*lst);
		n_pos = count_pos_neg(*lst, '+');
		while (j > 0 && n_pos > 0)
		{
			if ((head->n > big_n) && !is_already_set(*lst, head->n))
			{
				big_n = head->n;
				n_pos--;
			}
			head = head->next;
			j--;
		}
		store_index(big_i, big_n, lst);
		i--;
	}
}

static void	translate_indexes_to_pos(t_clist **lst)
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
	set_pos_indexes(lst);
	set_neg_indexes(lst);
	translate_indexes_to_pos(lst);
}
