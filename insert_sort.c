/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 14:26:10 by ncolliau          #+#    #+#             */
/*   Updated: 2015/02/27 15:34:24 by ncolliau         ###   ########.fr       */
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

t_pile	split_sort(t_pile st)
{
	int		max;
	int		min;
	int		i;

	i = 0;
	while (st.s1 != 2)
	{
		st = push(B, st);
		i++;
	}
	//disp_piles(st);
	while (st.s2 != 0)
	{
		max = get_max(st.pile[A], st.s1);
		min = get_min(st.pile[A], st.s1);
		if (st.pile[B][END_B] > max)
		{
			while (st.pile[A][END_A] != min)
			{
				st = rotate(A, st); // ra ou rra pour opti
				i++;
			}
		}
		else if (st.pile[B][END_B] < min)
		{
			while (st.pile[A][0] != max)
			{
				st = rotate(A, st); // ra ou rra pour opti
				i++;
			}
		}
		else
		{
			while (!(st.pile[B][END_B] < st.pile[A][END_A] && st.pile[B][END_B] > st.pile[A][0]))
			{
				st = rotate(A, st); // ra ou rra pour opti
				i++;
			}
		}
		st = push(A, st);
		i++;
		//disp_piles(st);
	}
	while (check_tab(st.pile[A], st.s1) != 1)
	{
		st = rotate(A, st);
		i++;
	}
	ft_miniprintf("Success in %d operations !\n", i);
	//disp_piles(st);
	return (st);
}