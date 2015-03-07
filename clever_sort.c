/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clever_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 14:56:39 by ncolliau          #+#    #+#             */
/*   Updated: 2015/03/07 17:43:13 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	clever_sort(t_pile st)
{
	int		min;
	int		pushed;

	pushed = 0;
	while (check_tab(st.pile[A], st.s1) == 0)
	{
		min = get_min(st.pile[A], st.s1);
		if (END_A == min)
		{
			pushed++;
			st = push(B, st);
		}
		else if (END_A > st.pile[A][st.s1 - 2])
			st = swap(A, st);
		else
			st = reverse_rotate(A, st);
	}
	while (pushed != 0)
	{
		pushed--;
		st = push(A, st);
	}
	return (st);
}
