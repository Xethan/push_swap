/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 15:02:46 by ncolliau          #+#    #+#             */
/*   Updated: 2015/03/06 18:00:09 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_pivot(t_pile st)
{
	int		less;
	int		pivot;
	int		min;
	int		max;
	int		i;

	less = 0;
	min = get_min(st.pile[A], st.s1);
	max = get_max(st.pile[A], st.s1);
	while (less < 9 * st.s1 / 100 || less > 11 * st.s1 / 100)
	{
		less = 0;
		pivot = (min + max) / 2;
		i = 0;
		while (i != st.s1)
		{
			if (st.pile[A][i] < pivot)
				less++;
			i++;
		}
		if (less < 9 * st.s1 / 100)
			min = pivot;
		else
			max = pivot;
	}
	return (pivot);
}

t_pile	pivot_sort(t_pile st)
{
	int		pivot;
	int		size;
	int		i;

	while (st.s1 > 50)
	{
		size = st.s1;
		pivot = get_pivot(st);
		i = 0;
		while (i != size)
		{
			if (END_A < pivot)
				st = push(B, st);
			else
				st = rotate(A, st);
			i++;
		}
	}
	//st = basic_sort(st);
	st = bubble_sort(st);
	st = insert_sort(st);
	return (st);
}
