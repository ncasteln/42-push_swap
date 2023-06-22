/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 08:31:26 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/22 13:50:14 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	fill(char *p, int n, int sign, size_t len)
{
	size_t	i;

	i = 0;
	if (n == 0)
		p[0] = '0';
	if (sign == -1)
	{
		p[i] = '-';
		i++;
	}
	p[len] = '\0';
	while (n > 0)
	{
		p[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
}

static	int	get_length(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_strdup(char *str)
{
	char	*p;
	size_t	len;
	int		i;

	len = ft_strlen(str);
	p = malloc (len + 1);
	if (!p)
		return (0);
	i = 0;
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	*(p + len) = '\0';
	return (p);
}

static char	*ft_itoa(int n)
{
	int		sign;
	size_t	len;
	char	*p;

	p = NULL;
	sign = 1;
	len = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else
	{
		if (n < 0)
		{
			sign = -1;
			n = n * -1;
			len++;
		}
		len += get_length(n);
		p = malloc ((len + 1) * sizeof(char));
		if (!p)
			return (NULL);
		fill(p, n, sign, len);
	}
	return (p);
}

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

void	print_bits(int n)
{
	int	int_bits;
	int	msb;
	int	n_cpy = n;

	ft_putstr_fd(ft_itoa(n), 1);
	ft_putstr_fd("   ", 1);
	int_bits = sizeof(int) * 8;
	msb = 0b00000001 << (int_bits - 1);
	while (int_bits > 0)
	{
		if (n & msb)
			ft_putchar_fd('1', 1);
		else
			ft_putchar_fd('0', 1);
		n <<= 1;
		int_bits--;
	}
	ft_putstr_fd("\tHighest set is: ", 1);
	ft_putstr_fd(ft_itoa(highest_set(n_cpy)), 1);
	if (is_set(n_cpy, 0))
		ft_putstr_fd("  is_set", 1);
	else
		ft_putstr_fd("  not_set", 1);
	ft_putchar_fd('\n', 1);
}

