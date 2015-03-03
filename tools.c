/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 17:06:04 by ncolliau          #+#    #+#             */
/*   Updated: 2015/03/03 17:11:20 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_max(int *tab, int size)
{
	int		max;
	int		i;

	i = 1;
	max = tab[0];
	while (i != size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int		get_min(int *tab, int size)
{
	int		min;
	int		i;

	i = 1;
	min = tab[0];
	while (i != size)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int		r_or_rr_cmp_max(t_pile st, int max)
{
	int		i;

	i = 0;
	while (st.pile[A][i] != max)
		i++;
	return (i < st.s1 / 2) ? - i : st.s1 - i;
}

int		r_or_rr_cmp_min(t_pile st, int min)
{
	int		i;

	i = 0;
	while (st.pile[A][i] != min)
		i++;
	return (i < st.s1 / 2) ? - i - 1 : END_A - i;
}

int		check_tab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i != size - 1)
	{
		if (tab[i] < tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
