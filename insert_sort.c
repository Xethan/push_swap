/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 14:26:10 by ncolliau          #+#    #+#             */
/*   Updated: 2015/03/06 17:15:45 by ncolliau         ###   ########.fr       */
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

t_pile	insert_sort(t_pile st)
{
	int		max;
	int		min;
	int		ret;

	while (check_tab(st.pile[A], st.s1) != 1)
	{
		if (END_A > st.pile[A][st.s1 - 2])
			st = push(B, st);
		else
			st = rotate(A, st);
	}
	while (st.s2 != 0)
	{
		max = get_max(st.pile[A], st.s1);
		min = get_min(st.pile[A], st.s1);
		if (END_B > max)
			ret = r_or_rr_cmp_max(st, max);
		else if (END_B < min)
			ret = r_or_rr_cmp_min(st, min);
		else
			ret = r_or_rr(st);
		while (ret != 0)
		{
			st = (ret > 0) ? rotate(A, st) : reverse_rotate(A, st);
			ret = (ret > 0) ? ret - 1 : ret + 1;
		}
		st = push(A, st);
	}
	min = get_min(st.pile[A], st.s1);
	ret = r_or_rr_cmp_min(st, min);
	while (ret != 0)
	{
		st = (ret > 0) ? rotate(A, st) : reverse_rotate(A, st);
		ret = (ret > 0) ? ret - 1 : ret + 1;
	}
	return (st);
}
