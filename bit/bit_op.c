/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:31:26 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/24 17:59:41 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* Cehck if the current bit of [n], shifted for [i] position, is set or not */
int	is_set(int n, int i)
{
	if ((n >> i) & 0b00000001)
		return (1);
	return (0);
}

/* Return the index of the highest set bit (from l to r),
which is also the number of times I want o push from a to be and viceversa */
int	highest_set(int n)
{
	int	int_bits;
	int	i;
	int	comp;

	int_bits = sizeof(int) * 8;
	comp = 1 << (int_bits - 1);
	i = 0;
	while (i < int_bits)
	{
		if ((n << i) & comp)
			return (int_bits - i - 1);
		i++;
	}
	return (int_bits - i - 1);
}
