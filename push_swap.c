/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:33:42 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/14 10:47:46 by ncasteln         ###   ########.fr       */
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
		clst_append(&lst, clst_newnode(ft_atoi(argv[i])));
		i++;
	}
	print_clst(lst);
	printf("size = [%d]\n", clst_size(lst));
	printf("last = [%d]\n\n", clst_last(lst)->n);

	printf("__ ROTATE (shift up) __\n");
	clst_rotate(&lst);
	print_clst(lst);
	clst_rotate(&lst);
	print_clst(lst);
	clst_rotate(&lst);
	print_clst(lst);
	printf("\n");

	printf("__ REV_ROTATE (shift down) __\n");
	clst_rev_rotate(&lst);
	print_clst(lst);
	clst_rev_rotate(&lst);
	print_clst(lst);
	clst_rev_rotate(&lst);
	print_clst(lst);
	printf("\n");

	printf("__ POP __\n");
	printf("I popped [%d]\n", clst_pop(&lst)->n);
	printf("I popped [%d]\n", clst_pop(&lst)->n);
	printf("I popped [%d]\n", clst_pop(&lst)->n);
	printf("After popping 3 times, the list is now:\n");
	print_clst(lst);
	printf("size = [%d]\n", clst_size(lst));
	printf("last = [%d]\n\n", clst_last(lst)->n);

	printf("__ SWAP __\n");
	clst_swap(&lst);
	printf("After swap, the list is now:\n");
	print_clst(lst);
	clst_swap(&lst);
	printf("After swap, the list is now:\n");
	print_clst(lst);
	clst_swap(&lst);
	printf("After swap, the list is now:\n");
	print_clst(lst);
}
