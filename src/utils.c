/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:54:38 by surpetro          #+#    #+#             */
/*   Updated: 2024/07/22 21:54:41 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	check_dead(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		pthread_mutex_lock(&info->philosophers[i].last_eat_time_mutex);
		if (get_time() - info->philosophers[i].last_eat_time
			>= info->time_to_die)
		{
			pthread_mutex_lock(&info->is_died_mutex);
			info->is_deat = -1;
			pthread_mutex_unlock(&info->is_died_mutex);
			pthread_mutex_lock(&info->philosophers[i].info->print_mutex);
			printf("%lld %d died\n", get_time(), info->philosophers[i].id + 1);
			pthread_mutex_unlock(&info->philosophers[i].info->print_mutex);
			pthread_mutex_unlock(&info->philosophers[i].last_eat_time_mutex);
			return (-1);
		}
		pthread_mutex_unlock(&info->philosophers[i].last_eat_time_mutex);
		i++;
	}
	return (0);
}

int	amount_of_work(t_info *info)
{
	int	amount_food;
	int	i;

	if (info->amount_work < 0)
		return (0);
	amount_food = 0;
	i = 0;
	while (i < info->number_of_philosophers)
	{
		pthread_mutex_lock(&info->philosophers[i].current_meal_mutexm);
		if (info->philosophers[i].current_meal
			>= info->amount_work)
			amount_food++;
		pthread_mutex_unlock(&info->philosophers[i].current_meal_mutexm);
		i++;
	}
	if (amount_food == info->number_of_philosophers)
	{
		pthread_mutex_lock(&info->is_died_mutex);
		info->is_deat = -1;
		pthread_mutex_unlock(&info->is_died_mutex);
		return (1);
	}
	return (0);
}

void	get_last_eat_time_mutex(t_philosophers *philo)
{
	pthread_mutex_lock(&philo->last_eat_time_mutex);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->last_eat_time_mutex);
}

int	is_died(t_philosophers *philo)
{
	int	is_died;

	pthread_mutex_lock(&philo->info->is_died_mutex);
	is_died = philo->info->is_deat;
	pthread_mutex_unlock(&philo->info->is_died_mutex);
	return (is_died);
}

void	print_mutex(t_philosophers *philo, char *str)
{
	pthread_mutex_lock(&philo->info->print_mutex);
	if (is_died(philo) != -1)
		printf("%lld %d %s", get_time(), philo->id + 1, str);
	pthread_mutex_unlock(&philo->info->print_mutex);
}
