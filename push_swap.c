/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:33:42 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/14 09:50:14 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	int i;
	t_list *lst;

	lst = NULL;
	i = 1;
	if (argc == 1)
		return (1);
	while (i < argc)
	{
		clst_push(&lst, clst_newnode(ft_atoi(argv[i])));
		i++;
	}
	printf("clst_size = [%d]\n", clst_size(lst));
	printf("clst_last = [%d]\n", clst_last(lst)->n);
	print_list(lst);
}
