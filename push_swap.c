/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:33:42 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/14 14:40:45 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	*stack;
	t_clist	*a;
	t_clist	*b;
	int i;

	if (argc == 1)
		return (1);
	stack = malloc (sizeof(t_ps));
	if (!stack)
		return (1);
	a = NULL;
	b = NULL;
	stack->a = a;
	stack->b = b;
	stack->max_size = argc - 1;

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

	printf("__ LAST __ \n");
	t_clist *last = clst_last(&a);
	printf("address outside of lst_last [%p]\n", last);
	printf("BUT ITS NOT");

	// printf("__ PUSH __ \n");
	// clst_push(&a, clst_newnode(99999));
	// clst_push(&b, clst_newnode(99999));

	// printf("__ POP __\n");
	// clst_pop(&a);
	// clst_pop(&a);
	// clst_pop(&a);
	// clst_pop(&a);
	// clst_pop(&a);
	// clst_pop(&a);
	// print_clst(a);
	// printf("\n");

	// printf("\n__ POP & PUSH __\n");
	// clst_push(&b, clst_pop(&a));
	// printf("[ A ] ");
	// print_clst(a);
	// printf("[ B ] ");
	// print_clst(b);
	// clst_push(&b, clst_pop(&a));
	// printf("[ A ] ");
	// print_clst(a);
	// printf("[ B ] ");
	// print_clst(b);
	// clst_push(&b, clst_pop(&a));
	// printf("[ A ] ");
	// print_clst(a);
	// printf("[ B ] ");
	// print_clst(b);
	// clst_push(&b, clst_pop(&a));
	// printf("[ A ] ");
	// print_clst(a);
	// printf("[ B ] ");
	// print_clst(b);
	// clst_push(&b, clst_pop(&a));
	// printf("[ A ] ");
	// print_clst(a);
	// printf("[ B ] ");
	// print_clst(b);

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
