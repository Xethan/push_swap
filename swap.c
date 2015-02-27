/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 12:04:41 by ncolliau          #+#    #+#             */
/*   Updated: 2015/02/27 13:17:51 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	swap(t_ab ab, t_pile st)
{
	int		tmp;
	int		size;

	size = (ab == A) ? st.s1 : st.s2;
	tmp = st.pile[ab][size - 2];
	st.pile[ab][size - 2] = st.pile[ab][size - 1];
	st.pile[ab][size - 1] = tmp;
	return (st);
}

t_pile	rotate(t_ab ab, t_pile st)
{
	int		tmp;
	int		i;

	i = (ab == A) ? st.s1 - 1: st.s2 - 1;
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

	size = (ab == A) ? st.s1 - 1: st.s2 - 1;
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
	if (ab == A)
	{
		st.pile[A][st.s1] = st.pile[B][st.s2 - 1];
		st.s1++;
		st.s2--;
	}
	else
	{
		st.pile[B][st.s2] = st.pile[A][st.s1 - 1];
		st.s2++;
		st.s1--;
	}
	return (st);
}