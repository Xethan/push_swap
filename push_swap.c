/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 12:04:41 by ncolliau          #+#    #+#             */
/*   Updated: 2015/02/27 15:54:12 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	get_piles(t_pile st, int ac, char **av)
{
	int		i;

	i = 1;
	st.pile = (int **)malloc(2 * sizeof(int *));
	st.pile[B] = (int *)malloc((ac - 1) * sizeof(int));
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

void	disp_piles(t_pile st)
{
	int		i;

	ft_putendl("-----pile 1-----");
	i = 0;
	while (i != st.s1)
	{
		ft_miniprintf("%d : %d\n", i, st.pile[A][i]);
		i++;
	}
	ft_putendl("-----pile 2-----");
	i = 0;
	while (i != st.s2)
	{
		ft_miniprintf("%d : %d\n", i, st.pile[B][i]);
		i++;
	}
	ft_putendl("-----end-----");
}

t_pile	read_stdin(t_pile st)
{
	char	*line;
	int		ret;

	while ((ret = get_next_line(0, &line)) == 1)
	{
		if (ft_strequ(line, "exit") == 1)
		{
			free(line);
			return (st);
		}
		if (ft_strequ(line, "sa") == 1)
			st = swap(A, st);
		if (ft_strequ(line, "sb") == 1)
			st = swap(B, st);
		if (ft_strequ(line, "ra") == 1)
			st = rotate(A, st);
		if (ft_strequ(line, "rb") == 1)
			st = rotate(B, st);
		if (ft_strequ(line, "rra") == 1)
			st = reverse_rotate(A, st);
		if (ft_strequ(line, "rrb") == 1)
			st = reverse_rotate(B, st);
		if (ft_strequ(line, "pa") == 1)
			st = push(A, st);
		if (ft_strequ(line, "pb") == 1)
			st = push(B, st);
		disp_piles(st);
		free(line);
	}
	if (ret == -1)
		ft_putendl_fd("Error get_next_line", 2);
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
	//st = read_stdin(st);
	st = split_sort(st);
	free(st.pile[A]);
	free(st.pile[B]);
	free(st.pile);
	return (0);
}