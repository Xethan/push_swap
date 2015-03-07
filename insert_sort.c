/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 14:26:10 by ncolliau          #+#    #+#             */
/*   Updated: 2015/03/07 18:05:01 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		r_or_rr(t_pile st)
{
	int		i;

	i = 0;
	if (END_B < END_A && END_B > st.pile[A][0])
		return (0);
	while (END_B > st.pile[A][i] || END_B < st.pile[A][i + 1])
		i++;
	return (i < st.s1 / 2) ? -i - 1 : st.s1 - i - 1;
}

int		how_many_rot(t_pile st)
{
	int		max;
	int		min;
	int		rot;

	max = get_max(st.pile[A], st.s1);
	min = get_min(st.pile[A], st.s1);
	if (END_B > max)
		rot = r_or_rr_cmp_max(st, max);
	else if (END_B < min)
		rot = r_or_rr_cmp_min(st, min);
	else
		rot = r_or_rr(st);
	return (rot);
}

t_pile	rotation(t_pile st, int rot)
{
	while (rot != 0)
	{
		st = (rot > 0) ? rotate(A, st) : reverse_rotate(A, st);
		rot = (rot > 0) ? rot - 1 : rot + 1;
	}
	return (st);
}

t_pile	insert_sort(t_pile st)
{
	int		min;
	int		rot;

	while (check_tab(st.pile[A], st.s1) != 1)
	{
		if (END_A > st.pile[A][st.s1 - 2])
			st = push(B, st);
		else
			st = rotate(A, st);
	}
	while (st.s2 != 0)
	{
		rot = how_many_rot(st);
		st = rotation(st, rot);
		st = push(A, st);
	}
	min = get_min(st.pile[A], st.s1);
	rot = r_or_rr_cmp_min(st, min);
	st = rotation(st, rot);
	return (st);
}
