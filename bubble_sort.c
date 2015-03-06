/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 14:56:39 by ncolliau          #+#    #+#             */
/*   Updated: 2015/03/06 17:18:28 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	bubble_sort(t_pile st)
{
	int		max;

	while (check_tab(st.pile[A], st.s1) == 0)
	{
		max = get_max(st.pile[A], st.s1);
		if (END_A < st.pile[A][st.s1 - 2] || END_A == max)
			st = rotate(A, st);
		else
			st = swap(A, st);
	}
	return (st);
}
