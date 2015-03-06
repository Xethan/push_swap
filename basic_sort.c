/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:53:54 by ncolliau          #+#    #+#             */
/*   Updated: 2015/03/06 17:16:13 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		where_errors(t_pile st)
{
	int		i;
	int		max;

	max = get_max_pos(st.pile[A], st.s1);
	i = max;
	max = (max == 0) ? st.s1 : max;
	while (i != max - 1)
	{
		if (i == st.s1 - 1)
		{
			if (st.pile[A][i] < st.pile[A][0])
				return (i + 1 < st.s1 / 2) ? -i - 2 : st.s1 - i - 2;
		}
		else if (st.pile[A][i] < st.pile[A][i + 1])
			return (i + 1 < st.s1 / 2) ? -i - 2 : st.s1 - i - 2;
		i++;
		if (i == st.s1)
			i = 0;
	}
	return (0);
}

t_pile	basic_sort(t_pile st)
{
	int		ret;

	while (count_errors(st.pile[A], st.s1) != 0)
	{
		ret = where_errors(st);
		while (ret != 0)
		{
			st = (ret > 0) ? rotate(A, st) : reverse_rotate(A, st);
			ret = (ret > 0) ? ret - 1 : ret + 1;
		}
		swap(A, st);
	}
	ret = r_or_rr_cmp_min(st, get_min(st.pile[A], st.s1));
	while (ret != 0)
	{
		st = (ret > 0) ? rotate(A, st) : reverse_rotate(A, st);
		ret = (ret > 0) ? ret - 1 : ret + 1;
	}
	return (st);
}
