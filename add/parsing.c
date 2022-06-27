/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:57:25 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/27 18:07:59 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

int	ft_parsing(int ac, char **av)
{
	(void)av;
	if (ac < 5 || ac > 6)
		return (ft_stderr("Bad Args Count\n"));
	return (1);
}