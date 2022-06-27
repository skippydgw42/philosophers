/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:47:27 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/27 19:31:19 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

void	ft_initstruct(t_data *data, char **av)
{
	data->nphilo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (av[5])
		data->nrounds = ft_atoi(av[5]);
	else
		data->nrounds = -1;
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
	pthread_mutex_init(&new->fork->mutex, NULL);
	return (new);
}

int	ft_initphilos(t_data *data)
{
	int		i;
	t_philo	*new;
	t_philo *start;

	i = 0;
	while (i < data->nphilo)
	{
		new = ft_initnew(i);
		if (!new)
			return (ft_stderr("Malloc Error\n"));
		if (i == 0)
		{
			data->lst = new;
			start = data->lst;
		}
		else
		{
			data->lst->next = new;
			data->lst = new;
		}
		i++;
	}
	data->lst->next = 0;
	data->lst = start;
	return (1);
}

int	ft_create(t_data *data)
{
	t_philo	*ptr;

	ptr = data->lst;
	while (ptr)
	{
		if (pthread_create(&ptr->p, NULL, &routine, (void *)data) != 0)
			return (ft_stderr("pthread_create Error\n"));
		ptr = ptr->next;
	}
	return (1);
}