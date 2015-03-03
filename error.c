/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolliau <ncolliau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 15:00:55 by ncolliau          #+#    #+#             */
/*   Updated: 2015/03/03 15:46:45 by ncolliau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_number(char *str, char *cmp)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i] == '0')
		i++;
	while (str[i + len] >= '0' && str[i + len] <= '9')
		len++;
	if (len > ft_strlen(cmp))
		return (-1);
	else if (len == ft_strlen(cmp))
		return (ft_strcmp(cmp, str + i));
	return (1);
}

static int	check_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			if (str[i] != '-' && str[i] != '+')
				return (0);
		i++;
	}
	if (str[0] == '-')
	{
		if (check_number(str + 1, "2147483648") < 0)
			return (0);
	}
	else
	{
		if (str[0] == '+')
			str++;
		if (check_number(str, "2147483647") < 0)
			return (0);
	}
	return (1);
}

int		check_double(char **av)
{
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			check_error(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac == 1)
		exit(EXIT_SUCCESS);
	while (av[i])
	{
		if (check_str(av[i]) == 0)
			return (0);
		i++;
	}
	if (check_double(av) == 0)
		return (0);
	return (1);
}