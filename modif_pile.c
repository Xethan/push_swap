/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 18:02:25 by ncolliau          #+#    #+#             */
/*   Updated: 2015/03/08 17:00:57 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	swap(t_ab ab, t_pile st)
{
	int		tmp;
	int		size;

	size = (ab == A) ? st.s1 - 1 : st.s2 - 1;
	if (size <= 0)
		return (st);
	tmp = st.pile[ab][size - 1];
	st.pile[ab][size - 1] = st.pile[ab][size];
	st.pile[ab][size] = tmp;
	(ab == A) ? ft_putstr("sa") : ft_putstr("sb");
	if (check_tab(st.pile[A], st.s1) == 0 || st.s2 != 0)
		write(1, " ", 1);
	return (st);
}

t_pile	rotate(t_ab ab, t_pile st)
{
	int		tmp;
	int		i;

	i = (ab == A) ? st.s1 - 1 : st.s2 - 1;
	if (i <= 0)
		return (st);
	while (i != 0)
	{
		tmp = st.pile[ab][i];
		st.pile[ab][i] = st.pile[ab][i - 1];
		st.pile[ab][i - 1] = tmp;
		i--;
	}
	(ab == A) ? ft_putstr("ra") : ft_putstr("rb");
	if (check_tab(st.pile[A], st.s1) == 0 || st.s2 != 0)
		write(1, " ", 1);
	return (st);
}

t_pile	reverse_rotate(t_ab ab, t_pile st)
{
	int		tmp;
	int		i;
	int		size;

	size = (ab == A) ? st.s1 - 1 : st.s2 - 1;
	if (size <= 0)
		return (st);
	i = 0;
	while (i != size)
	{
		tmp = st.pile[ab][i];
		st.pile[ab][i] = st.pile[ab][i + 1];
		st.pile[ab][i + 1] = tmp;
		i++;
	}
	(ab == A) ? ft_putstr("rra") : ft_putstr("rrb");
	if (check_tab(st.pile[A], st.s1) == 0 || st.s2 != 0)
		write(1, " ", 1);
	return (st);
}

int		*copy_tab(int *tab, int size, int new_size)
{
	int		*tmp;
	int		i;

	tmp = tab;
	tab = (int *)malloc(new_size * sizeof(int));
	i = 0;
	while (i != size && i != new_size)
	{
		tab[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (tab);
}

t_pile	push(t_ab ab, t_pile st)
{
	if ((ab == A && st.s2 == 0) || (ab == B && st.s1 == 0))
		return (st);
	if (ab == A)
	{
		st.pile[A] = copy_tab(st.pile[A], st.s1, st.s1 + 1);
		st.pile[A][st.s1] = st.pile[B][st.s2 - 1];
		st.pile[B] = copy_tab(st.pile[B], st.s2, st.s2 - 1);
	}
	else
	{
		st.pile[B] = copy_tab(st.pile[B], st.s2, st.s2 + 1);
		st.pile[B][st.s2] = st.pile[A][st.s1 - 1];
		st.pile[A] = copy_tab(st.pile[A], st.s1, st.s1 - 1);
	}
	(ab == A) ? st.s1++ : st.s1--;
	(ab == B) ? st.s2++ : st.s2--;
	(ab == A) ? ft_putstr("pa") : ft_putstr("pb");
	if (check_tab(st.pile[A], st.s1) == 0 || st.s2 != 0)
		write(1, " ", 1);
	return (st);
}
