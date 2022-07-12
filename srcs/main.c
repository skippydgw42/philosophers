/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:30:01 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/07/12 17:56:44 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_philo	*ptr;
	t_data	*data;
	int		i;

	i = 0;
	if (!ft_parsing(ac, av))
		return (0);
	philo = ft_initphilos(av);
	data = ft_initdata(av);
	ft_joindata(philo, data);
	ft_create(philo);
	ptr = philo;
	while (ptr)
	{
		pthread_join(ptr->p, NULL);
		ptr = ptr->next;
	}
	ft_free_all(philo);
	return (0);
}
