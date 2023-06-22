/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:54:58 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/22 16:59:26 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	is_already_set(t_clist *lst, int n)
{
	t_clist *head;
	int		size;

	head = lst;
	size = clst_size(lst);
	while (size > 0)
	{
		if (head->n == n && head->i > 0)
			return (1);
		head = head->next;
		size--;
	}
	return (0);
}

int	set_indexes(t_clist **a)
{
	int		i;
	int		j;
	int		neg;
	t_clist *head;
	t_clist *biggest;

	biggest = malloc (sizeof(t_clist));
	if (!biggest)
		return (0);



	j = clst_size(*a);
	neg = -1;
	while (j > 0)
	{
		biggest->n = 0;
		biggest->i = j;
		head = *a;
		i = clst_size(*a);
		while (i > 0)
		{
			if ((head->n >= biggest->n) && !is_already_set(*a, head->n))
				biggest->n = head->n;
			// if (head->n < 0 && )

			printf("head->n %d    ", head->n);
			printf("head->i [%d]    ", head->i);
			printf("big->n [%d]    ", biggest->n);
			printf("already set: [%d]\n", is_already_set(*a, i));
			head = head->next;
			i--;
		}
		printf("set biggest->n as [%d] and i as [%d]\n\n", biggest->n, biggest->i);


		i = 0;
		head = *a;
		while (i < clst_size(*a))
		{
			if (head->n == biggest->n)
				head->i = biggest->i;
			head = head->next;
			i++;
		}
		j--;
	}
	clst_print(*a, 'A');
	return (free(biggest), 1);
}







// int		*indexes;
// t_clist	*head;
// int		i;

// indexes = malloc (sizeof(int) * clst_size(*a));
// if (!indexes)
// 	return (0);
// head = *a;
// i = 0;
// while (i < clst_size(*a))
// {
// 	indexes[i] = head->n;
// 	i++;
// 	head = head->next;
// }
// bubble_sort(indexes, clst_size(*a));
// return (1);
