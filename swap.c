/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 12:04:41 by ncolliau          #+#    #+#             */
/*   Updated: 2015/03/03 16:07:17 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	swap(t_ab ab, t_pile st)
{
	int		tmp;
	int		size;

	(ab == A) ? ft_putstr("sa ") : ft_putstr("sb ");
	size = (ab == A) ? END_A : END_B;
	if (size <= 0)
		return (st);
	tmp = st.pile[ab][size - 1];
	st.pile[ab][size - 1] = st.pile[ab][size];
	st.pile[ab][size] = tmp;
	return (st);
}

t_pile	rotate(t_ab ab, t_pile st)
{
	int		tmp;
	int		i;

	(ab == A) ? ft_putstr("ra ") : ft_putstr("rb ");
	i = (ab == A) ? END_A : END_B;
	if (i <= 0)
		return (st);
	while (i != 0)
	{
		tmp = st.pile[ab][i];
		st.pile[ab][i] = st.pile[ab][i - 1];
		st.pile[ab][i - 1] = tmp;
		i--;
	}
	return (st);
}

t_pile	reverse_rotate(t_ab ab, t_pile st)
{
	int		tmp;
	int		i;
	int		size;

	(ab == A) ? ft_putstr("rra ") : ft_putstr("rrb ");
	size = (ab == A) ? END_A : END_B;
	if (size <= 0)
		return (st);
	i = 0;
	while (i != size)
	{
		tmp = st.pile[ab][i];
		st.pile[ab][i] = st.pile[ab][i + 1];
		st.pile[ab][i + 1] = tmp;
		i++;
	}
	return (st);
}

t_pile	push(t_ab ab, t_pile st)
{
	(ab == A) ? ft_putstr("pa ") : ft_putstr("pb ");
	if ((ab == A && st.s2 == 0) || (ab == B && st.s1 == 0))
		return (st);
	if (ab == A)
		st.pile[A][st.s1] = st.pile[B][st.s2 - 1];
	else
		st.pile[B][st.s2] = st.pile[A][st.s1 - 1];
	(ab == A) ? st.s1++ : st.s1--;
	(ab == A) ? st.s2-- : st.s2++;
	return (st);
}