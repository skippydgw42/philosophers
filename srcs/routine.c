/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:58:25 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/28 18:48:29 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

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
	while (block < 2)
	{
		if (block == 0)
		{
			block = ft_block_fork(philo->fork, block);
			if (block == 0)
				pthread_mutex_unlock(&philo->fork->mutex);
		}
		else if (block == 1)
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
	gettimeofday(&philo->data->c_time, NULL);
	printf("%ld %d is thinking\n", philo->data->c_time.tv_sec, philo->name);
}

void	ft_isalive(t_philo *philo)
{
	int	isalive;

	isalive = 0;
	gettimeofday(&philo->data->c_time, NULL);
	if (philo->time != 0)
		isalive = philo->data->c_time.tv_sec - philo->time;
	else
		isalive = philo->data->c_time.tv_sec - philo->start_time;
	if (isalive > philo->data->time_die) //pas la meme unite ?
		philo->alive = 0;
	printf("isalive: %d\n", isalive);
}

void	ft_eat(t_philo *philo)
{
	ft_take_fork(philo);
	ft_isalive(philo);
	if (philo->alive == 1)
	{
		printf("%d %d is eating\n", philo->time, philo->name);
		usleep(philo->data->time_eat * 1000);
		gettimeofday(&philo->data->c_time, NULL);
		philo->time = philo->data->c_time.tv_sec;
		pthread_mutex_unlock(&philo->fork->mutex);
		philo->fork->state = 1;
		pthread_mutex_unlock(&philo->next->fork->mutex);
		philo->next->fork->state = 1;
	}
	else
		printf("%d IL EST MORT !\n", philo->name);
}

void	ft_sleep(t_philo *philo)
{
	int	t_sleep;

	gettimeofday(&philo->data->c_time, NULL);
	t_sleep = philo->data->c_time.tv_sec;
	printf("%d %d is sleeping\n", t_sleep, philo->name);
	usleep(philo->data->time_sleep * 1000);
}

void	*routine(void *philo)
{
	t_philo	*ptr;

	ptr = philo;
	if (ptr->name % 2 == 0)
		usleep(100);
	gettimeofday(&ptr->data->c_time, NULL);
	ptr->start_time = ptr->data->c_time.tv_sec;
	while (ptr->alive == 1)
	{
		ft_thinking(philo);
		ft_eat(ptr);
		ft_sleep(ptr);
	}
	return (NULL);
}
