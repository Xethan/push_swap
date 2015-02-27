/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 12:04:41 by ncolliau          #+#    #+#             */
/*   Updated: 2015/02/27 15:01:42 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "get_next_line.h"

# define END_A	st.s1 - 1
# define END_B	st.s2 - 1

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

t_pile			split_sort(t_pile st);

void			disp_piles(t_pile st);

#endif