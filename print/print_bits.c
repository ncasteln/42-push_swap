/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 13:04:10 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/24 17:30:42 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_bits(int n)
{
	int	int_bits;
	int	msb;
	int	n_cpy = n;

	int_bits = sizeof(int) * 8;
	msb = 0b00000001 << (int_bits - 1);
	while (int_bits > 0)
	{
		if (n & msb)
			ft_printf("1");
		else
			ft_printf("0");
		n <<= 1;
		int_bits--;
	}
	ft_printf("\tHighest set is: ", highest_set(n_cpy));
	if (is_set(n_cpy, 0))
		ft_printf("  is_set\n");
	else
		ft_printf("  not_set\n");
}

