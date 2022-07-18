/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:40:35 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/07/18 14:01:45 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

int	ft_checkchar(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_parsing(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (ft_stderr("Bad Args Count"));
	if (!ft_checkchar(ac, av))
		return (ft_stderr("Wrong Char Input"));
	if (av[5])
	{
		if (ft_atoi(av[5]) <= 0)
			return (ft_stderr("Need positive nb rounds!"));
	}
	return (1);
}
