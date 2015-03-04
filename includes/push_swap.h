/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 12:04:41 by ncolliau          #+#    #+#             */
/*   Updated: 2015/03/04 12:42:49 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"

# define END_A	(st.s1 - 1)
# define END_B	(st.s2 - 1)

typedef enum	e_ab
{
	A = 0, B = 1
}				t_ab;

typedef struct	s_pile
{
	int			**pile;
	int			s1;
	int			s2;
}				t_pile;

t_pile			swap(t_ab ab, t_pile st);
t_pile			rotate(t_ab ab, t_pile st);
t_pile			reverse_rotate(t_ab ab, t_pile st);
t_pile			push(t_ab ab, t_pile st);

int				check_error(int ac, char **av);

t_pile			insert_sort(t_pile st);
t_pile			bubble_sort(t_pile st);

int				get_max(int *tab, int size);
int				get_max_pos(int *tab, int size);
int				get_min(int *tab, int size);
int				r_or_rr_cmp_max(t_pile st, int max);
int				r_or_rr_cmp_min(t_pile st, int min);
int				check_tab(int *tab, int size);
int				count_errors(int *tab, int size);

void			disp_piles(t_pile st);

#endif