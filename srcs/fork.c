/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:54:19 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/07/12 14:00:48 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

int	ft_block_fork(t_fork *fork, int ready)
{
	//thread a lock avant ou dans le "if" ??
	pthread_mutex_lock(&fork->mutex);
	if (fork->state == 1)
		fork->state = 0;
	else
	{
		pthread_mutex_unlock(&fork->mutex);
		return (0);
	}
	return (ready + 1);
}

int	ft_take_fork(t_philo *philo)
{
	int	block;

	block = 0;
	while (block < 2 && philo->data->alive == 1 && philo->data->nrounds != 0)
	{
		ft_isalive(philo);
		if (block == 0)
			block = ft_block_fork(philo->fork, block);
		else if (block == 1 && philo->next != philo)
			block = ft_block_fork(philo->next->fork, block);
	}
	printf("%ld %d has taken a fork\n", ft_gettime(philo), philo->name);
	printf("%ld %d has taken a fork\n", ft_gettime(philo), philo->name);
	return (1);
}

// int	take_fork(t_philo *philo)
// {
// 	while (ft_isalive(philo) && philo->data->nrounds != 0)
// 	{
// 		if (philo->fork->state == 1 && pthread_mutex_lock(&philo->fork->mutex) == 0)
// 		{
// 			philo->fork->state = 0;
// 			if (philo->next->fork->state == 1 && pthread_mutex_lock(&philo->next->fork->mutex) == 0)
// 			{
// 				philo->next->fork->state = 0;
// 				printf("%ld %d has taken a fork\n", ft_gettime(philo), philo->name);
// 				printf("%ld %d has taken a fork\n", ft_gettime(philo), philo->name);
// 				return (1);
// 			}
// 			else
// 			{
// 				philo->fork->state = 1;
// 				pthread_mutex_unlock(&philo->fork->mutex);
// 			}
// 		}
// 	}
// 	while (ft_isalive(philo) && philo->data->nrounds != 0)
// 	{
// 		if (philo->next->fork->state == 1 && pthread_mutex_lock(&philo->next->fork->mutex) == 0)
// 		{
// 			philo->next->fork->state = 0;
// 			printf("%ld %d has taken a fork\n", ft_gettime(philo), philo->name);
// 			printf("%ld %d has taken a fork\n", ft_gettime(philo), philo->name);
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

int	take_fork(t_philo *philo)
{
	while (ft_isalive(philo) && philo->data->nrounds != 0)
	{
		if (philo->fork->state == 1)
		{
			pthread_mutex_lock(&philo->fork->mutex);
			philo->fork->state = 0;
			if (philo->next->fork->state == 1)
			{
				pthread_mutex_lock(&philo->next->fork->mutex);
				philo->next->fork->state = 0;
				break ;
			}
			else
			{
				philo->fork->state = 1;
				pthread_mutex_unlock(&philo->fork->mutex);
			}
		}
	}
	printf("%ld %d has taken a fork\n", ft_gettime(philo), philo->name);
	printf("%ld %d has taken a fork\n", ft_gettime(philo), philo->name);
	return (0);
}