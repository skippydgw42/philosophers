/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:30:01 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/28 15:54:53 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;
	// t_philo	*ptr;

	ft_parsing(ac, av);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	philo = ft_initphilos(av);
	ft_create(philo);
	while (philo->alive)
	{
		pthread_join(philo->p, NULL);
	}
	ft_destroy(philo);
	ft_free_all(philo);
	return (0);
}
