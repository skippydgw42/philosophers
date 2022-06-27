/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:58:25 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/27 19:32:11 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

//pour lock les forks
	//lock
	//faire l'action
	//unlock

void	ft_eat(t_data *data)
{
	usleep(data->time_eat);
}

void	ft_sleep(t_data *data)
{
	usleep(data->time_sleep);
}

void	*routine(void *data)
{
	t_data	*ptr;

	ptr = data;
	printf("n: %d\n", ptr->nphilo);
	gettimeofday(&ptr->c_time, NULL);
	printf("before routine: %ld\n", ptr->c_time.tv_sec);
	ft_eat(ptr);
	ft_sleep(ptr);
	gettimeofday(&ptr->c_time, NULL);
	printf("after routine: %ld\n", ptr->c_time.tv_sec);
	return (NULL);
}