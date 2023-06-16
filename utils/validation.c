/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:52:31 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/16 12:06:29 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_valid_string_format(char *s)
{
	int	i;

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

int	is_valid_argv(char *argv, t_clist *lst)
{
	long	n;
	t_clist	*head;

	if (!is_valid_string_format(argv))
		return (0);
	n = ft_atol(argv); // --- change atol to be more smart ????
	printf("n = %ld\n", n);
	if (n != (int)n)
		return (0);
	head = lst;
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

int	is_valid_argc(int argc)
{
	if (argc == 1)
		return (0);
	return (1);
}
