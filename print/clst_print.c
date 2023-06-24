/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:08:52 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/24 13:13:09 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clst_print(t_clist *lst, char lst_name)
{
	t_clist	*head;

	ft_putstr_fd("[  ", 1);
	ft_putchar_fd(lst_name, 1);
	ft_putstr_fd("  ]", 1);
	ft_putchar_fd('\n', 1);
	head = NULL;
	if (clst_size(lst))
	{
		head = lst;
		while (head && head->next != lst)
		{
			// printf("%d   [%d]\n", head->n, head->i);
			print_bits(head->i);
			head = head->next;
		}
		// printf("%d   [%d]\n", head->n, head->i);
		print_bits(head->i);
	}
	else
		printf("(empty list)\n");
		// ft_putstr_fd("(empty list)\n", 1);
}
