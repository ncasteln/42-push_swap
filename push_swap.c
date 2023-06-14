/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:33:42 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/14 13:13:40 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_clist	*a;
	t_clist	*b;
	int i;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	i = 1;
	while (i < argc)
	{
		clst_append(&a, clst_newnode(ft_atoi(argv[i])));
		i++;
	}
	printf("[ A ] ");
	print_clst(a);
	printf("[ B ] ");
	print_clst(b);

	// printf("__ PUSH __ \n");
	// clst_push(&a, clst_newnode(99999));
	// clst_push(&b, clst_newnode(99999));

	// printf("__ POP __\n");
	// printf("I popped [%d]\n", clst_pop(&a)->n);
	// printf("I popped [%d]\n", clst_pop(&a)->n);
	// printf("I popped [%d]\n", clst_pop(&a)->n);
	// printf("After popping 3 times, the list is now:\n");
	// print_clst(a);
	// printf("size = [%d]\n", clst_size(a));
	// printf("last = [%d]\n", clst_last(a)->n);
	// printf("\n");

	printf("__ POP & PUSH __\n");
	clst_push(&b, clst_pop(&a));
	clst_push(&b, clst_pop(&a));
	clst_push(&b, clst_pop(&a));
	printf("[ A ] ");
	print_clst(a);
	printf("[ B ] ");
	print_clst(b);

	// printf("__ ROTATE (shift up) __\n");
	// clst_rotate(&a);
	// print_clst(a);
	// clst_rotate(&a);
	// print_clst(a);
	// clst_rotate(&a);
	// print_clst(a);
	// printf("\n");

	// printf("__ REV_ROTATE (shift down) __\n");
	// clst_rev_rotate(&a);
	// print_clst(a);
	// clst_rev_rotate(&a);
	// print_clst(a);
	// clst_rev_rotate(&a);
	// print_clst(a);
	// printf("\n");

	// printf("__ SWAP __\n");
	// clst_swap(&a);
	// printf("After swap, the list is now: ");
	// print_clst(a);
	// clst_swap(&a);
	// printf("After swap, the list is now: ");
	// print_clst(a);
	// clst_swap(&a);
	// printf("After swap, the list is now: ");
	// print_clst(a);
	// printf("\n");
}
