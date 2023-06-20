/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:27:57 by ncasteln          #+#    #+#             */
/*   Updated: 2023/06/20 12:32:25 by ncasteln         ###   ########.fr       */
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
void	clst_clear(t_clist **lst);
void	clst_print(t_clist *lst, char name);

// ------------------------ CLISTS MOVES ------------------------
void	clst_pop_push(t_clist **src, t_clist **dst, char *name);
void	clst_swap(t_clist **lst, char *name);
void	clst_ss(t_clist **a, t_clist **b);
void	clst_rotate(t_clist **lst, char *name);
void	clst_rr(t_clist **a, t_clist **b);
void	clst_rev_rotate(t_clist **lst, char *name);
void	clst_rrr(t_clist **a, t_clist **b);

// ------------------------ VALIDATION ------------------------
int		is_valid_argc(int argc);
int		is_valid_argv(char *argv, t_clist *lst);

// ------------------------ SORTING ------------------------
int		is_sorted(t_clist *lst);
int		get_best_sort(int argc, t_clist **a, t_clist **b);

// ------------------------ UTILS ------------------------
int		ft_isdigit(int c);
int		ft_strlen(char *str);
int		error(void);
char	*ft_strchr(char *str, int c);
char	**ft_split(char *s, char c);
long	ft_atol(char *str);
void	free_double_pointer(char **s);
void	ft_putstr_fd(char *s, int fd);

#endif
