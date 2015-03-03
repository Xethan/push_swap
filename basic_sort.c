/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 16:53:54 by ncolliau          #+#    #+#             */
/*   Updated: 2015/03/03 17:19:54 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		where_errors(t_pile st)
{
	int		i;

	i = 0;
	while (i != END_A)
	{
		if (st.pile[A][i] < st.pile[A][i + 1])
			return (i + 1 < st.s1 / 2) ? - i - 2 : END_A - i - 1;
		i++;
	}
	return (1);
}

t_pile basic_sort(t_pile st)
{
	int		ret;
	int		min;

	min = get_min(st.pile[A], st.s1);
	ret = where_errors(st);
	while (ret != 0)
	{
		st = (ret > 0) ? rotate(A, st) : reverse_rotate(A, st);
		ret = (ret > 0) ? ret - 1 : ret + 1;
	}
	if (check_tab(st.pile[A], st.s1))
		return (st);
	st = swap(A, st);
	ret = r_or_rr_cmp_min(st, min);
	while (ret != 0)
	{
		st = (ret > 0) ? rotate(A, st) : reverse_rotate(A, st);
		ret = (ret > 0) ? ret - 1 : ret + 1;
	}
	ft_putchar('\n');
	disp_piles(st);
	return (st);
}
