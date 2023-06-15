/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:26:48 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/15 16:33:22 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	char	*p;
	int		i;

	p = (char *) str;
	i = 0;
	if ((char)c == '\0')
		return (p + ft_strlen(str));
	while (p[i])
	{
		if (p[i] == (char)c)
			return (p + i);
		i++;
	}
	return (NULL);
}
