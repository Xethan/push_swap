/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 18:00:42 by ncolliau          #+#    #+#             */
/*   Updated: 2015/03/08 16:29:42 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	get_piles(t_pile st, int ac, char **av)
{
	int		i;

	i = 1;
	st.pile = (int **)malloc(2 * sizeof(int *));
	st.pile[B] = (int *)malloc(1 * sizeof(int));
	st.s2 = 0;
	st.s1 = ac - 1;
	st.pile[A] = (int *)malloc((ac - 1) * sizeof(int));
	while (av[i])
	{
		st.pile[A][st.s1 - i] = ft_atoi(av[i]);
		i++;
	}
	return (st);
}

int		main(int ac, char **av)
{
	t_pile	st;

	if (check_error(ac, av) == 0)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	st = get_piles(st, ac, av);
	st = pivot_sort(st);
	st = clever_sort(st);
	st = insert_sort(st);
	if (check_tab(st.pile[A], st.s1) == 1 && st.s2 == 0)
		ft_putchar('\n');
	free(st.pile[A]);
	free(st.pile[B]);
	free(st.pile);
	return (0);
}
