/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:58:25 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/07/01 17:05:41 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

long	ft_gettime(void)
{
	struct timeval	current;
	long			time;

	gettimeofday(&current, NULL);
	time = current.tv_sec * 1000;
	time += current.tv_usec / 1000;
	return (time);
}

void	ft_isalive(t_philo *philo)
{
	long	isalive;

	isalive = 0;
	if (philo->time != 0)
		isalive = ft_gettime() - philo->time;
	else
		isalive = ft_gettime() - philo->start_time;
	if (isalive > philo->data->time_die)
	{
		philo->finish_time = ft_gettime();
		philo->data->alive = 0;
	}
}

int	ft_block_fork(t_fork *fork, int ready)
{
	pthread_mutex_lock(&fork->mutex);
	if (fork->state == 1)
		fork->state = 0;
	else
		return (0);
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
		{
			block = ft_block_fork(philo->fork, block);
			if (block == 0)
				pthread_mutex_unlock(&philo->fork->mutex);
		}
		else if (block == 1 && philo->next != philo)
		{
			block = ft_block_fork(philo->next->fork, block);
			if (block == 0)
				pthread_mutex_unlock(&philo->next->fork->mutex);
		}
	}
	return (1);
}

void	ft_thinking(t_philo *philo)
{
	ft_isalive(philo);
	if (philo->data->alive == 1 && philo->data->nrounds != 0)
		printf("%ld %d is thinking\n", ft_gettime(), philo->name);
}

void	ft_eat(t_philo *philo)
{
	ft_isalive(philo);
	ft_take_fork(philo);
	ft_isalive(philo);
	if (philo->data->alive == 1)
	{
		if (philo->time)
			printf("%ld %d is eating\n", philo->time, philo->name);
		else
			printf("%ld %d is eating\n", philo->start_time, philo->name);
		usleep(philo->data->time_eat * 1000);
		if (philo->data->nrounds > 0)
		{
			if (philo->data->sated == philo->data->nphilo)
			{
				philo->data->sated = 0;
				philo->data->nrounds--;
				if (philo->data->nrounds == 0)
					philo->finish_time = -1;
			}
			philo->data->sated++;
		}
		philo->time = ft_gettime();
		philo->fork->state = 1;
		pthread_mutex_unlock(&philo->fork->mutex);
		philo->next->fork->state = 1;
		pthread_mutex_unlock(&philo->next->fork->mutex);
	}
}

void	ft_sleep(t_philo *philo)
{
	ft_isalive(philo);
	if (philo->data->alive == 1 && philo->data->nrounds != 0)
	{
		printf("%ld %d is sleeping\n", ft_gettime(), philo->name);
		usleep(philo->data->time_sleep * 1000);
	}
}

void	*routine(void *philo)
{
	t_philo	*ptr;

	ptr = philo;
	if (ptr->name % 2 == 0)
		usleep(100);
	ptr->start_time = ft_gettime();
	while (ptr->data->alive == 1 && ptr->data->nrounds != 0)
	{
		ft_thinking(philo);
		ft_eat(ptr);
		if (ptr->data->nrounds != 0)
			ft_sleep(ptr);
	}
	if (ptr->finish_time > 0)
	{
		usleep(100);
		printf("%ld %d is dead\n", ptr->finish_time, ptr->name);
	}
	else if (ptr->finish_time == -1)
	{
		usleep(100);
		printf("Rounds passed\n");
	}
	return (NULL);
}
