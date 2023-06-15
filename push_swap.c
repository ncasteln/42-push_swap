/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:21:34 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/15 16:34:24 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// static void	expand_argv(char *argv) // ex "    6   889   "
// {
// 	int	i;

// 	i = 0;
// 	while (argv[i] == ' ' || argv[i] == '\t')
// 		i++;
// 	// while (ft_isdigit(argv[i]))
// }

static int	is_valid_input(int argc)
{
	if (argc == 1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_ps	*stack;
	int		i;

	// --- VALIDATION ---
	if(!(is_valid_input(argc)))
		return (error());

	// --- INPUT FORMAT ---
	// i = 1;
	// while (i < argc)
	// {
	// 	if (ft_strchr(argv[i], ' '))
	// 		argv = expand_argv(argv);
	// 	i++;
	// }

	// --- ALLOCATION ---
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
		if (ft_strchr(argv[i], ' ') || ft_strchr(argv[i], '\t')) // \n ???
		{
			// expand_argv(argv[i]);
			// append it
		}
		clst_append(&stack->a, clst_newnode(ft_atoi(argv[i])));
		i++;
	}
	return (0);
}
