/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:27:57 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/16 14:40:54 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// ------------------------ CLISTS ------------------------
typedef struct s_clist
{
	int				n;
	struct s_clist	*next;
}					t_clist;
t_clist	*clst_newnode(int n);
int		clst_size(t_clist *lst);
t_clist	*clst_last(t_clist *lst);
void	clst_append(t_clist **lst, t_clist *node);
void	clst_push(t_clist **lst, t_clist *new_node);
t_clist	*clst_pop(t_clist **lst);
void	clst_swap(t_clist **lst);
void	clst_rotate(t_clist **lst);
void	clst_rev_rotate(t_clist **lst);
void	clst_print(t_clist *lst);

// ------------------------ VALIDATION ------------------------
int		is_valid_argc(int argc);
int		is_valid_argv(char *argv, t_clist *lst);

// ------------------------ UTILS ------------------------
int		ft_isdigit(int c);
int		ft_strlen(char *str);
int		error(void);
char	*ft_strchr(char *str, int c);
char	**ft_split(char *s, char c);
long	ft_atol(char *str);
void	free_dptr(char **s);

#endif
