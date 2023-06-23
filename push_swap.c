/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:21:34 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/23 13:04:40 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	build_stack(t_clist **stack, int argc, char **argv)
{
	int		i;
	int		j;
	char	**argv_splitted;
	int		n_args;

	argv_splitted = NULL;
	i = 1;
	n_args = 0;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			free_double_pointer(argv_splitted);
			argv_splitted = ft_split(argv[i], ' ');
			if (!argv_splitted[0]) // ----- protectable also inside split
				return (0);
			j = 0;
			while (argv_splitted[j])
			{
				if (is_valid_argv(argv_splitted[j], *stack))
					clst_append(stack, clst_newnode((int)ft_atol(argv_splitted[j])));
				else
					return (free_double_pointer(argv_splitted), 0);
				j++;
			}
			n_args += j;
		}
		else
		{
			if (is_valid_argv(argv[i], *stack))
				clst_append(stack, clst_newnode((int)ft_atol(argv[i])));
			else
				return (free_double_pointer(argv_splitted), 0);
			n_args++;
		}
		i++;
	}
	return (free_double_pointer(argv_splitted), n_args);
}

int	main(int argc, char **argv)
{
	t_clist *a;
	t_clist *b;
	int		n_args;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	n_args = build_stack(&a, argc, argv);
	if (!n_args)
		return (clst_clear(&a), ft_putstr_fd("Error\n", 2), 1);
	if (is_sorted(a))
		return (clst_clear(&a), 0);
	else if (n_args == 2)
		sort_two(&a);
	else if (n_args == 3)
		sort_three(&a);
	else if (n_args == 4 || n_args == 5)
		sort_five(&a, &b);
	else
	{
		set_indexes(&a);
		sort_six_and_more(&a, &b);
	}
	clst_print(a, 'A'); // --- REMOVE ---
	return (clst_clear(&a), clst_clear(&b), 0);
}
