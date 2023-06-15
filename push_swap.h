/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:27:57 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/14 14:53:04 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_clist
{
	int				n;
	struct s_clist	*next;
}					t_clist;
typedef struct s_ps
{
	t_clist	*a;
	t_clist	*b;
	int		max_size;
}				t_ps;
t_clist	*clst_newnode(int n);
int		clst_size(t_clist *lst);
t_clist	*clst_last(t_clist *lst);
void	clst_append(t_clist **lst, t_clist *node);
void	clst_push(t_clist **lst, t_clist *new_node);
t_clist	*clst_pop(t_clist **lst);
void	clst_swap(t_clist **lst);
void	clst_rotate(t_clist **lst);
void	clst_rev_rotate(t_clist **lst);
void	print_clst(t_clist *lst);

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);

#endif
