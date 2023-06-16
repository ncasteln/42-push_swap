/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:21:34 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/16 09:50:40 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	is_valid_argv(char *argv, t_clist *lst)
{
	long	n;
	t_clist	*head;

	n = ft_atol(argv);
	if (n != (int)n)
		return (0);
	head = lst;
	clst_print(lst);
	if (lst && clst_size(lst) > 0)
	{
		while (head->next != lst)
		{
			if (head->n == n)
				return (0);
			head = head->next;
		}
		if (head->n == n)
			return (0);
	}
	return (1);
}

static int	is_valid_argc(int argc)
{
	if (argc == 1)
		return (0);
	return (1);
}

static int	build_stacks(t_ps *stack, int argc, char **argv)
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
				if (is_valid_argv(argv_splitted[j], stack->a)) // case of 0 to handle --- valid number?
					clst_append(&stack->a, clst_newnode((int)ft_atol(argv_splitted[j])));
				else
					return (0); // free argv_splitted && list
				j++;
			}
		}
		else
		{
			if (is_valid_argv(argv[i], stack->a)) // case of 0 to handle--- valid number?
				clst_append(&stack->a, clst_newnode((int)ft_atol(argv[i])));
			else
				return (0); // free the list until now && splitted
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

	if (!(build_stacks(stack, argc, argv)))
		return (error());
	clst_print(stack->a);
	return (0);
}
