/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:47:36 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/16 10:12:27 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dest, char *src, size_t d_size)
{
	size_t	i;
	size_t	s_size;

	i = 0;
	s_size = ft_strlen(src);
	if (d_size > 0)
	{
		while ((i < s_size) && (i < d_size - 1))
		{
			if (src[i])
				dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (s_size);
}


static	void	free_memory(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static	int	get_str_length(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static	int	get_n_words(char *s, char c)
{
	int	i;
	int	len;
	int	n_words;

	i = 0;
	n_words = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			n_words += 1;
			len = get_str_length(s + i, c);
			i += len;
		}
	}
	return (n_words);
}

static	char	**allocate_words(char *s, int n_words)
{
	char	**p;

	if (!s)
		return (NULL);
	p = malloc ((n_words + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	*(p + n_words) = NULL;
	return (p);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		n_words;
	char	**p;

	n_words = get_n_words(s, c);
	p = allocate_words(s, n_words);
	if (!p)
		return (NULL);
	i = 0;
	while (i < n_words)
	{
		if (*s == c)
			s++;
		else
		{
			p[i] = malloc((get_str_length(s, c) + 1) * sizeof(char));
			if (!(p[i]))
				return (free_memory(p), NULL);
			ft_strlcpy(p[i], s, get_str_length(s, c) + 1);
			s += get_str_length(s, c);
			i++;
		}
	}
	return (p);
}
