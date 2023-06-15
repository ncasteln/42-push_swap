/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:33:42 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/15 08:30:17 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	*stack;
	int i;

	if (argc == 1)
		return (1);
	stack = malloc (sizeof(t_ps));
	if (!stack)
		return (1);
	stack->a = NULL;
	stack->b = NULL;
	stack->max_size = argc - 1;

	i = 1;
	while (i < argc)
	{
		clst_append(&stack->a, clst_newnode(ft_atoi(argv[i])));
		i++;
	}
	printf("[ A ] ");
	print_clst(stack->a);
	printf("[ B ] ");
	print_clst(stack->b);
	printf("\n");

	// printf("__ SIZE __ \n");
	// clst_size(stack->a);
	// clst_size(stack->b);

	// printf("__ LAST __ \n");
	// t_clist *last = clst_last(a);
	// printf("address outside of lst_last [%p]\n", last);

	// printf("__ PUSH __ \n");
	// clst_push(&stack->a, clst_newnode(99999));
	// clst_push(&b, clst_newnode(99999));

	// printf("__ POP __\n");
	// clst_pop(&stack->a);
	// clst_pop(&stack->a);
	// clst_pop(&stack->a);
	// clst_pop(&stack->a);
	// clst_pop(&stack->a);
	// clst_pop(&stack->a);
	// print_clst(stack->a);
	// printf("\n");

	// printf("\n__ POP & PUSH __\n");
	// clst_push(&b, clst_pop(&stack->a));
	// printf("[ A ] ");
	// print_clst(a);
	// printf("[ B ] ");
	// print_clst(b);
	// clst_push(&b, clst_pop(&stack->a));
	// printf("[ A ] ");
	// print_clst(a);
	// printf("[ B ] ");
	// print_clst(b);
	// clst_push(&b, clst_pop(&stack->a));
	// printf("[ A ] ");
	// print_clst(a);
	// printf("[ B ] ");
	// print_clst(b);
	// clst_push(&b, clst_pop(&stack->a));
	// printf("[ A ] ");
	// print_clst(a);
	// printf("[ B ] ");
	// print_clst(b);
	// clst_push(&b, clst_pop(&stack->a));
	// printf("[ A ] ");
	// print_clst(a);
	// printf("[ B ] ");
	// print_clst(b);

	// printf("__ ROTATE (shift up) __\n");
	// clst_rotate(&stack->a);
	// print_clst(a);
	// clst_rotate(&stack->a);
	// print_clst(a);
	// clst_rotate(&stack->a);
	// print_clst(a);
	// printf("\n");

	// printf("__ REV_ROTATE (shift down) __\n");
	// clst_rev_rotate(&stack->a);
	// print_clst(a);
	// clst_rev_rotate(&stack->a);
	// print_clst(a);
	// clst_rev_rotate(&stack->a);
	// print_clst(a);
	// printf("\n");

	// printf("__ SWAP __\n");
	// clst_swap(&stack->a);
	// printf("After swap, the list is now: ");
	// print_clst(a);
	// clst_swap(&stack->a);
	// printf("After swap, the list is now: ");
	// print_clst(a);
	// clst_swap(&stack->a);
	// printf("After swap, the list is now: ");
	// print_clst(a);
	// printf("\n");
}
