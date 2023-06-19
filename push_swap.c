/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:21:34 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/19 12:29:14 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	build_stack(t_clist **stack, int argc, char **argv)
{
	int		i;
	int		j;
	char	**argv_splitted;

	if(!(is_valid_argc(argc)))
		return (0);
	argv_splitted = NULL;
	i = 1;
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
		}
		else
		{
			if (is_valid_argv(argv[i], *stack))
				clst_append(stack, clst_newnode((int)ft_atol(argv[i])));
			else
				return (free_double_pointer(argv_splitted), 0);
		}
		i++;
	}
	return (free_double_pointer(argv_splitted), 1);
}

int	main(int argc, char **argv)
{
	t_clist *a;
	t_clist *b;

	a = NULL;
	b = NULL;

	if (!(build_stack(&a, argc, argv)))
		return (clst_clear(&a), error());
	clst_print(a);
	return (clst_clear(&a), 0);
}
