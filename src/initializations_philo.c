/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations_philo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:55:16 by surpetro          #+#    #+#             */
/*   Updated: 2024/07/22 21:55:17 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	initializ_philo(int i, t_info *info)
{
	while (i < info->number_of_philosophers)
	{
		info->philosophers[i].id = i;
		info->philosophers[i].current_meal = 0;
		info->philosophers[i].philo_dead = info->is_deat;
		info->philosophers[i].last_eat_time = LLONG_MAX;
		pthread_mutex_init(&info->forks[i], NULL);
		pthread_mutex_init(&info->philosophers[i].last_eat_time_mutex, NULL);
		pthread_mutex_init(&info->philosophers[i].current_meal_mutexm, NULL);
		info->philosophers[i].info = info;
		i++;
	}
}

int	initializations_philo(t_info *info)
{
	int	i;

	i = 0;
	info->philosophers = malloc(sizeof(t_philosophers)
			* (info->number_of_philosophers));
	if (!info->philosophers)
		return (0);
	info->forks = malloc(sizeof(pthread_mutex_t)
			* (info->number_of_philosophers));
	if (!info->forks)
	{
		free(info->philosophers);
		return (0);
	}
	initializ_philo(i, info);
	return (1);
}
