/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:21:34 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/16 10:59:06 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	build_stack(t_ps *stack, int argc, char **argv)
{
	int		i;
	int		j;
	char	**argv_splitted;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' ')) // \n or \t???
		{
			argv_splitted = ft_split(argv[i], ' ');
			j = 0;
			while (argv_splitted[j])
			{
				if (is_valid_argv(argv_splitted[j], stack->a))
					clst_append(&stack->a, clst_newnode((int)ft_atol(argv_splitted[j])));
				else
					return (0); // free() argv_splitted, clst
				j++;
			}
		}
		else
		{
			if (is_valid_argv(argv[i], stack->a)) // case of 0 to handle--- valid number?
				clst_append(&stack->a, clst_newnode((int)ft_atol(argv[i])));
			else
				return (0); // free() argv_splitted, clst
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_ps	*stack;

	// --- VALIDATION ---
	if(!(is_valid_argc(argc)))
		return (error());

	// --- ALLOCATION ---
	stack = malloc (sizeof(t_ps));
	if (!stack)
		return (error());

	// --- BUILD STACKS ---
	stack->a = NULL;
	stack->b = NULL;

	if (!(build_stack(stack, argc, argv)))
		return (error());
	clst_print(stack->a);
	return (0);
}
