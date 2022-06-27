/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:30:01 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/27 19:31:45 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	ft_parsing(ac, av);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	ft_initstruct(data, av);
	ft_initphilos(data);

	//faire tourner la routine
	while (data->lst)
	{
		pthread_detach(data->lst->p);
		data->lst = data->lst->next;
	}
	// ft_destroy(data);
	// ft_free_data(data);
	return (0);
}
