/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:47:36 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/24 17:24:02 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_double_pointer(char **s)
{
	int	i;
	int	j;

	if (!s)
		return ;
	i = 0;
	j = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
