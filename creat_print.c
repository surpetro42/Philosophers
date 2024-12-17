/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:54:27 by surpetro          #+#    #+#             */
/*   Updated: 2024/07/22 21:54:30 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*creat_print(t_philosophers *philo)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	left_fork = &philo->info->forks[philo->id];
	right_fork = &philo->info->forks[(philo->id + 1)
		% (philo->info->number_of_philosophers)];
	get_last_eat_time_mutex(philo);
	if ((philo->id + 1) % 2 == 0)
		usleep(500);
	while (is_died(philo) != -1)
	{
		if (take_forks(philo, left_fork, right_fork) == 1)
			return (NULL);
	}
	return (NULL);
}
