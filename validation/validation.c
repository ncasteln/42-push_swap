/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:52:31 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/24 17:17:54 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	is_valid_string_format(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == '+' || s[i] == '-') && i == 0)
			i++;
		while (ft_isdigit(s[i]))
			i++;
		if (ft_strlen(s) == i)
			return (1);
		return (0);
	}
	return (0);
}

static int	has_duplicates(int n, t_clist *lst)
{
	t_clist	*head;

	head = lst;
	if (lst && clst_size(lst) > 0)
	{
		while (head->next != lst)
		{
			if (head->n == n)
				return (1);
			head = head->next;
		}
		if (head->n == n)
			return (1);
	}
	return (0);
}

static int	is_valid_zero(char *argv)
{
	if (ft_strlen(argv) == 1)
	{
		if (argv[0] == '+' || argv[0] == '-')
			return (0);
	}
	return (1);
}

int	is_valid_argv(char *argv, t_clist *lst)
{
	long	n;

	if (ft_atol(argv) == 0 && !(is_valid_zero(argv)))
		return (0);
	if (!is_valid_string_format(argv))
		return (0);
	n = ft_atol(argv);
	// printf("n = %ld\n", n);
	if (n != (int)n)
		return (0);
	if (has_duplicates((int)n, lst))
		return (0);
	return (1);
}
