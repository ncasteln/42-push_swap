/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:21:34 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/15 16:16:53 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static	int	is_valid_input(int argc)
{
	if (argc == 1)
		return (0);
	return (1);
}

int main (int argc, char **argv)
{
	t_ps	*stack;
	int		i;

	// --- VALIDATION ---
	if(!(is_valid_input(argc)))
		return (error());
	stack = malloc (sizeof(t_ps));
	if (!stack)
		return (error());

	// --- BUILD STACKS ---
	stack->a = NULL;
	stack->b = NULL;
	stack->max_size = argc - 1;

	i = 1;
	while (i < argc)
	{
		clst_append(&stack->a, clst_newnode(ft_atoi(argv[i])));
		i++;
	}
	return (0);
}
