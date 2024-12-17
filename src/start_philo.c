/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surpetro <surpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:52:25 by surpetro          #+#    #+#             */
/*   Updated: 2024/07/22 19:18:20 by surpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	start_philo(t_info *info)
{
	int	i;

	i = -1;
	get_time();
	while (++i < info->number_of_philosophers)
		pthread_create(&info->philosophers[i].tid, NULL,
			(void *)creat_print, &info->philosophers[i]);
	while (1)
	{
		if (check_dead(info) == -1
			|| amount_of_work(info) == 1)
			break ;
	}
	i = -1;
	while (++i < info->number_of_philosophers)
	{
		pthread_join(info->philosophers[i].tid, NULL);
		pthread_mutex_destroy(&info->forks[i]);
		pthread_mutex_destroy(&info->philosophers[i].last_eat_time_mutex);
		pthread_mutex_destroy(&info->philosophers[i].current_meal_mutexm);
	}
	free(info->philosophers);
	free(info->forks);
	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->is_died_mutex);
}
