/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:08:52 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/24 17:30:48 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clst_print(t_clist *lst, char lst_name)
{
	t_clist	*head;

	ft_printf("[ %c ]\n", lst_name);
	head = NULL;
	if (clst_size(lst))
	{
		head = lst;
		while (head && head->next != lst)
		{
			ft_printf("%d   [%d]   ", head->n, head->i);
			print_bits(head->i);
			head = head->next;
		}
		ft_printf("%d   [%d]   ", head->n, head->i);
		print_bits(head->i);
	}
	else
		ft_printf("(empty list)\n");
	ft_printf("\n");
}
