/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegraeu <mdegraeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:10:05 by mdegraeu          #+#    #+#             */
/*   Updated: 2022/06/27 17:11:29 by mdegraeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclds/philo.h"

void	ft_free_data(t_data *data)
{
	t_philo	*ptr;

	while (data->lst)
	{
		ptr = data->lst;
		data->lst = data->lst->next;
		free(ptr);
	}
	free(data);
}