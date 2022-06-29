/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:30:01 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/29 17:17:22 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_philo	*ptr;
	t_data	*data;
	int		i;

	ft_parsing(ac, av);
	philo = ft_initphilos(av);
	data = ft_initdata(av);
	ft_joindata(philo, data);
	ft_create(philo);
	ptr = philo;
	i = 0;
	while (i < philo->data->nphilo)
	{
		pthread_join(ptr->p, NULL);
		ptr = ptr->next;
		i++;
	}
	ft_destroy(philo);
	ft_free_all(philo);
	return (0);
}
