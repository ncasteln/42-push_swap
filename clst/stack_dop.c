/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_dop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:51:56 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/26 11:55:18 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clst_d_swap(t_clist **a, t_clist **b)
{
	clst_swap(a, ' ');
	clst_swap(b, ' ');
	ft_printf("ss\n", 1);
}

void	clst_d_rotate(t_clist **a, t_clist **b)
{
	clst_rotate(a, ' ');
	clst_rotate(b, ' ');
	ft_printf("rr\n");
}

void	clst_dr_rotate(t_clist **a, t_clist **b)
{
	clst_rev_rotate(a, ' ');
	clst_rev_rotate(b, ' ');
	ft_printf("rrr\n");
}
