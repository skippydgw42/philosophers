/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:47:27 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/29 17:15:43 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

t_data	*ft_initdata(char **av)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->nphilo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->alive = 1;
	if (av[5])
		data->nrounds = ft_atoi(av[5]);
	else
		data->nrounds = -1;
	return (data);
}

void	ft_joindata(t_philo *philo, t_data *data)
{
	int		i;
	t_philo	*ptr;

	i = 0;
	ptr = philo;
	while (i < data->nphilo)
	{
		ptr->data = data;
		ptr = ptr->next;
		i++;
	}
}

t_philo	*ft_initnew(int i)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->fork = malloc(sizeof(t_fork));
	if (!new->fork)
		return (NULL);
	new->name = i + 1;
	new->fork->state = 1;
	new->time = 0;
	new->finish_time = 0;
	pthread_mutex_init(&new->fork->mutex, NULL);
	return (new);
}

t_philo	*ft_initphilos(char **av)
{
	int		i;
	t_philo	*ptr;
	t_philo	*new;
	t_philo	*start;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		new = ft_initnew(i);
		if (!new)
			return (NULL);
		if (i == 0)
		{
			ptr = new;
			start = new;
		}
		else
		{
			ptr->next = new;
			ptr = new;
		}
		i++;
	}
	ptr->next = start;
	return (start);
}

int	ft_create(t_philo *philo)
{
	int		i;
	t_philo	*ptr;

	i = 0;
	ptr = philo;
	while (i < philo->data->nphilo)
	{
		if (pthread_create(&ptr->p, NULL, &routine, (void *)ptr) != 0)
			return (ft_stderr("pthread_create Error\n"));
		ptr = ptr->next;
		i++;
	}
	return (1);
}