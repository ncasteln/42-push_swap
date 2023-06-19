/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clst_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:33:42 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/19 09:40:00 by ncasteln         ###   ########.fr       */
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

	i = 1;
	while (i < argc)
	{
		clst_append(&a, clst_newnode(ft_atol(argv[i])));
		i++;
	}
	printf("[ A ] ");
	clst_print(a);
	printf("[ B ] ");
	clst_print(b);
	printf("\n");

	// printf("__ SIZE __ \n");
	// clst_size(a);
	// clst_size(b);

	// printf("__ LAST __ \n");
	// t_clist *last = clst_last(a);
	// printf("Last is [%d] address outside of lst_last [%p]\n", last->n, last);

	// printf("__ PUSH __ \n");
	// clst_push(&a, clst_newnode(99999));
	// clst_push(&b, clst_newnode(99999));

	// printf("__ POP __\n");
	// clst_pop(&a);
	// clst_print(a);
	// printf("\n");

	// printf("\n__ POP & PUSH __\n");
	// clst_push(&b, clst_pop(&a));
	// printf("[ A ] ");
	// clst_print(a);
	// printf("[ B ] ");
	// clst_print(b);

	// printf("__ ROTATE (shift up) __\n");
	// clst_rotate(&a);
	// clst_print(a);
	// clst_rotate(&a);
	// clst_print(a);
	// clst_rotate(&a);
	// clst_print(a);
	// printf("\n");

	// printf("__ REV_ROTATE (shift down) __\n");
	// clst_rev_rotate(&a);
	// clst_print(a);
	// clst_rev_rotate(&a);
	// clst_print(a);
	// clst_rev_rotate(&a);
	// clst_print(a);
	// printf("\n");

	// printf("__ SWAP __\n");
	// clst_swap(&a);
	// printf("After swap, the list is now: ");
	// clst_print(a);
	// clst_swap(&a);
	// printf("After swap, the list is now: ");
	// clst_print(a);
	// clst_swap(&a);
	// printf("After swap, the list is now: ");
	// clst_print(a);
	// printf("\n");

	// printf("__ MIX __\n");
	// clst_swap(&a);
	// printf("[ A ] ");
	// clst_print(a);
	// printf("[ B ] ");
	// clst_print(b);
	// printf("\n");
	// clst_push(&b, clst_pop(&a));
	// // clst_push(&b, clst_pop(&a));
	// printf("[ A ] ");
	// clst_print(a);
	// printf("[ B ] ");
	// clst_print(b);
	// printf("\n");
	// clst_rotate(&a);
	// clst_rotate(&b);
	// printf("[ A ] ");
	// clst_print(a);
	// printf("[ B ] ");
	// clst_print(b);
	// printf("\n");
	// clst_push(&a, clst_pop(&b));
	// clst_push(&a, clst_pop(&b));
	// clst_push(&a, clst_pop(&b));
	// clst_push(&a, clst_pop(&b));
	// printf("[ A ] ");
	// clst_print(a);
	// printf("[ B ] ");
	// clst_print(b);
	// printf("\n");

	printf("__ CLEAR __\n");
	clst_clear(&a);
}
