/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 14:26:10 by ncolliau          #+#    #+#             */
/*   Updated: 2015/03/03 17:10:58 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		r_or_rr(t_pile st)
{
	int		i;

	i = 0;
	if (st.pile[B][END_B] < st.pile[A][END_A] && st.pile[B][END_B] > st.pile[A][0])
		return (0);
	while (st.pile[B][END_B] > st.pile[A][i] || st.pile[B][END_B] < st.pile[A][i + 1])
		i++;
	return (i < st.s1 / 2) ? - i - 1 : END_A - i;
}

t_pile	insert_sort(t_pile st)
{
	int		max;
	int		min;
	int		ret;

	while (check_tab(st.pile[A], st.s1) != 1)
	{
		if (st.pile[A][END_A] > st.pile[A][END_A - 1])
			st = push(B, st);
		else
			st = rotate(A, st);
	}
	//disp_piles(st);
	while (st.s2 != 0)
	{
		max = get_max(st.pile[A], st.s1);
		min = get_min(st.pile[A], st.s1);
		if (st.pile[B][END_B] > max)
			ret = r_or_rr_cmp_max(st, max);
		else if (st.pile[B][END_B] < min)
			ret = r_or_rr_cmp_min(st, min);
		else
			ret = r_or_rr(st);
		while (ret != 0)
		{
			st = (ret > 0) ? rotate(A, st) : reverse_rotate(A, st);
			ret = (ret > 0) ? ret - 1 : ret + 1;
		}
		st = push(A, st);
		//disp_piles(st);
	}
	//disp_piles(st);
	ret = r_or_rr_cmp_min(st, min);
	while (ret != 0)
	{
		st = (ret > 0) ? rotate(A, st) : reverse_rotate(A, st);
		ret = (ret > 0) ? ret - 1 : ret + 1;
	}
	ft_putchar('\n');
	return (st);
}