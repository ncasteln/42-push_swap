/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:21:34 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/24 12:44:33 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	split_and_append(char *argv, t_clist **stack)
{
	int		i;
	char	**argv_splitted;

	argv_splitted = ft_split(argv, ' ');
	if (!argv_splitted[0])
		return (0);
	i = 0;
	while (argv_splitted[i])
	{
		if (is_valid_argv(argv_splitted[i], *stack))
			clst_append(stack, clst_newnode((int)ft_atol(argv_splitted[i])));
		else
			return (free_double_pointer(argv_splitted), 0);
		i++;
	}
	return (free_double_pointer(argv_splitted), i);
}

static int	build_stack(t_clist **stack, int argc, char **argv)
{
	int	i;
	int	n_splitted;
	int	n_args;

	i = 1;
	n_args = 0;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			n_splitted = split_and_append(argv[i], stack);
			if (!n_splitted)
				return (0);
			n_args += n_splitted;
		}
		else
		{
			if (is_valid_argv(argv[i], *stack))
				clst_append(stack, clst_newnode((int)ft_atol(argv[i])));
			else
				return (0);
			n_args++;
		}
		i++;
	}
	return (n_args);
}

int	main(int argc, char **argv)
{
	t_clist	*a;
	t_clist	*b;
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
	// clst_print(a, 'A'); // ------------------ REMOVE ------------------
	return (clst_clear(&a), clst_clear(&b), 0);
}
