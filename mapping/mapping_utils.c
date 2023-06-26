/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:14:14 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/26 12:17:32 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_already_set(t_clist *lst, int n)
{
	int		size;

	size = clst_size(lst);
	while (size > 0)
	{
		if ((lst->n == n) && (lst->i > 0))
			return (1);
		lst = lst->next;
		size--;
	}
	return (0);
}

int	count_pos_neg(t_clist *lst, char sign)
{
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (i < clst_size(lst))
	{
		if (sign == '+' && lst->n > 0)
			counter++;
		else if (sign == '-' && lst->n < 0)
			counter++;
		lst = lst->next;
		i++;
	}
	return (counter);
}
