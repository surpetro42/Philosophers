/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:55:08 by surpetro          #+#    #+#             */
/*   Updated: 2024/07/22 21:55:10 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	take_forks(t_philosophers *philo,
		pthread_mutex_t *left_fork, pthread_mutex_t *right_fork)
{
	pthread_mutex_lock(left_fork);
	print_mutex(philo, "has taken a fork\n");
	if (philo->info->number_of_philosophers == 1)
	{
		pthread_mutex_unlock(left_fork);
		return (1);
	}
	pthread_mutex_lock(right_fork);
	print_mutex(philo, "has taken a fork\n");
	print_mutex(philo, "is eating\n");
	usleep_philo(philo, philo->info->time_to_eat);
	pthread_mutex_unlock(left_fork);
	pthread_mutex_unlock(right_fork);
	get_last_eat_time_mutex(philo);
	pthread_mutex_lock(&philo->current_meal_mutexm);
	philo->current_meal++;
	pthread_mutex_unlock(&philo->current_meal_mutexm);
	print_mutex(philo, "is sleeping\n");
	usleep_philo(philo, philo->info->time_to_sleep);
	print_mutex(philo, "is thinking\n");
	return (0);
}
