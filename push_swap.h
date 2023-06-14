/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:27:57 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/14 10:41:07 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				n;
	struct s_list	*next;
}					t_list;
t_list	*clst_newnode(int n);
int		clst_size(t_list *lst);
t_list	*clst_last(t_list *lst);
void	clst_append(t_list **lst, t_list *node);
void	clst_push(t_list **lst, t_list *new_node);
t_list	*clst_pop(t_list **lst);
void	clst_swap(t_list **lst);
void	clst_rotate(t_list **lst);
void	clst_rev_rotate(t_list **lst);
void	print_clst(t_list *lst);

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);

#endif
